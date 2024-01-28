// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: pointcloud.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>

#ifndef CAPNP_VERSION
#error "CAPNP_VERSION is not defined, is capnp/generated-header-support.h missing?"
#elif CAPNP_VERSION != 1000002
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif

#include "header.capnp.h"
#include "odometry3d.capnp.h"

CAPNP_BEGIN_HEADER

namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(d425bbeea1f9125a);
CAPNP_DECLARE_SCHEMA(864d2a7d4d83734e);
enum class NumericType_864d2a7d4d83734e: uint16_t {
  FLOAT32,
  FLOAT64,
  INT8,
  INT16,
  INT32,
  INT64,
  UINT8,
  UINT16,
  UINT32,
  UINT64,
};
CAPNP_DECLARE_ENUM(NumericType, 864d2a7d4d83734e);
CAPNP_DECLARE_SCHEMA(fb940bb02480e1cc);

}  // namespace schemas
}  // namespace capnp

namespace vkc {

struct Field {
  Field() = delete;

  class Reader;
  class Builder;
  class Pipeline;
  typedef ::capnp::schemas::NumericType_864d2a7d4d83734e NumericType;


  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(d425bbeea1f9125a, 1, 1)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct PointCloud {
  PointCloud() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(fb940bb02480e1cc, 1, 4)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class Field::Reader {
public:
  typedef Field Reads;

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

  inline bool hasName() const;
  inline  ::capnp::Text::Reader getName() const;

  inline  ::uint32_t getOffset() const;

  inline  ::vkc::Field::NumericType getType() const;

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

class Field::Builder {
public:
  typedef Field Builds;

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

  inline bool hasName();
  inline  ::capnp::Text::Builder getName();
  inline void setName( ::capnp::Text::Reader value);
  inline  ::capnp::Text::Builder initName(unsigned int size);
  inline void adoptName(::capnp::Orphan< ::capnp::Text>&& value);
  inline ::capnp::Orphan< ::capnp::Text> disownName();

  inline  ::uint32_t getOffset();
  inline void setOffset( ::uint32_t value);

  inline  ::vkc::Field::NumericType getType();
  inline void setType( ::vkc::Field::NumericType value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class Field::Pipeline {
public:
  typedef Field Pipelines;

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

class PointCloud::Reader {
public:
  typedef PointCloud Reads;

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

  inline bool hasPose() const;
  inline  ::vkc::Odometry3d::Reader getPose() const;

  inline  ::uint32_t getPointStride() const;

  inline bool hasFields() const;
  inline  ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>::Reader getFields() const;

  inline bool hasPoints() const;
  inline  ::capnp::Data::Reader getPoints() const;

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

class PointCloud::Builder {
public:
  typedef PointCloud Builds;

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

  inline bool hasPose();
  inline  ::vkc::Odometry3d::Builder getPose();
  inline void setPose( ::vkc::Odometry3d::Reader value);
  inline  ::vkc::Odometry3d::Builder initPose();
  inline void adoptPose(::capnp::Orphan< ::vkc::Odometry3d>&& value);
  inline ::capnp::Orphan< ::vkc::Odometry3d> disownPose();

  inline  ::uint32_t getPointStride();
  inline void setPointStride( ::uint32_t value);

  inline bool hasFields();
  inline  ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>::Builder getFields();
  inline void setFields( ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>::Reader value);
  inline  ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>::Builder initFields(unsigned int size);
  inline void adoptFields(::capnp::Orphan< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>>&& value);
  inline ::capnp::Orphan< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>> disownFields();

  inline bool hasPoints();
  inline  ::capnp::Data::Builder getPoints();
  inline void setPoints( ::capnp::Data::Reader value);
  inline  ::capnp::Data::Builder initPoints(unsigned int size);
  inline void adoptPoints(::capnp::Orphan< ::capnp::Data>&& value);
  inline ::capnp::Orphan< ::capnp::Data> disownPoints();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class PointCloud::Pipeline {
public:
  typedef PointCloud Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

  inline  ::vkc::Header::Pipeline getHeader();
  inline  ::vkc::Odometry3d::Pipeline getPose();
private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

inline bool Field::Reader::hasName() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool Field::Builder::hasName() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Text::Reader Field::Reader::getName() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::capnp::Text::Builder Field::Builder::getName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void Field::Builder::setName( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Text::Builder Field::Builder::initName(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), size);
}
inline void Field::Builder::adoptName(
    ::capnp::Orphan< ::capnp::Text>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Text> Field::Builder::disownName() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline  ::uint32_t Field::Reader::getOffset() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t Field::Builder::getOffset() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void Field::Builder::setOffset( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline  ::vkc::Field::NumericType Field::Reader::getType() const {
  return _reader.getDataField< ::vkc::Field::NumericType>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}

inline  ::vkc::Field::NumericType Field::Builder::getType() {
  return _builder.getDataField< ::vkc::Field::NumericType>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}
inline void Field::Builder::setType( ::vkc::Field::NumericType value) {
  _builder.setDataField< ::vkc::Field::NumericType>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS, value);
}

inline bool PointCloud::Reader::hasHeader() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool PointCloud::Builder::hasHeader() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::Header::Reader PointCloud::Reader::getHeader() const {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::vkc::Header::Builder PointCloud::Builder::getHeader() {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::Header::Pipeline PointCloud::Pipeline::getHeader() {
  return  ::vkc::Header::Pipeline(_typeless.getPointerField(0));
}
#endif  // !CAPNP_LITE
inline void PointCloud::Builder::setHeader( ::vkc::Header::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::Header>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::vkc::Header::Builder PointCloud::Builder::initHeader() {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void PointCloud::Builder::adoptHeader(
    ::capnp::Orphan< ::vkc::Header>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::Header>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::Header> PointCloud::Builder::disownHeader() {
  return ::capnp::_::PointerHelpers< ::vkc::Header>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline bool PointCloud::Reader::hasPose() const {
  return !_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline bool PointCloud::Builder::hasPose() {
  return !_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::Odometry3d::Reader PointCloud::Reader::getPose() const {
  return ::capnp::_::PointerHelpers< ::vkc::Odometry3d>::get(_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline  ::vkc::Odometry3d::Builder PointCloud::Builder::getPose() {
  return ::capnp::_::PointerHelpers< ::vkc::Odometry3d>::get(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::Odometry3d::Pipeline PointCloud::Pipeline::getPose() {
  return  ::vkc::Odometry3d::Pipeline(_typeless.getPointerField(1));
}
#endif  // !CAPNP_LITE
inline void PointCloud::Builder::setPose( ::vkc::Odometry3d::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::Odometry3d>::set(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), value);
}
inline  ::vkc::Odometry3d::Builder PointCloud::Builder::initPose() {
  return ::capnp::_::PointerHelpers< ::vkc::Odometry3d>::init(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline void PointCloud::Builder::adoptPose(
    ::capnp::Orphan< ::vkc::Odometry3d>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::Odometry3d>::adopt(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::Odometry3d> PointCloud::Builder::disownPose() {
  return ::capnp::_::PointerHelpers< ::vkc::Odometry3d>::disown(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}

inline  ::uint32_t PointCloud::Reader::getPointStride() const {
  return _reader.getDataField< ::uint32_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline  ::uint32_t PointCloud::Builder::getPointStride() {
  return _builder.getDataField< ::uint32_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void PointCloud::Builder::setPointStride( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline bool PointCloud::Reader::hasFields() const {
  return !_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline bool PointCloud::Builder::hasFields() {
  return !_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>::Reader PointCloud::Reader::getFields() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>>::get(_reader.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline  ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>::Builder PointCloud::Builder::getFields() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>>::get(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}
inline void PointCloud::Builder::setFields( ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>>::set(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), value);
}
inline  ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>::Builder PointCloud::Builder::initFields(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>>::init(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), size);
}
inline void PointCloud::Builder::adoptFields(
    ::capnp::Orphan< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>>::adopt(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>> PointCloud::Builder::disownFields() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::vkc::Field,  ::capnp::Kind::STRUCT>>::disown(_builder.getPointerField(
      ::capnp::bounded<2>() * ::capnp::POINTERS));
}

inline bool PointCloud::Reader::hasPoints() const {
  return !_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline bool PointCloud::Builder::hasPoints() {
  return !_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS).isNull();
}
inline  ::capnp::Data::Reader PointCloud::Reader::getPoints() const {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(_reader.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline  ::capnp::Data::Builder PointCloud::Builder::getPoints() {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}
inline void PointCloud::Builder::setPoints( ::capnp::Data::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Data>::set(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), value);
}
inline  ::capnp::Data::Builder PointCloud::Builder::initPoints(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::init(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), size);
}
inline void PointCloud::Builder::adoptPoints(
    ::capnp::Orphan< ::capnp::Data>&& value) {
  ::capnp::_::PointerHelpers< ::capnp::Data>::adopt(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::capnp::Data> PointCloud::Builder::disownPoints() {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::disown(_builder.getPointerField(
      ::capnp::bounded<3>() * ::capnp::POINTERS));
}

}  // namespace

CAPNP_END_HEADER

