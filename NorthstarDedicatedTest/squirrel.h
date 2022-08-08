#include <../modmanager.h>
#pragma once

void InitialiseClientSquirrel(HMODULE baseAddress);
void InitialiseServerSquirrel(HMODULE baseAddress);

// stolen from ttf2sdk: sqvm types
typedef float SQFloat;
typedef long SQInteger;
typedef unsigned long SQUnsignedInteger;
typedef char SQChar;

typedef SQUnsignedInteger SQBool;
typedef SQInteger SQRESULT;

const SQRESULT SQRESULT_ERROR = -1;
const SQRESULT SQRESULT_NULL = 0;
const SQRESULT SQRESULT_NOTNULL = 1;

typedef SQInteger (*SQFunction)(void* sqvm);

enum SQReturnTypeEnum
{
	SqReturnFloat = 0x1,
	SqReturnVector = 0x3,
	SqReturnInteger = 0x5,
	SqReturnBoolean = 0x6,
	SqReturnEntity = 0xD,
	SqReturnString = 0x21,
	SqReturnDefault = 0x20,
	SqReturnArrays = 0x25,
	SqReturnAsset = 0x28,
	SqReturnTable = 0x26,
};

struct CompileBufferState
{
	const SQChar* buffer;
	const SQChar* bufferPlusLength;
	const SQChar* bufferAgain;

	CompileBufferState(const std::string& code)
	{
		buffer = code.c_str();
		bufferPlusLength = code.c_str() + code.size();
		bufferAgain = code.c_str();
	}
};

struct SQFuncRegistration
{
	const char* squirrelFuncName;
	const char* cppFuncName;
	const char* helpText;
	const char* returnTypeString;
	const char* argTypes;
	__int32 unknown1;
	__int32 devLevel;
	const char* shortNameMaybe;
	__int32 unknown2;
	SQReturnTypeEnum returnTypeEnum;
	__int32* externalBufferPointer;
	__int64 externalBufferSize;
	__int64 unknown3;
	__int64 unknown4;
	void* funcPtr;

	SQFuncRegistration()
	{
		memset(this, 0, sizeof(SQFuncRegistration));
		this->returnTypeEnum = SqReturnDefault;
	}
};

SQReturnTypeEnum GetReturnTypeEnumFromString(const char* returnTypeString);

// core sqvm funcs
typedef SQRESULT (*sq_compilebufferType)(void* sqvm, CompileBufferState* compileBuffer, const char* file, int a1, ScriptContext a2);
extern sq_compilebufferType ClientSq_compilebuffer;
extern sq_compilebufferType ServerSq_compilebuffer;

typedef void (*sq_pushroottableType)(void* sqvm);
extern sq_pushroottableType ClientSq_pushroottable;
extern sq_pushroottableType ServerSq_pushroottable;

typedef SQRESULT (*sq_callType)(void* sqvm, SQInteger s1, SQBool a2, SQBool a3);
extern sq_callType ClientSq_call;
extern sq_callType ServerSq_call;

typedef int64_t (*RegisterSquirrelFuncType)(void* sqvm, SQFuncRegistration* funcReg, char unknown);
extern RegisterSquirrelFuncType ClientRegisterSquirrelFunc;
extern RegisterSquirrelFuncType ServerRegisterSquirrelFunc;

// sq stack array funcs
typedef void (*sq_newarrayType)(void* sqvm, SQInteger stackpos);
extern sq_newarrayType ClientSq_newarray;
extern sq_newarrayType ServerSq_newarray;

typedef SQRESULT (*sq_arrayappendType)(void* sqvm, SQInteger stackpos);
extern sq_arrayappendType ClientSq_arrayappend;
extern sq_arrayappendType ServerSq_arrayappend;

// sq stack push funcs
typedef void (*sq_pushstringType)(void* sqvm, const SQChar* str, SQInteger stackpos);
extern sq_pushstringType ClientSq_pushstring;
extern sq_pushstringType ServerSq_pushstring;

// weird how these don't take a stackpos arg?
typedef void (*sq_pushintegerType)(void* sqvm, SQInteger i);
extern sq_pushintegerType ClientSq_pushinteger;
extern sq_pushintegerType ServerSq_pushinteger;

