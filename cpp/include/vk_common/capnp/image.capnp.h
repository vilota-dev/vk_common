// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: image.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>

#ifndef CAPNP_VERSION
#error "CAPNP_VERSION is not defined, is capnp/generated-header-support.h missing?"
#elif CAPNP_VERSION != 1000002
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif

#include "cameraintrinsic.capnp.h"
#include "header.capnp.h"
#include "sensorextrinsic.capnp.h"
#include "vector3.capnp.h"

CAPNP_BEGIN_HEADER

namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(8ae1c338e0e10723);
CAPNP_DECLARE_SCHEMA(a12d4c299b56fb7f);
CAPNP_DECLARE_SCHEMA(8c9b6c5b5eb3773c);
enum class Encoding_8c9b6c5b5eb3773c: uint16_t {
  MONO8,
  MONO16,
  YUV420,
  BGR8,
  JPEG,
  PNG,
  H264,
  H265,
};
CAPNP_DECLARE_ENUM(Encoding, 8c9b6c5b5eb3773c);

}  // namespace schemas
}  // namespace capnp

namespace vkc {

struct MotionMeta {
  MotionMeta() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(8ae1c338e0e10723, 1, 2)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct Image {
  Image() = delete;

  class Reader;
  class Builder;
  class Pipeline;
  typedef ::capnp::schemas::Encoding_8c9b6c5b5eb3773c Encoding;


  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(a12d4c299b56fb7f, 4, 6)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class MotionMeta::Reader {
public:
  typedef MotionMeta Reads;

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

  inline bool hasInstantaneousAngularVelocity() const;
  inline  ::vkc::Vector3d::Reader getInstantaneousAngularVelocity() const;

  inline bool hasAverageAngularVelocity() const;
  inline  ::vkc::Vector3d::Reader getAverageAngularVelocity() const;

  inline float getShockLikelihood() const;

  inline float getDeltaUs() const;

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

class MotionMeta::Builder {
public:
  typedef MotionMeta Builds;

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

  inline bool hasInstantaneousAngularVelocity();
  inline  ::vkc::Vector3d::Builder getInstantaneousAngularVelocity();
  inline void setInstantaneousAngularVelocity( ::vkc::Vector3d::Reader value);
  inline  ::vkc::Vector3d::Builder initInstantaneousAngularVelocity();
  inline void adoptInstantaneousAngularVelocity(::capnp::Orphan< ::vkc::Vector3d>&& value);
  inline ::capnp::Orphan< ::vkc::Vector3d> disownInstantaneousAngularVelocity();

  inline bool hasAverageAngularVelocity();
  inline  ::vkc::Vector3d::Builder getAverageAngularVelocity();
  inline void setAverageAngularVelocity( ::vkc::Vector3d::Reader value);
  inline  ::vkc::Vector3d::Builder initAverageAngularVelocity();
  inline void adoptAverageAngularVelocity(::capnp::Orphan< ::vkc::Vector3d>&& value);
  inline ::capnp::Orphan< ::vkc::Vector3d> disownAverageAngularVelocity();

  inline float getShockLikelihood();
  inline void setShockLikelihood(float value);

  inline float getDeltaUs();
  inline void setDeltaUs(float value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class MotionMeta::Pipeline {
public:
  typedef MotionMeta Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

  inline  ::vkc::Vector3d::Pipeline getInstantaneousAngularVelocity();
  inline  ::vkc::Vector3d::Pipeline getAverageAngularVelocity();
private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

class Image::Reader {
public:
  typedef Image Reads;

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

  inline  ::vkc::Image::Encoding getEncoding() const;

  inline  ::uint32_t getWidth() const;

  inline  ::uint32_t getHeight() const;

  inline  ::uint32_t getStep() const;

  inline bool hasData() const;
  inline  ::capnp::Data::Reader getData() const;

  inline  ::uint32_t getExposureUSec() const;

  inline  ::uint32_t getGain() const;

  inline  ::int8_t getSensorIdx() const;

  inline bool hasStreamName() const;
  inline  ::capnp::Text::Reader getStreamName() const;

  inline bool hasIntrinsic() const;
  inline  ::vkc::CameraIntrinsic::Reader getIntrinsic() const;

  inline bool hasExtrinsic() const;
  inline  ::vkc::SensorExtrinsic::Reader getExtrinsic() const;

  inline  ::uint8_t getMipMapLevels() const;

  inline  ::uint8_t getMipMapBrightness() const;

  inline float getMipMapBrightnessChange() const;

  inline bool hasMotionMeta() const;
  inline  ::vkc::MotionMeta::Reader getMotionMeta() const;

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

class Image::Builder {
public:
  typedef Image Builds;

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

  inline  ::vkc::Image::Encoding getEncoding();
  inline void setEncoding( ::vkc::Image::Encoding value);

  inline  ::uint32_t getWidth();
  inline void setWidth( ::uint32_t value);

  inline  ::uint32_t getHeight();
  inline void setHeight( ::uint32_t value);

  inline  ::uint32_t getStep();
  inline void setStep( ::uint32_t value);

  inline bool hasData();
  inline  ::capnp::Data::Builder getData();
  inline void setData( ::capnp::Data::Reader value);
  inline  ::capnp::Data::Builder initData(unsigned int size);
  inline void adoptData(::capnp::Orphan< ::capnp::Data>&& value);
  inline ::capnp::Orphan< ::capnp::Data> disownData();

  inline  ::uint32_t getExposureUSec();
  inline void setExposureUSec( ::uint32_t value);

  inline  ::uint32_t getGain();
  inline void setGain( ::uint32_t value);

  inline  ::int8_t getSensorIdx();
  inline void setSensorIdx( ::int8_t value);

  inline bool hasStreamName();
  inline  ::capnp::Text::Builder getStreamName();
  inline void setStreamName( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initStreamName(unsigned int size);
  inline void adoptStreamName(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownStreamName();

  inline bool hasIntrinsic();
  inline  ::vkc::CameraIntrinsic::Builder getIntrinsic();
  inline void setIntrinsic( ::vkc::CameraIntrinsic::Reader value);
  inline  ::vkc::CameraIntrinsic::Builder initIntrinsic();
  inline void adoptIntrinsic(::capnp::Orphan< ::vkc::CameraIntrinsic>&& value);
  inline ::capnp::Orphan< ::vkc::CameraIntrinsic> disownIntrinsic();

  inline bool hasExtrinsic();
  inline  ::vkc::SensorExtrinsic::Builder getExtrinsic();
  inline void setExtrinsic( ::vkc::SensorExtrinsic::Reader value);
  inline  ::vkc::SensorExtrinsic::Builder initExtrinsic();
  inline void adoptExtrinsic(::capnp::Orphan< ::vkc::SensorExtrinsic>&& value);
  inline ::capnp::Orphan< ::vkc::SensorExtrinsic> disownExtrinsic();

  inline  ::uint8_t getMipMapLevels();
  inline void setMipMapLevels( ::uint8_t value);

  inline  ::uint8_t getMipMapBrightness();
  inline void setMipMapBrightness( ::uint8_t value);

  inline float getMipMapBrightnessChange();
  inline void setMipMapBrightnessChange(float value);

  inline bool hasMotionMeta();
  inline  ::vkc::MotionMeta::Builder getMotionMeta();
  inline void setMotionMeta( ::vkc::MotionMeta::Reader value);
  inline  ::vkc::MotionMeta::Builder initMotionMeta();
  inline void adoptMotionMeta(::capnp::Orphan< ::vkc::MotionMeta>&& value);
  inline ::capnp::Orphan< ::vkc::MotionMeta> disownMotionMeta();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class Image::Pipeline {
public:
  typedef Image Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

  inline  ::vkc::Header::Pipeline getHeader();
  inline  ::vkc::CameraIntrinsic::Pipeline getIntrinsic();
  inline  ::vkc::SensorExtrinsic::Pipeline getExtrinsic();
  inline  ::vkc::MotionMeta::Pipeline getMotionMeta();
private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

inline bool MotionMeta::Reader::hasInstantaneousAngularVelocity() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool MotionMeta::Builder::hasInstantaneousAngularVelocity() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::Vector3d::Reader MotionMeta::Reader::getInstantaneousAngularVelocity() const {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::vkc::Vector3d::Builder MotionMeta::Builder::getInstantaneousAngularVelocity() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::Vector3d::Pipeline MotionMeta::Pipeline::getInstantaneousAngularVelocity() {
  return  ::vkc::Vector3d::Pipeline(_typeless.getPointerField(0));
}
#endif  // !CAPNP_LITE
inline void MotionMeta::Builder::setInstantaneousAngularVelocity( ::vkc::Vector3d::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::Vector3d>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::vkc::Vector3d::Builder MotionMeta::Builder::initInstantaneousAngularVelocity() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void MotionMeta::Builder::adoptInstantaneousAngularVelocity(
    ::capnp::Orphan< ::vkc::Vector3d>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::Vector3d>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::Vector3d> MotionMeta::Builder::disownInstantaneousAngularVelocity() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline bool MotionMeta::Reader::hasAverageAngularVelocity() const {
  return !_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline bool MotionMeta::Builder::hasAverageAngularVelocity() {
  return !_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::Vector3d::Reader MotionMeta::Reader::getAverageAngularVelocity() const {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::get(_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline  ::vkc::Vector3d::Builder MotionMeta::Builder::getAverageAngularVelocity() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::get(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::Vector3d::Pipeline MotionMeta::Pipeline::getAverageAngularVelocity() {
  return  ::vkc::Vector3d::Pipeline(_typeless.getPointerField(1));
}
#endif  // !CAPNP_LITE
inline void MotionMeta::Builder::setAverageAngularVelocity( ::vkc::Vector3d::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::Vector3d>::set(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), value);
}
inline  ::vkc::Vector3d::Builder MotionMeta::Builder::initAverageAngularVelocity() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::init(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline void MotionMeta::Builder::adoptAverageAngularVelocity(
    ::capnp::Orphan< ::vkc::Vector3d>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::Vector3d>::adopt(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::Vector3d> MotionMeta::Builder::disownAverageAngularVelocity() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::disown(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}

inline float MotionMeta::Reader::getShockLikelihood() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline float MotionMeta::Builder::getShockLikelihood() {
  return _builder.getDataField<float>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void MotionMeta::Builder::setShockLikelihood(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline float MotionMeta::Reader::getDeltaUs() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline float MotionMeta::Builder::getDeltaUs() {
  return _builder.getDataField<float>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void MotionMeta::Builder::setDeltaUs(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline bool Image::Reader::hasHeader() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool Image::Builder::hasHeader() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::Header::Reader Image::Reader::getHeader() const {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::vkc::Header::Builder Image::Builder::getHeader() {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::Header::Pipeline Image::Pipeline::getHeader() {
  return  ::vkc::Header::Pipeline(_typeless.getPointerField(0));
}
#endif  // !CAPNP_LITE
inline void Image::Builder::setHeader( ::vkc::Header::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::Header>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::vkc::Header::Builder Image::Builder::initHeader() {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void Image::Builder::adoptHeader(
    ::capnp::Orphan< ::vkc::Header>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::Header>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::Header> Image::Builder::disownHeader() {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline  ::vkc::Image::Encoding Image::Reader::getEncoding() const {
  return _reader.getDataField< ::vkc::Image::Encoding>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline  ::vkc::Image::Encoding Image::Builder::getEncoding() {
  return _builder.getDataField< ::vkc::Image::Encoding>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setEncoding( ::vkc::Image::Encoding value) {
  _builder.setDataField< ::vkc::Image::Encoding>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline  ::uint32_t Image::Reader::getWidth() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Image::Builder::getWidth() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setWidth( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline  ::uint32_t Image::Reader::getHeight() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Image::Builder::getHeight() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setHeight( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS, value);
}

inline  ::uint32_t Image::Reader::getStep() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Image::Builder::getStep() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setStep( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS, value);
}

inline bool Image::Reader::hasData() const {
  return !_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline bool Image::Builder::hasData() {
  return !_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Data::Reader Image::Reader::getData() const {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline  ::capnp::Data::Builder Image::Builder::getData() {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline void Image::Builder::setData( ::capnp::Data::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Data>::set(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Data::Builder Image::Builder::initData(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::init(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), size);
}
inline void Image::Builder::adoptData(
    ::capnp::Orphan< ::capnp::Data>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Data>::adopt(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Data> Image::Builder::disownData() {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::disown(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}

inline  ::uint32_t Image::Reader::getExposureUSec() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Image::Builder::getExposureUSec() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setExposureUSec( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<4>() * ::capnp::ELEMENTS, value);
}

inline  ::uint32_t Image::Reader::getGain() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Image::Builder::getGain() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setGain( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<5>() * ::capnp::ELEMENTS, value);
}

inline  ::int8_t Image::Reader::getSensorIdx() const {
  return _reader.getDataField< ::int8_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}

inline  ::int8_t Image::Builder::getSensorIdx() {
  return _builder.getDataField< ::int8_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setSensorIdx( ::int8_t value) {
  _builder.setDataField< ::int8_t>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS, value);
}

inline bool Image::Reader::hasStreamName() const {
  return !_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline bool Image::Builder::hasStreamName() {
  return !_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Image::Reader::getStreamName() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Image::Builder::getStreamName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline void Image::Builder::setStreamName( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Image::Builder::initStreamName(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), size);
}
inline void Image::Builder::adoptStreamName(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Image::Builder::disownStreamName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}

inline bool Image::Reader::hasIntrinsic() const {
  return !_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline bool Image::Builder::hasIntrinsic() {
  return !_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::CameraIntrinsic::Reader Image::Reader::getIntrinsic() const {
  return ::capnp::_::PointerHelpers< ::vkc::CameraIntrinsic>::get(_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline  ::vkc::CameraIntrinsic::Builder Image::Builder::getIntrinsic() {
  return ::capnp::_::PointerHelpers< ::vkc::CameraIntrinsic>::get(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::CameraIntrinsic::Pipeline Image::Pipeline::getIntrinsic() {
  return  ::vkc::CameraIntrinsic::Pipeline(_typeless.getPointerField(3));
}
#endif  // !CAPNP_LITE
inline void Image::Builder::setIntrinsic( ::vkc::CameraIntrinsic::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::CameraIntrinsic>::set(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), value);
}
inline  ::vkc::CameraIntrinsic::Builder Image::Builder::initIntrinsic() {
  return ::capnp::_::PointerHelpers< ::vkc::CameraIntrinsic>::init(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline void Image::Builder::adoptIntrinsic(
    ::capnp::Orphan< ::vkc::CameraIntrinsic>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::CameraIntrinsic>::adopt(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::CameraIntrinsic> Image::Builder::disownIntrinsic() {
  return ::capnp::_::PointerHelpers< ::vkc::CameraIntrinsic>::disown(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}

inline bool Image::Reader::hasExtrinsic() const {
  return !_reader.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS).isNull();
}
inline bool Image::Builder::hasExtrinsic() {
  return !_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::SensorExtrinsic::Reader Image::Reader::getExtrinsic() const {
  return ::capnp::_::PointerHelpers< ::vkc::SensorExtrinsic>::get(_reader.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}
inline  ::vkc::SensorExtrinsic::Builder Image::Builder::getExtrinsic() {
  return ::capnp::_::PointerHelpers< ::vkc::SensorExtrinsic>::get(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::SensorExtrinsic::Pipeline Image::Pipeline::getExtrinsic() {
  return  ::vkc::SensorExtrinsic::Pipeline(_typeless.getPointerField(4));
}
#endif  // !CAPNP_LITE
inline void Image::Builder::setExtrinsic( ::vkc::SensorExtrinsic::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::SensorExtrinsic>::set(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS), value);
}
inline  ::vkc::SensorExtrinsic::Builder Image::Builder::initExtrinsic() {
  return ::capnp::_::PointerHelpers< ::vkc::SensorExtrinsic>::init(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}
inline void Image::Builder::adoptExtrinsic(
    ::capnp::Orphan< ::vkc::SensorExtrinsic>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::SensorExtrinsic>::adopt(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::SensorExtrinsic> Image::Builder::disownExtrinsic() {
  return ::capnp::_::PointerHelpers< ::vkc::SensorExtrinsic>::disown(_builder.getPointerField(
      ::capnp::bounded<4>() * ::capnp::POINTERS));
}

inline  ::uint8_t Image::Reader::getMipMapLevels() const {
  return _reader.getDataField< ::uint8_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}

inline  ::uint8_t Image::Builder::getMipMapLevels() {
  return _builder.getDataField< ::uint8_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setMipMapLevels( ::uint8_t value) {
  _builder.setDataField< ::uint8_t>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS, value);
}

inline  ::uint8_t Image::Reader::getMipMapBrightness() const {
  return _reader.getDataField< ::uint8_t>(
      ::capnp::bounded<24>() * ::capnp::ELEMENTS);
}

inline  ::uint8_t Image::Builder::getMipMapBrightness() {
  return _builder.getDataField< ::uint8_t>(
      ::capnp::bounded<24>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setMipMapBrightness( ::uint8_t value) {
  _builder.setDataField< ::uint8_t>(
      ::capnp::bounded<24>() * ::capnp::ELEMENTS, value);
}

inline float Image::Reader::getMipMapBrightnessChange() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<7>() * ::capnp::ELEMENTS);
}

inline float Image::Builder::getMipMapBrightnessChange() {
  return _builder.getDataField<float>(
      ::capnp::bounded<7>() * ::capnp::ELEMENTS);
}
inline void Image::Builder::setMipMapBrightnessChange(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<7>() * ::capnp::ELEMENTS, value);
}

inline bool Image::Reader::hasMotionMeta() const {
  return !_reader.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS).isNull();
}
inline bool Image::Builder::hasMotionMeta() {
  return !_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::MotionMeta::Reader Image::Reader::getMotionMeta() const {
  return ::capnp::_::PointerHelpers< ::vkc::MotionMeta>::get(_reader.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS));
}
inline  ::vkc::MotionMeta::Builder Image::Builder::getMotionMeta() {
  return ::capnp::_::PointerHelpers< ::vkc::MotionMeta>::get(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::MotionMeta::Pipeline Image::Pipeline::getMotionMeta() {
  return  ::vkc::MotionMeta::Pipeline(_typeless.getPointerField(5));
}
#endif  // !CAPNP_LITE
inline void Image::Builder::setMotionMeta( ::vkc::MotionMeta::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::MotionMeta>::set(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS), value);
}
inline  ::vkc::MotionMeta::Builder Image::Builder::initMotionMeta() {
  return ::capnp::_::PointerHelpers< ::vkc::MotionMeta>::init(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS));
}
inline void Image::Builder::adoptMotionMeta(
    ::capnp::Orphan< ::vkc::MotionMeta>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::MotionMeta>::adopt(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::MotionMeta> Image::Builder::disownMotionMeta() {
  return ::capnp::_::PointerHelpers< ::vkc::MotionMeta>::disown(_builder.getPointerField(
      ::capnp::bounded<5>() * ::capnp::POINTERS));
}

}  // namespace

CAPNP_END_HEADER

