#ifndef VKC_OWNED_HPP
#define VKC_OWNED_HPP

#include <memory>
#include <capnp/message.h>
#include <capnp/serialize.h>

namespace vkc {

    template <typename T>
    class Owned {
    public:
        /// Construct an owned version of a capnproto type `T` by deserializing the given buffer.
        ///
        /// The given buffer must be a capnproto serialized value of a `T`.
        explicit Owned(const char* buffer, size_t buffer_size): Owned() {
            kj::ArrayPtr<const kj::byte> bytes(reinterpret_cast<const kj::byte*>(buffer), buffer_size);
            kj::ArrayInputStream stream(bytes);
            capnp::InputStreamMessageReader reader(stream);
            this->mBuffer.setRoot(reader);
        }

        /// Construct an owned version of a capnproto type `T` by deep-copying from a reader.
        explicit Owned(typename T::Reader& reader): Owned() {
            this->mBuffer.setRoot(reader);
        }

        operator typename T::Builder() {
            return this->mBuffer->template getRoot<T>();
        }
        
        operator typename T::Reader() {
            return this->mBuffer->template getRoot<T>();
        }

    private:
        explicit Owned(): mBuffer(new capnp::MallocMessageBuilder()) {}

        std::unique_ptr<capnp::MessageBuilder> mBuffer;
    };

}

#endif