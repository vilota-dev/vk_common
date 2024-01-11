#ifndef VKC_OWNED_HPP
#define VKC_OWNED_HPP

#include <kj/io.h>
#include <memory>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <mutex>

namespace vkc {
    /// Shared ownership to a capnproto value.
    template <typename T>
    class Shared {
    public:
        Shared(): mBuffer(nullptr) {};

        /// Construct an owned version of a capnproto type `T` by consuming a raw builder.
        explicit Shared(std::unique_ptr<capnp::MessageBuilder> raw): Shared() {
            this->mBuffer = std::move(raw);
        }

        /// Construct an owned version of a capnproto type `T` by deserializing (with validation and copy)
        /// from the stream.
        explicit Shared(kj::InputStream& stream): Shared() {
            this->mBuffer = std::shared_ptr<capnp::MallocMessageBuilder>(new capnp::MallocMessageBuilder());
            capnp::readMessageCopy(stream, *this->mBuffer);
        }

        /// Construct an owned version of a capnproto type `T` by deep-copying from a reader.
        explicit Shared(typename T::Reader& reader): Shared()  {
            this->mBuffer = std::shared_ptr<capnp::MallocMessageBuilder>(new capnp::MallocMessageBuilder());
            this->mBuffer->setRoot(reader);
        }

        /// Serialize the capnproto type `T` into the stream.  
        void serialize(kj::OutputStream& stream) {
            capnp::writeMessage(stream, *this->mBuffer);
        }

        /// Implicitly use this as a `T::Reader`.
        operator typename T::Reader() {
            return this->mBuffer->template getRoot<T>();
        }

        bool operator==(std::nullptr_t) {
            return this->mBuffer == nullptr;
        }

        bool operator!=(std::nullptr_t) {
            return this->mBuffer != nullptr;
        }

        bool operator==(const Shared<T>& other) {
            return this->mBuffer == other.mBuffer;
        }

        bool operator!=(const Shared<T>& other) {
            return this->mBuffer != other.mBuffer;
        }

    private:
        std::shared_ptr<capnp::MessageBuilder> mBuffer;
    };

}

#endif