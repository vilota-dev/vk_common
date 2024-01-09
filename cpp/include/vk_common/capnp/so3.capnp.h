// Generated by Cap'n Proto compiler, DO NOT EDIT
// source: so3.capnp

#pragma once

#include <capnp/generated-header-support.h>
#include <kj/windows-sanity.h>

#ifndef CAPNP_VERSION
#error "CAPNP_VERSION is not defined, is capnp/generated-header-support.h missing?"
#elif CAPNP_VERSION != 1000001
#error "Version mismatch between generated code and library headers.  You must use the same version of the Cap'n Proto compiler and library."
#endif


CAPNP_BEGIN_HEADER

namespace capnp {
namespace schemas {

CAPNP_DECLARE_SCHEMA(b9c1440daf004061);

}  // namespace schemas
}  // namespace capnp

namespace vkc {

struct So3 {
  So3() = delete;

  class Reader;
  class Builder;
  class Pipeline;

  struct _capnpPrivate {
    CAPNP_DECLARE_STRUCT_HEADER(b9c1440daf004061, 4, 0)
    #if !CAPNP_LITE
    static constexpr ::capnp::_::RawBrandedSchema const* brand() { return &schema->defaultBrand; }
    #endif  // !CAPNP_LITE
  };
};

// =======================================================================================

class So3::Reader {
public:
  typedef So3 Reads;

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

  inline double getZ() const;

  inline double getW() const;

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

class So3::Builder {
public:
  typedef So3 Builds;

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

  inline double getZ();
  inline void setZ(double value);

  inline double getW();
  inline void setW(double value);

private:
  ::capnp::_::StructBuilder _builder;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::ToDynamic_;
  friend class ::capnp::Orphanage;
  template <typename, ::capnp::Kind>
  friend struct ::capnp::_::PointerHelpers;
};

#if !CAPNP_LITE
class So3::Pipeline {
public:
  typedef So3 Pipelines;

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

inline double So3::Reader::getX() const {
  return _reader.getDataField<double>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}

inline double So3::Builder::getX() {
  return _builder.getDataField<double>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS);
}
inline void So3::Builder::setX(double value) {
  _builder.setDataField<double>(
      ::capnp::bounded<0>() * ::capnp::ELEMENTS, value);
}

inline double So3::Reader::getY() const {
  return _reader.getDataField<double>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}

inline double So3::Builder::getY() {
  return _builder.getDataField<double>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS);
}
inline void So3::Builder::setY(double value) {
  _builder.setDataField<double>(
      ::capnp::bounded<1>() * ::capnp::ELEMENTS, value);
}

inline double So3::Reader::getZ() const {
  return _reader.getDataField<double>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}

inline double So3::Builder::getZ() {
  return _builder.getDataField<double>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS);
}
inline void So3::Builder::setZ(double value) {
  _builder.setDataField<double>(
      ::capnp::bounded<2>() * ::capnp::ELEMENTS, value);
}

inline double So3::Reader::getW() const {
  return _reader.getDataField<double>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}

inline double So3::Builder::getW() {
  return _builder.getDataField<double>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS);
}
inline void So3::Builder::setW(double value) {
  _builder.setDataField<double>(
      ::capnp::bounded<3>() * ::capnp::ELEMENTS, value);
}

}  // namespace

CAPNP_END_HEADER
