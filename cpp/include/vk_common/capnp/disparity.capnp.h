// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: disparity.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>

#ifndef CAPNP_VERSION
#error "CAPNP_VERSION is not defined, is capnp/generated-header-support.h missing?"
#elif CAPNP_VERSION != 1000002
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif

#include "header.capnp.h"
#include "so3.capnp.h"

CAPNP_BEGIN_HEADER

namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(fd2ce832d8ecd12a);
CAPNP_DECLARE_SCHEMA(97a6ede36f3ed26f);
enum class Encoding_97a6ede36f3ed26f: uint16_t {
  DISPARITY8,
  DISPARITY16,
  DEPTH16,
  DEPTH32,
};
CAPNP_DECLARE_ENUM(Encoding, 97a6ede36f3ed26f);

}  // namespace schemas
}  // namespace capnp

namespace vkc {

struct Disparity {
  Disparity() = delete;

  class Reader;
  class Builder;
  class Pipeline;
  typedef ::capnp::schemas::Encoding_97a6ede36f3ed26f Encoding;


  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(fd2ce832d8ecd12a, 5, 4)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class Disparity::Reader {
public:
  typedef Disparity Reads;

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

  inline bool hasHeader() const;
  inline  ::vkc::Header::Reader getHeader() const;

  inline  ::vkc::Disparity::Encoding getEncoding() const;

  inline  ::uint32_t getWidth() const;

  inline  ::uint32_t getHeight() const;

  inline  ::uint32_t getStep() const;

  inline  ::uint8_t getDecimationFactor() const;

  inline bool hasData() const;
  inline  ::capnp::Data::Reader getData() const;

  inline float getFx() const;

  inline float getFy() const;

  inline float getCx() const;

  inline float getCy() const;

  inline float getBaseline() const;

  inline bool hasStreamName() const;
  inline  ::capnp::Text::Reader getStreamName() const;

  inline bool hasPinholeRotation() const;
  inline  ::vkc::So3::Reader getPinholeRotation() const;

  inline  ::uint32_t getMaxDisparity() const;

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

class Disparity::Builder {
public:
  typedef Disparity Builds;

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

  inline bool hasHeader();
  inline  ::vkc::Header::Builder getHeader();
  inline void setHeader( ::vkc::Header::Reader value);
  inline  ::vkc::Header::Builder initHeader();
  inline void adoptHeader(::capnp::Orphan< ::vkc::Header>&& value);
  inline ::capnp::Orphan< ::vkc::Header> disownHeader();

  inline  ::vkc::Disparity::Encoding getEncoding();
  inline void setEncoding( ::vkc::Disparity::Encoding value);

  inline  ::uint32_t getWidth();
  inline void setWidth( ::uint32_t value);

  inline  ::uint32_t getHeight();
  inline void setHeight( ::uint32_t value);

  inline  ::uint32_t getStep();
  inline void setStep( ::uint32_t value);

  inline  ::uint8_t getDecimationFactor();
  inline void setDecimationFactor( ::uint8_t value);

  inline bool hasData();
  inline  ::capnp::Data::Builder getData();
  inline void setData( ::capnp::Data::Reader value);
  inline  ::capnp::Data::Builder initData(unsigned int size);
  inline void adoptData(::capnp::Orphan< ::capnp::Data>&& value);
  inline ::capnp::Orphan< ::capnp::Data> disownData();

  inline float getFx();
  inline void setFx(float value);

  inline float getFy();
  inline void setFy(float value);

  inline float getCx();
  inline void setCx(float value);

  inline float getCy();
  inline void setCy(float value);

  inline float getBaseline();
  inline void setBaseline(float value);

  inline bool hasStreamName();
  inline  ::capnp::Text::Builder getStreamName();
  inline void setStreamName( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initStreamName(unsigned int size);
  inline void adoptStreamName(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownStreamName();

  inline bool hasPinholeRotation();
  inline  ::vkc::So3::Builder getPinholeRotation();
  inline void setPinholeRotation( ::vkc::So3::Reader value);
  inline  ::vkc::So3::Builder initPinholeRotation();
  inline void adoptPinholeRotation(::capnp::Orphan< ::vkc::So3>&& value);
  inline ::capnp::Orphan< ::vkc::So3> disownPinholeRotation();

  inline  ::uint32_t getMaxDisparity();
  inline void setMaxDisparity( ::uint32_t value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class Disparity::Pipeline {
public:
  typedef Disparity Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

  inline  ::vkc::Header::Pipeline getHeader();
  inline  ::vkc::So3::Pipeline getPinholeRotation();
private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

inline bool Disparity::Reader::hasHeader() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool Disparity::Builder::hasHeader() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::Header::Reader Disparity::Reader::getHeader() const {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::vkc::Header::Builder Disparity::Builder::getHeader() {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::Header::Pipeline Disparity::Pipeline::getHeader() {
  return  ::vkc::Header::Pipeline(_typeless.getPointerField(0));
}
#endif  // !CAPNP_LITE
inline void Disparity::Builder::setHeader( ::vkc::Header::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::Header>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::vkc::Header::Builder Disparity::Builder::initHeader() {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void Disparity::Builder::adoptHeader(
    ::capnp::Orphan< ::vkc::Header>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::Header>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::Header> Disparity::Builder::disownHeader() {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline  ::vkc::Disparity::Encoding Disparity::Reader::getEncoding() const {
  return _reader.getDataField< ::vkc::Disparity::Encoding>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline  ::vkc::Disparity::Encoding Disparity::Builder::getEncoding() {
  return _builder.getDataField< ::vkc::Disparity::Encoding>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setEncoding( ::vkc::Disparity::Encoding value) {
  _builder.setDataField< ::vkc::Disparity::Encoding>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline  ::uint32_t Disparity::Reader::getWidth() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Disparity::Builder::getWidth() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setWidth( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline  ::uint32_t Disparity::Reader::getHeight() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Disparity::Builder::getHeight() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setHeight( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS, value);
}

inline  ::uint32_t Disparity::Reader::getStep() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Disparity::Builder::getStep() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setStep( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS, value);
}

inline  ::uint8_t Disparity::Reader::getDecimationFactor() const {
  return _reader.getDataField< ::uint8_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}

inline  ::uint8_t Disparity::Builder::getDecimationFactor() {
  return _builder.getDataField< ::uint8_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setDecimationFactor( ::uint8_t value) {
  _builder.setDataField< ::uint8_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS, value);
}

inline bool Disparity::Reader::hasData() const {
  return !_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline bool Disparity::Builder::hasData() {
  return !_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Data::Reader Disparity::Reader::getData() const {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline  ::capnp::Data::Builder Disparity::Builder::getData() {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline void Disparity::Builder::setData( ::capnp::Data::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Data>::set(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Data::Builder Disparity::Builder::initData(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::init(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), size);
}
inline void Disparity::Builder::adoptData(
    ::capnp::Orphan< ::capnp::Data>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Data>::adopt(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Data> Disparity::Builder::disownData() {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::disown(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}

inline float Disparity::Reader::getFx() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}

inline float Disparity::Builder::getFx() {
  return _builder.getDataField<float>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setFx(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS, value);
}

inline float Disparity::Reader::getFy() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS);
}

inline float Disparity::Builder::getFy() {
  return _builder.getDataField<float>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setFy(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS, value);
}

inline float Disparity::Reader::getCx() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<6>() * ::capnp::ELEMENTS);
}

inline float Disparity::Builder::getCx() {
  return _builder.getDataField<float>(
      ::capnp::bounded<6>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setCx(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<6>() * ::capnp::ELEMENTS, value);
}

inline float Disparity::Reader::getCy() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<7>() * ::capnp::ELEMENTS);
}

inline float Disparity::Builder::getCy() {
  return _builder.getDataField<float>(
      ::capnp::bounded<7>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setCy(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<7>() * ::capnp::ELEMENTS, value);
}

inline float Disparity::Reader::getBaseline() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<8>() * ::capnp::ELEMENTS);
}

inline float Disparity::Builder::getBaseline() {
  return _builder.getDataField<float>(
      ::capnp::bounded<8>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setBaseline(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<8>() * ::capnp::ELEMENTS, value);
}

inline bool Disparity::Reader::hasStreamName() const {
  return !_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline bool Disparity::Builder::hasStreamName() {
  return !_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Disparity::Reader::getStreamName() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Disparity::Builder::getStreamName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline void Disparity::Builder::setStreamName( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Disparity::Builder::initStreamName(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), size);
}
inline void Disparity::Builder::adoptStreamName(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Disparity::Builder::disownStreamName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}

inline bool Disparity::Reader::hasPinholeRotation() const {
  return !_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline bool Disparity::Builder::hasPinholeRotation() {
  return !_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::So3::Reader Disparity::Reader::getPinholeRotation() const {
  return ::capnp::_::PointerHelpers< ::vkc::So3>::get(_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline  ::vkc::So3::Builder Disparity::Builder::getPinholeRotation() {
  return ::capnp::_::PointerHelpers< ::vkc::So3>::get(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::So3::Pipeline Disparity::Pipeline::getPinholeRotation() {
  return  ::vkc::So3::Pipeline(_typeless.getPointerField(3));
}
#endif  // !CAPNP_LITE
inline void Disparity::Builder::setPinholeRotation( ::vkc::So3::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::So3>::set(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), value);
}
inline  ::vkc::So3::Builder Disparity::Builder::initPinholeRotation() {
  return ::capnp::_::PointerHelpers< ::vkc::So3>::init(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline void Disparity::Builder::adoptPinholeRotation(
    ::capnp::Orphan< ::vkc::So3>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::So3>::adopt(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::So3> Disparity::Builder::disownPinholeRotation() {
  return ::capnp::_::PointerHelpers< ::vkc::So3>::disown(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}

inline  ::uint32_t Disparity::Reader::getMaxDisparity() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<9>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Disparity::Builder::getMaxDisparity() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<9>() * ::capnp::ELEMENTS);
}
inline void Disparity::Builder::setMaxDisparity( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<9>() * ::capnp::ELEMENTS, value);
}

}  // namespace

CAPNP_END_HEADER