typedef void (*sq_pushfloatType)(void* sqvm, SQFloat f);
extern sq_pushfloatType ClientSq_pushfloat;
extern sq_pushfloatType ServerSq_pushfloat;

typedef void (*sq_pushboolType)(void* sqvm, SQBool b);
extern sq_pushboolType ClientSq_pushbool;
extern sq_pushboolType ServerSq_pushbool;

typedef SQInteger (*sq_pusherrorType)(void* sqvm, const SQChar* error);
extern sq_pusherrorType ClientSq_pusherror;
extern sq_pusherrorType ServerSq_pusherror;

typedef void (*sq_defconst)(void* sqvm, const SQChar* name, int value);
extern sq_defconst ClientSq_defconst;
extern sq_defconst ServerSq_defconst;

typedef SQRESULT (*sq_pushAssetType)(void* sqvm, const SQChar* assetName, SQInteger nameLength);
extern sq_pushAssetType ServerSq_pushAsset;
extern sq_pushAssetType ClientSq_pushAsset;

// sq stack get funcs
typedef const SQChar* (*sq_getstringType)(void* sqvm, SQInteger stackpos);
extern sq_getstringType ClientSq_getstring;
extern sq_getstringType ServerSq_getstring;

typedef SQInteger (*sq_getintegerType)(void* sqvm, SQInteger stackpos);
extern sq_getintegerType ClientSq_getinteger;
extern sq_getintegerType ServerSq_getinteger;

typedef SQFloat (*sq_getfloatType)(void*, SQInteger stackpos);
extern sq_getfloatType ClientSq_getfloat;
extern sq_getfloatType ServerSq_getfloat;

typedef SQBool (*sq_getboolType)(void*, SQInteger stackpos);
extern sq_getboolType ClientSq_getbool;
extern sq_getboolType ServerSq_getbool;

typedef SQRESULT (*sq_getType)(void* sqvm, SQInteger idx);
extern sq_getType ServerSq_sq_get;
extern sq_getType ClientSq_sq_get;

