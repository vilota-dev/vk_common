#ifndef VKC_OWNED_HPP
#define VKC_OWNED_HPP

#include <memory>
#include <capnp/message.h>
#include <capnp/serialize.h>

namespace vkc {
    /// Owned version of a capnproto value.
    template <typename T>
    class Owned {
    public:
        Owned() = default;
        /// Construct an owned version of a capnproto type `T` by deserializing the given buffer.
        ///
        /// The given buffer must be a capnproto serialized value of a `T`.
        explicit Owned(const char* buffer, size_t buffer_size): mBuffer(new capnp::MallocMessageBuilder())  {
            kj::ArrayPtr<const kj::byte> bytes(reinterpret_cast<const kj::byte*>(buffer), buffer_size);
            kj::ArrayInputStream stream(bytes);
            capnp::InputStreamMessageReader reader(stream);
            this->mBuffer.setRoot(reader);
        }

        /// Construct an owned version of a capnproto type `T` by deep-copying from a reader.
        explicit Owned(typename T::Reader& reader): mBuffer(new capnp::MallocMessageBuilder())  {
            this->mBuffer.setRoot(reader);
        }

        operator typename T::Builder() {
            return this->mBuffer->template getRoot<T>();
        }
        
        operator typename T::Reader() {
            return this->mBuffer->template getRoot<T>();
        }

        bool operator==(std::nullptr_t) {
            return this->mBuffer == nullptr;
        }

        bool operator!=(std::nullptr_t) {
            return this->mBuffer != nullptr;
        }

        bool operator==(const Owned<T>& other) {
            return this->mBuffer == other.mBuffer;
        }

        bool operator!=(const Owned<T>& other) {
            return this->mBuffer != other.mBuffer;
        }

    private:
        std::unique_ptr<capnp::MessageBuilder> mBuffer;
    };

}

#endif