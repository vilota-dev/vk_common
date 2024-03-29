// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: vector2.capnp

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

CAPNP_DECLARE_SCHEMA(b1472b6dd45d3316);
CAPNP_DECLARE_SCHEMA(f42a8c72f18a33be);

}  // namespace schemas
}  // namespace capnp

namespace vkc {

struct Vector2f {
  Vector2f() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(b1472b6dd45d3316, 1, 0)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

struct Vector2d {
  Vector2d() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(f42a8c72f18a33be, 2, 0)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class Vector2f::Reader {
public:
  typedef Vector2f Reads;

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

  inline float getX() const;

  inline float getY() const;

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

class Vector2f::Builder {
public:
  typedef Vector2f Builds;

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

  inline float getX();
  inline void setX(float value);

  inline float getY();
  inline void setY(float value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class Vector2f::Pipeline {
public:
  typedef Vector2f Pipelines;

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

class Vector2d::Reader {
public:
  typedef Vector2d Reads;

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

  inline double getX() const;

  inline double getY() const;

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

class Vector2d::Builder {
public:
  typedef Vector2d Builds;

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

  inline double getX();
  inline void setX(double value);

  inline double getY();
  inline void setY(double value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class Vector2d::Pipeline {
public:
  typedef Vector2d Pipelines;

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

inline float Vector2f::Reader::getX() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline float Vector2f::Builder::getX() {
  return _builder.getDataField<float>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void Vector2f::Builder::setX(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline float Vector2f::Reader::getY() const {
  return _reader.getDataField<float>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline float Vector2f::Builder::getY() {
  return _builder.getDataField<float>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void Vector2f::Builder::setY(float value) {
  _builder.setDataField<float>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline double Vector2d::Reader::getX() const {
  return _reader.getDataField<double>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline double Vector2d::Builder::getX() {
  return _builder.getDataField<double>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void Vector2d::Builder::setX(double value) {
  _builder.setDataField<double>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline double Vector2d::Reader::getY() const {
  return _reader.getDataField<double>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline double Vector2d::Builder::getY() {
  return _builder.getDataField<double>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void Vector2d::Builder::setY(double value) {
  _builder.setDataField<double>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

}  // namespace

CAPNP_END_HEADER