template <ScriptContext context> class SquirrelManager
{
  private:
	std::vector<SQFuncRegistration*> m_funcRegistrations;

  public:
	void* sqvm;
	void* sqvm2;

  public:
	SquirrelManager() : sqvm(nullptr) {}

	void VMCreated(void* newSqvm)
	{
		sqvm = newSqvm;
		sqvm2 = *((void**)((char*)sqvm + 8)); // honestly not 100% sure on what this is, but alot of functions take it

		for (SQFuncRegistration* funcReg : m_funcRegistrations)
		{
			spdlog::info("Registering {} function {}", GetContextName(context), funcReg->squirrelFuncName);

			if (context == ScriptContext::CLIENT || context == ScriptContext::UI)
				ClientRegisterSquirrelFunc(sqvm, funcReg, 1);
			else
				ServerRegisterSquirrelFunc(sqvm, funcReg, 1);
		}
		for (auto& pair : g_ModManager->DependencyConstants)
		{
			bool wasFound = false;
			for (Mod& dependency : g_ModManager->m_loadedMods)
			{
				if (dependency.Name == pair.second)
				{
					wasFound = dependency.Enabled;
					break;
				}
			}
			if (context == ScriptContext::SERVER)
				ServerSq_defconst(sqvm, pair.first.c_str(), wasFound);
			else
				ClientSq_defconst(sqvm, pair.first.c_str(), wasFound);
		}
	}

	void VMDestroyed()
	{
		sqvm = nullptr;
	}

	void ExecuteCode(const char* code)
	{
		// ttf2sdk checks ThreadIsInMainThread here, might be good to do that? doesn't seem like an issue rn tho

		if (!sqvm)
		{
			spdlog::error("Cannot execute code, {} squirrel vm is not initialised", GetContextName(context));
			return;
		}

		spdlog::info("Executing {} script code {} ", GetContextName(context), code);

		std::string strCode(code);
		CompileBufferState bufferState = CompileBufferState(strCode);

		SQRESULT compileResult;
		if (context == ScriptContext::CLIENT || context == ScriptContext::UI)
			compileResult = ClientSq_compilebuffer(sqvm2, &bufferState, "console", -1, context);
		else if (context == ScriptContext::SERVER)
			compileResult = ServerSq_compilebuffer(sqvm2, &bufferState, "console", -1, context);

		spdlog::info("sq_compilebuffer returned {}", compileResult);
		if (compileResult >= 0)
		{
			if (context == ScriptContext::CLIENT || context == ScriptContext::UI)
			{
				ClientSq_pushroottable(sqvm2);
				SQRESULT callResult = ClientSq_call(sqvm2, 1, false, false);
				spdlog::info("sq_call returned {}", callResult);
			}
			else if (context == ScriptContext::SERVER)
			{
				ServerSq_pushroottable(sqvm2);
				SQRESULT callResult = ServerSq_call(sqvm2, 1, false, false);
				spdlog::info("sq_call returned {}", callResult);
			}
		}
	}

	int setupfunc(const char* funcname)
	{
		int result = -2;
		if (context == ScriptContext::CLIENT || context == ScriptContext::UI)
		{
			ClientSq_pushroottable(sqvm2);
			ClientSq_pushstring(sqvm2, funcname, -1);
			result = ClientSq_sq_get(sqvm2, -2);
			if (result != SQRESULT_ERROR)
			{
				ClientSq_pushroottable(sqvm2);
			}
		}
		else if (context == ScriptContext::SERVER)
		{
			ServerSq_pushroottable(sqvm2);
			ServerSq_pushstring(sqvm2, funcname, -1);
			result = ServerSq_sq_get(sqvm2, -2);
			if (result != SQRESULT_ERROR)
			{
				ServerSq_pushroottable(sqvm2);
			}
		}
		return result;
	}

	void pusharg(int arg)
	{
		if (context == ScriptContext::CLIENT || context == ScriptContext::UI)
			ClientSq_pushinteger(sqvm2, arg);
		else if (context == ScriptContext::SERVER)
			ServerSq_pushinteger(sqvm2, arg);
	}
	void pusharg(const char* arg)
	{
		if (context == ScriptContext::CLIENT || context == ScriptContext::UI)
			ClientSq_pushstring(sqvm2, arg, -1);
		else if (context == ScriptContext::SERVER)
			ServerSq_pushstring(sqvm2, arg, -1);
	}
	void pusharg(float arg)
	{
		if (context == ScriptContext::CLIENT || context == ScriptContext::UI)
			ClientSq_pushfloat(sqvm2, arg);
		else if (context == ScriptContext::SERVER)
			ServerSq_pushfloat(sqvm2, arg);
	}
	void pusharg(bool arg)
	{
		if (context == ScriptContext::CLIENT || context == ScriptContext::UI)
			ClientSq_pushbool(sqvm2, arg);
		else if (context == ScriptContext::SERVER)
			ServerSq_pushbool(sqvm2, arg);
	}

	int call(int args)
	{
		int result = -2;
		if (context == ScriptContext::CLIENT || context == ScriptContext::UI)
			result = ClientSq_call(sqvm2, args + 1, false, false);
		else if (context == ScriptContext::SERVER)
			result = ServerSq_call(sqvm2, args + 1, false, false);

		return result;
	}

	void AddFuncRegistration(std::string returnType, std::string name, std::string argTypes, std::string helpText, SQFunction func)
	{
		SQFuncRegistration* reg = new SQFuncRegistration;

		reg->squirrelFuncName = new char[name.size() + 1];
		strcpy((char*)reg->squirrelFuncName, name.c_str());
		reg->cppFuncName = reg->squirrelFuncName;

		reg->helpText = new char[helpText.size() + 1];
		strcpy((char*)reg->helpText, helpText.c_str());

		reg->returnTypeString = new char[returnType.size() + 1];
		strcpy((char*)reg->returnTypeString, returnType.c_str());
		reg->returnTypeEnum = GetReturnTypeEnumFromString(returnType.c_str());

		reg->argTypes = new char[argTypes.size() + 1];
		strcpy((char*)reg->argTypes, argTypes.c_str());

		reg->funcPtr = reinterpret_cast<void*>(func);

		m_funcRegistrations.push_back(reg);
	}
};

extern SquirrelManager<ScriptContext::CLIENT>* g_ClientSquirrelManager;
extern SquirrelManager<ScriptContext::SERVER>* g_ServerSquirrelManager;
extern SquirrelManager<ScriptContext::UI>* g_UISquirrelManager;
