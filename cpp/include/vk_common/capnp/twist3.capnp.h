// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: twist3.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>

#ifndef CAPNP_VERSION
#error "CAPNP_VERSION is not defined, is capnp/generated-header-support.h missing?"
#elif CAPNP_VERSION != 1000002
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif

#include "vector3.capnp.h"

CAPNP_BEGIN_HEADER

namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(81743c67e0b0a254);

}  // namespace schemas
}  // namespace capnp

namespace vkc {

struct Twist3 {
  Twist3() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(81743c67e0b0a254, 0, 2)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class Twist3::Reader {
public:
  typedef Twist3 Reads;

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

  inline bool hasLinear() const;
  inline  ::vkc::Vector3d::Reader getLinear() const;

  inline bool hasAngular() const;
  inline  ::vkc::Vector3d::Reader getAngular() const;

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

class Twist3::Builder {
public:
  typedef Twist3 Builds;

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

  inline bool hasLinear();
  inline  ::vkc::Vector3d::Builder getLinear();
  inline void setLinear( ::vkc::Vector3d::Reader value);
  inline  ::vkc::Vector3d::Builder initLinear();
  inline void adoptLinear(::capnp::Orphan< ::vkc::Vector3d>&& value);
  inline ::capnp::Orphan< ::vkc::Vector3d> disownLinear();

  inline bool hasAngular();
  inline  ::vkc::Vector3d::Builder getAngular();
  inline void setAngular( ::vkc::Vector3d::Reader value);
  inline  ::vkc::Vector3d::Builder initAngular();
  inline void adoptAngular(::capnp::Orphan< ::vkc::Vector3d>&& value);
  inline ::capnp::Orphan< ::vkc::Vector3d> disownAngular();

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class Twist3::Pipeline {
public:
  typedef Twist3 Pipelines;

  inline Pipeline(decltype(nullptr)): _typeless(nullptr) {}
  inline explicit Pipeline(::capnp::AnyPointer::Pipeline&& typeless)
      : _typeless(kj::mv(typeless)) {}

  inline  ::vkc::Vector3d::Pipeline getLinear();
  inline  ::vkc::Vector3d::Pipeline getAngular();
private:
  ::capnp::AnyPointer::Pipeline _typeless;
  friend class ::capnp::PipelineHook;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
};
#endif  // !CAPNP_LITE

// =======================================================================================

inline bool Twist3::Reader::hasLinear() const {
  return !_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline bool Twist3::Builder::hasLinear() {
  return !_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::Vector3d::Reader Twist3::Reader::getLinear() const {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::get(_reader.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline  ::vkc::Vector3d::Builder Twist3::Builder::getLinear() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::get(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::Vector3d::Pipeline Twist3::Pipeline::getLinear() {
  return  ::vkc::Vector3d::Pipeline(_typeless.getPointerField(0));
}
#endif  // !CAPNP_LITE
inline void Twist3::Builder::setLinear( ::vkc::Vector3d::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::Vector3d>::set(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), value);
}
inline  ::vkc::Vector3d::Builder Twist3::Builder::initLinear() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::init(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}
inline void Twist3::Builder::adoptLinear(
    ::capnp::Orphan< ::vkc::Vector3d>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::Vector3d>::adopt(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::Vector3d> Twist3::Builder::disownLinear() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::disown(_builder.getPointerField(
      ::capnp::bounded<0>() * ::capnp::POINTERS));
}

inline bool Twist3::Reader::hasAngular() const {
  return !_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline bool Twist3::Builder::hasAngular() {
  return !_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS).isNull();
}
inline  ::vkc::Vector3d::Reader Twist3::Reader::getAngular() const {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::get(_reader.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline  ::vkc::Vector3d::Builder Twist3::Builder::getAngular() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::get(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
#if !CAPNP_LITE
inline  ::vkc::Vector3d::Pipeline Twist3::Pipeline::getAngular() {
  return  ::vkc::Vector3d::Pipeline(_typeless.getPointerField(1));
}
#endif  // !CAPNP_LITE
inline void Twist3::Builder::setAngular( ::vkc::Vector3d::Reader value) {
  ::capnp::_::PointerHelpers< ::vkc::Vector3d>::set(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), value);
}
inline  ::vkc::Vector3d::Builder Twist3::Builder::initAngular() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::init(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}
inline void Twist3::Builder::adoptAngular(
    ::capnp::Orphan< ::vkc::Vector3d>&& value) {
  ::capnp::_::PointerHelpers< ::vkc::Vector3d>::adopt(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS), kj::mv(value));
}
inline ::capnp::Orphan< ::vkc::Vector3d> Twist3::Builder::disownAngular() {
  return ::capnp::_::PointerHelpers< ::vkc::Vector3d>::disown(_builder.getPointerField(
      ::capnp::bounded<1>() * ::capnp::POINTERS));
}

}  // namespace

CAPNP_END_HEADER

