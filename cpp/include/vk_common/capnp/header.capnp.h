// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: header.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>

#ifndef CAPNP_VERSION
#error "CAPNP_VERSION is not defined, is capnp/generated-header-support.h missing?"
#elif CAPNP_VERSION != 1000002
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif


CAPNP_BEGIN_HEADER

namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(89f0c142cdcfc226);
CAPNP_DECLARE_SCHEMA(9bbf108037e89501);
enum class ClockDomain_9bbf108037e89501: uint16_t {
  MONOTONIC,
  REALTIME,
};
CAPNP_DECLARE_ENUM(ClockDomain, 9bbf108037e89501);

}  // namespace schemas
}  // namespace capnp

namespace vkc {

struct Header {
  Header() = delete;

  class Reader;
  class Builder;
  class Pipeline;
  typedef ::capnp::schemas::ClockDomain_9bbf108037e89501 ClockDomain;


  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(89f0c142cdcfc226, 5, 1)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class Header::Reader {
public:
  typedef Header Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline ::capnp::MessageSize totalSize() const {
    return _reader.totalSize().asPublic();
  }

#if !CAPNP_LITE
  inline ::kj::StringTree toString() const {
    return ::capnp::_::structString(_reader, *_capnpPrivate::brand());
  }
#endif  // !CAPNP_LITE

  inline  ::uint64_t getSeq() const;

  inline  ::uint64_t getStamp() const;

  inline bool hasFrameId() const;
  inline  ::capnp::Text::Reader getFrameId() const;

  inline  ::vkc::Header::ClockDomain getClockDomain() const;

  inline  ::uint64_t getLatencyDevice() const;

  inline  ::uint64_t getLatencyHost() const;

private:
  ::capnp::_::StructReader _reader;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::List;
  friend class ::capnp::MessageBuilder;
  friend class ::capnp::Orphanage;
};

class Header::Builder {
public:
  typedef Header Builds;

  Builder() = delete;  // Deleted to discourage incorrect usage.
                       // You can explicitly initialize to nullptr instead.
  inline Builder(decltype(nullptr)) {}
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline ::capnp::MessageSize totalSize() const { return asReader().totalSize(); }
#if !CAPNP_LITE
  inline ::kj::StringTree toString() const { return asReader().toString(); }
#endif  // !CAPNP_LITE

  inline  ::uint64_t getSeq();
  inline void setSeq( ::uint64_t value);

  inline  ::uint64_t getStamp();
  inline void setStamp( ::uint64_t value);

  inline bool hasFrameId();
  inline  ::capnp::Text::Builder getFrameId();
  inline void setFrameId( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initFrameId(unsigned int size);
  inline void adoptFrameId(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownFrameId();

  inline  ::vkc::Header::ClockDomain getClockDomain();
  inline void setClockDomain( ::vkc::Header::ClockDomain value);

  inline  ::uint64_t getLatencyDevice();
  inline void setLatencyDevice( ::uint64_t value);

  inline  ::uint64_t getLatencyHost();
  inline void setLatencyHost( ::uint64_t value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class Header::Pipeline {
public:
  typedef Header Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

inline  ::uint64_t Header::Reader::getSeq() const {
  return _reader.getDataField< ::uint64_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline  ::uint64_t Header::Builder::getSeq() {
  return _builder.getDataField< ::uint64_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void Header::Builder::setSeq( ::uint64_t value) {
  _builder.setDataField< ::uint64_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline  ::uint64_t Header::Reader::getStamp() const {
  return _reader.getDataField< ::uint64_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline  ::uint64_t Header::Builder::getStamp() {
  return _builder.getDataField< ::uint64_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void Header::Builder::setStamp( ::uint64_t value) {
  _builder.setDataField< ::uint64_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline bool Header::Reader::hasFrameId() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool Header::Builder::hasFrameId() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Header::Reader::getFrameId() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Header::Builder::getFrameId() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void Header::Builder::setFrameId( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Header::Builder::initFrameId(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), size);
}
inline void Header::Builder::adoptFrameId(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Header::Builder::disownFrameId() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline  ::vkc::Header::ClockDomain Header::Reader::getClockDomain() const {
  return _reader.getDataField< ::vkc::Header::ClockDomain>(
      ::capnp::bounded<8>() * ::capnp::ELEMENTS);
}

inline  ::vkc::Header::ClockDomain Header::Builder::getClockDomain() {
  return _builder.getDataField< ::vkc::Header::ClockDomain>(
      ::capnp::bounded<8>() * ::capnp::ELEMENTS);
}
inline void Header::Builder::setClockDomain( ::vkc::Header::ClockDomain value) {
  _builder.setDataField< ::vkc::Header::ClockDomain>(
      ::capnp::bounded<8>() * ::capnp::ELEMENTS, value);
}

inline  ::uint64_t Header::Reader::getLatencyDevice() const {
  return _reader.getDataField< ::uint64_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}

inline  ::uint64_t Header::Builder::getLatencyDevice() {
  return _builder.getDataField< ::uint64_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}
inline void Header::Builder::setLatencyDevice( ::uint64_t value) {
  _builder.setDataField< ::uint64_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS, value);
}

inline  ::uint64_t Header::Reader::getLatencyHost() const {
  return _reader.getDataField< ::uint64_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}

inline  ::uint64_t Header::Builder::getLatencyHost() {
  return _builder.getDataField< ::uint64_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}
inline void Header::Builder::setLatencyHost( ::uint64_t value) {
  _builder.setDataField< ::uint64_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS, value);
}

}  // namespace

CAPNP_END_HEADER

