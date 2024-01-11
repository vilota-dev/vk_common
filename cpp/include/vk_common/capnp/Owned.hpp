#ifndef VKC_OWNED_HPP
#define VKC_OWNED_HPP

#include <kj/io.h>
#include <memory>
#include <capnp/message.h>
#include <capnp/serialize.h>

namespace vkc {
    /// Owned version of a capnproto value.
    template <typename T>
    class Owned {
    public:
        Owned(): mBuilder(nullptr), mBuffer(nullptr) {};
        Owned(Owned<T>&&) = default;
        Owned& operator=(Owned&&) = default;

        /// Construct an owned version of a capnproto type `T` by deserializing the given buffer.
        ///
        /// The given buffer must be a capnproto serialized value of a `T`.
        explicit Owned(const char* buffer, size_t buffer_size): Owned() {
            kj::ArrayPtr<const kj::byte> bytes(reinterpret_cast<const kj::byte*>(buffer), buffer_size);
            kj::ArrayInputStream stream(bytes);
            capnp::InputStreamMessageReader reader(stream);
            this->mBuffer = std::unique_ptr<capnp::MallocMessageBuilder>(new capnp::MallocMessageBuilder());
            this->mBuffer->setRoot(reader);
            this->mBuilder = this->mBuffer->template getRoot<T>();
        }

        /// Construct an owned version of a capnproto type `T` by consuming a raw builder.
        explicit Owned(std::unique_ptr<capnp::MessageBuilder> raw): Owned() {
            this->mBuffer = raw;
            this->mBuilder = this->mBuffer->template getRoot<T>();
        }

        /// Construct an owned version of a capnproto type `T` by deserializing (with validation and copy)
        /// from the stream.
        explicit Owned(kj::InputStream& stream): Owned() {
            this->mBuffer = std::unique_ptr<capnp::MallocMessageBuilder>(new capnp::MallocMessageBuilder());
            capnp::readMessageCopy(stream, this->mBuilder);
            this->mBuilder = this->mBuffer->template getRoot<T>();
        }

        /// Construct an owned version of a capnproto type `T` by deep-copying from a reader.
        explicit Owned(typename T::Reader& reader): Owned()  {
            this->mBuffer = std::unique_ptr<capnp::MallocMessageBuilder>(new capnp::MallocMessageBuilder());
            this->mBuffer->setRoot(reader);
            this->mBuilder = this->mBuffer->template getRoot<T>();
        }

        /// Serialize the capnproto type `T` into the stream.  
        void serialize(kj::OutputStream& stream) {
            capnp::writeMessage(stream, this->mBuffer);
        }

        operator typename T::Builder() {
            return this->mBuilder;
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
        typename T::Builder mBuilder;
        std::unique_ptr<capnp::MessageBuilder> mBuffer;
    };

}

#endif