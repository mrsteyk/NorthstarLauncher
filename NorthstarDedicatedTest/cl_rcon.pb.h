// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cl_rcon.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_cl_5frcon_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_cl_5frcon_2eproto

#include <limits>
#include <string>

#include <protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <protobuf/port_undef.inc>
#include <protobuf/io/coded_stream.h>
#include <protobuf/arena.h>
#include <protobuf/arenastring.h>
#include <protobuf/generated_message_table_driven.h>
#include <protobuf/generated_message_util.h>
#include <protobuf/metadata_lite.h>
#include <protobuf/message_lite.h>
#include <protobuf/repeated_field.h> // IWYU pragma: export
#include <protobuf/extension_set.h>	 // IWYU pragma: export
#include <protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
#include <protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_cl_5frcon_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal
{
class AnyMetadata;
} // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_cl_5frcon_2eproto
{
	static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[] PROTOBUF_SECTION_VARIABLE(protodesc_cold);
	static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[] PROTOBUF_SECTION_VARIABLE(protodesc_cold);
	static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1] PROTOBUF_SECTION_VARIABLE(protodesc_cold);
	static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
	static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
	static const uint32_t offsets[];
};
namespace cl_rcon
{
class request;
struct requestDefaultTypeInternal;
extern requestDefaultTypeInternal _request_default_instance_;
} // namespace cl_rcon
PROTOBUF_NAMESPACE_OPEN
template <>::cl_rcon::request* Arena::CreateMaybeMessage<::cl_rcon::request>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace cl_rcon
{

enum request_t : int
{
	SERVERDATA_REQUEST_VALUE = 0,
	SERVERDATA_REQUEST_SETVALUE = 1,
	SERVERDATA_REQUEST_EXECCOMMAND = 2,
	SERVERDATA_REQUEST_AUTH = 3,
	SERVERDATA_REQUEST_SEND_CONSOLE_LOG = 4,
	SERVERDATA_REQUEST_SEND_REMOTEBUG = 5,
	request_t_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
	request_t_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool request_t_IsValid(int value);
constexpr request_t request_t_MIN = SERVERDATA_REQUEST_VALUE;
constexpr request_t request_t_MAX = SERVERDATA_REQUEST_SEND_REMOTEBUG;
constexpr int request_t_ARRAYSIZE = request_t_MAX + 1;

const std::string& request_t_Name(request_t value);
template <typename T> inline const std::string& request_t_Name(T enum_t_value)
{
	static_assert(::std::is_same<T, request_t>::value || ::std::is_integral<T>::value, "Incorrect type passed to function request_t_Name.");
	return request_t_Name(static_cast<request_t>(enum_t_value));
}
bool request_t_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name, request_t* value);
// ===================================================================

class request final : public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:cl_rcon.request) */
{
  public:
	inline request() : request(nullptr) {}
	~request() override;
	explicit constexpr request(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

	request(const request& from);
	request(request&& from) noexcept : request() { *this = ::std::move(from); }

	inline request& operator=(const request& from)
	{
		CopyFrom(from);
		return *this;
	}
	inline request& operator=(request&& from) noexcept
	{
		if (this == &from)
			return *this;
		if (GetOwningArena() == from.GetOwningArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
			&& GetOwningArena() != nullptr
#endif // !PROTOBUF_FORCE_COPY_IN_MOVE
		)
		{
			InternalSwap(&from);
		}
		else
		{
			CopyFrom(from);
		}
		return *this;
	}

	static const request& default_instance() { return *internal_default_instance(); }
	static inline const request* internal_default_instance() { return reinterpret_cast<const request*>(&_request_default_instance_); }
	static constexpr int kIndexInFileMessages = 0;

	friend void swap(request& a, request& b) { a.Swap(&b); }
	inline void Swap(request* other)
	{
		if (other == this)
			return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
		if (GetOwningArena() != nullptr && GetOwningArena() == other->GetOwningArena())
		{
#else  // PROTOBUF_FORCE_COPY_IN_SWAP
		if (GetOwningArena() == other->GetOwningArena())
		{
#endif // !PROTOBUF_FORCE_COPY_IN_SWAP
			InternalSwap(other);
		}
		else
		{
			::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
		}
	}
	void UnsafeArenaSwap(request* other)
	{
		if (other == this)
			return;
		GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
		InternalSwap(other);
	}

	// implements Message ----------------------------------------------

	request* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final { return CreateMaybeMessage<request>(arena); }
	void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) final;
	void CopyFrom(const request& from);
	void MergeFrom(const request& from);
	PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
	bool IsInitialized() const final;

	size_t ByteSizeLong() const final;
	const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
	uint8_t* _InternalSerialize(uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
	int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
	void SharedCtor();
	void SharedDtor();
	void SetCachedSize(int size) const;
	void InternalSwap(request* other);

  private:
	friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
	static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() { return "cl_rcon.request"; }

  protected:
	explicit request(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned = false);

  private:
	static void ArenaDtor(void* object);
	inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);

  public:
	std::string GetTypeName() const final;

	// nested types ----------------------------------------------------

	// accessors -------------------------------------------------------

	enum : int
	{
		kRequestBufFieldNumber = 3,
		kRequestValFieldNumber = 4,
		kRequestIDFieldNumber = 1,
		kRequestTypeFieldNumber = 2,
	};
	// optional string requestBuf = 3;
	bool has_requestbuf() const;

  private:
	bool _internal_has_requestbuf() const;

  public:
	void clear_requestbuf();
	const std::string& requestbuf() const;
	template <typename ArgT0 = const std::string&, typename... ArgT> void set_requestbuf(ArgT0&& arg0, ArgT... args);
	std::string* mutable_requestbuf();
	PROTOBUF_NODISCARD std::string* release_requestbuf();
	void set_allocated_requestbuf(std::string* requestbuf);

  private:
	const std::string& _internal_requestbuf() const;
	inline PROTOBUF_ALWAYS_INLINE void _internal_set_requestbuf(const std::string& value);
	std::string* _internal_mutable_requestbuf();

  public:
	// optional string requestVal = 4;
	bool has_requestval() const;

  private:
	bool _internal_has_requestval() const;

  public:
	void clear_requestval();
	const std::string& requestval() const;
	template <typename ArgT0 = const std::string&, typename... ArgT> void set_requestval(ArgT0&& arg0, ArgT... args);
	std::string* mutable_requestval();
	PROTOBUF_NODISCARD std::string* release_requestval();
	void set_allocated_requestval(std::string* requestval);

  private:
	const std::string& _internal_requestval() const;
	inline PROTOBUF_ALWAYS_INLINE void _internal_set_requestval(const std::string& value);
	std::string* _internal_mutable_requestval();

  public:
	// optional int32 requestID = 1;
	bool has_requestid() const;

  private:
	bool _internal_has_requestid() const;

  public:
	void clear_requestid();
	int32_t requestid() const;
	void set_requestid(int32_t value);

  private:
	int32_t _internal_requestid() const;
	void _internal_set_requestid(int32_t value);

  public:
	// optional .cl_rcon.request_t requestType = 2;
	bool has_requesttype() const;

  private:
	bool _internal_has_requesttype() const;

  public:
	void clear_requesttype();
	::cl_rcon::request_t requesttype() const;
	void set_requesttype(::cl_rcon::request_t value);

  private:
	::cl_rcon::request_t _internal_requesttype() const;
	void _internal_set_requesttype(::cl_rcon::request_t value);

  public:
	// @@protoc_insertion_point(class_scope:cl_rcon.request)
  private:
	class _Internal;

	template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
	typedef void InternalArenaConstructable_;
	typedef void DestructorSkippable_;
	::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
	mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
	::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr requestbuf_;
	::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr requestval_;
	int32_t requestid_;
	int requesttype_;
	friend struct ::TableStruct_cl_5frcon_2eproto;
};
// ===================================================================

// ===================================================================

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif // __GNUC__
// request

// optional int32 requestID = 1;
inline bool request::_internal_has_requestid() const
{
	bool value = (_has_bits_[0] & 0x00000004u) != 0;
	return value;
}
inline bool request::has_requestid() const { return _internal_has_requestid(); }
inline void request::clear_requestid()
{
	requestid_ = 0;
	_has_bits_[0] &= ~0x00000004u;
}
inline int32_t request::_internal_requestid() const { return requestid_; }
inline int32_t request::requestid() const
{
	// @@protoc_insertion_point(field_get:cl_rcon.request.requestID)
	return _internal_requestid();
}
inline void request::_internal_set_requestid(int32_t value)
{
	_has_bits_[0] |= 0x00000004u;
	requestid_ = value;
}
inline void request::set_requestid(int32_t value)
{
	_internal_set_requestid(value);
	// @@protoc_insertion_point(field_set:cl_rcon.request.requestID)
}

// optional .cl_rcon.request_t requestType = 2;
inline bool request::_internal_has_requesttype() const
{
	bool value = (_has_bits_[0] & 0x00000008u) != 0;
	return value;
}
inline bool request::has_requesttype() const { return _internal_has_requesttype(); }
inline void request::clear_requesttype()
{
	requesttype_ = 0;
	_has_bits_[0] &= ~0x00000008u;
}
inline ::cl_rcon::request_t request::_internal_requesttype() const { return static_cast<::cl_rcon::request_t>(requesttype_); }
inline ::cl_rcon::request_t request::requesttype() const
{
	// @@protoc_insertion_point(field_get:cl_rcon.request.requestType)
	return _internal_requesttype();
}
inline void request::_internal_set_requesttype(::cl_rcon::request_t value)
{
	_has_bits_[0] |= 0x00000008u;
	requesttype_ = value;
}
inline void request::set_requesttype(::cl_rcon::request_t value)
{
	_internal_set_requesttype(value);
	// @@protoc_insertion_point(field_set:cl_rcon.request.requestType)
}

// optional string requestBuf = 3;
inline bool request::_internal_has_requestbuf() const
{
	bool value = (_has_bits_[0] & 0x00000001u) != 0;
	return value;
}
inline bool request::has_requestbuf() const { return _internal_has_requestbuf(); }
inline void request::clear_requestbuf()
{
	requestbuf_.ClearToEmpty();
	_has_bits_[0] &= ~0x00000001u;
}
inline const std::string& request::requestbuf() const
{
	// @@protoc_insertion_point(field_get:cl_rcon.request.requestBuf)
	return _internal_requestbuf();
}
template <typename ArgT0, typename... ArgT> inline PROTOBUF_ALWAYS_INLINE void request::set_requestbuf(ArgT0&& arg0, ArgT... args)
{
	_has_bits_[0] |= 0x00000001u;
	requestbuf_.Set(
		::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0&&>(arg0), args..., GetArenaForAllocation());
	// @@protoc_insertion_point(field_set:cl_rcon.request.requestBuf)
}
inline std::string* request::mutable_requestbuf()
{
	std::string* _s = _internal_mutable_requestbuf();
	// @@protoc_insertion_point(field_mutable:cl_rcon.request.requestBuf)
	return _s;
}
inline const std::string& request::_internal_requestbuf() const { return requestbuf_.Get(); }
inline void request::_internal_set_requestbuf(const std::string& value)
{
	_has_bits_[0] |= 0x00000001u;
	requestbuf_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* request::_internal_mutable_requestbuf()
{
	_has_bits_[0] |= 0x00000001u;
	return requestbuf_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* request::release_requestbuf()
{
	// @@protoc_insertion_point(field_release:cl_rcon.request.requestBuf)
	if (!_internal_has_requestbuf())
	{
		return nullptr;
	}
	_has_bits_[0] &= ~0x00000001u;
	auto* p = requestbuf_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
	if (requestbuf_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited()))
	{
		requestbuf_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
	}
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
	return p;
}
inline void request::set_allocated_requestbuf(std::string* requestbuf)
{
	if (requestbuf != nullptr)
	{
		_has_bits_[0] |= 0x00000001u;
	}
	else
	{
		_has_bits_[0] &= ~0x00000001u;
	}
	requestbuf_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), requestbuf, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
	if (requestbuf_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited()))
	{
		requestbuf_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
	}
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
	   // @@protoc_insertion_point(field_set_allocated:cl_rcon.request.requestBuf)
}

// optional string requestVal = 4;
inline bool request::_internal_has_requestval() const
{
	bool value = (_has_bits_[0] & 0x00000002u) != 0;
	return value;
}
inline bool request::has_requestval() const { return _internal_has_requestval(); }
inline void request::clear_requestval()
{
	requestval_.ClearToEmpty();
	_has_bits_[0] &= ~0x00000002u;
}
inline const std::string& request::requestval() const
{
	// @@protoc_insertion_point(field_get:cl_rcon.request.requestVal)
	return _internal_requestval();
}
template <typename ArgT0, typename... ArgT> inline PROTOBUF_ALWAYS_INLINE void request::set_requestval(ArgT0&& arg0, ArgT... args)
{
	_has_bits_[0] |= 0x00000002u;
	requestval_.Set(
		::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0&&>(arg0), args..., GetArenaForAllocation());
	// @@protoc_insertion_point(field_set:cl_rcon.request.requestVal)
}
inline std::string* request::mutable_requestval()
{
	std::string* _s = _internal_mutable_requestval();
	// @@protoc_insertion_point(field_mutable:cl_rcon.request.requestVal)
	return _s;
}
inline const std::string& request::_internal_requestval() const { return requestval_.Get(); }
inline void request::_internal_set_requestval(const std::string& value)
{
	_has_bits_[0] |= 0x00000002u;
	requestval_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* request::_internal_mutable_requestval()
{
	_has_bits_[0] |= 0x00000002u;
	return requestval_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* request::release_requestval()
{
	// @@protoc_insertion_point(field_release:cl_rcon.request.requestVal)
	if (!_internal_has_requestval())
	{
		return nullptr;
	}
	_has_bits_[0] &= ~0x00000002u;
	auto* p = requestval_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
	if (requestval_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited()))
	{
		requestval_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
	}
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
	return p;
}
inline void request::set_allocated_requestval(std::string* requestval)
{
	if (requestval != nullptr)
	{
		_has_bits_[0] |= 0x00000002u;
	}
	else
	{
		_has_bits_[0] &= ~0x00000002u;
	}
	requestval_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), requestval, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
	if (requestval_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited()))
	{
		requestval_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
	}
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
	   // @@protoc_insertion_point(field_set_allocated:cl_rcon.request.requestVal)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif // __GNUC__

// @@protoc_insertion_point(namespace_scope)

} // namespace cl_rcon

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum<::cl_rcon::request_t> : ::std::true_type
{
};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <protobuf/port_undef.inc>
#endif // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_cl_5frcon_2eproto