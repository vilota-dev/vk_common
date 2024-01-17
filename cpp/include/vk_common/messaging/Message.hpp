#ifndef VKC_MESSAGE_HPP
#define VKC_MESSAGE_HPP

#include <cstdint>
#include <optional>

namespace vkc {
    struct Metadata {
        std::optional<uint64_t> mSequenceNumber = std::nullopt; //< Sequence number of message in its queue.
                                                                //< This member will be automatically filled if not populated. 
        std::optional<uint64_t> mPublishTime = std::nullopt;    //< Time instant, in miscroseconds, when the message is published.
                                                                //< This member will be automatically filled if not populated. 
    };

    /// Message containing a payload and its metadata.
    template<typename T>
    struct Message {
        Message() = default;
        Message(T payload) : mPayload(std::move(payload)) {}
        
        Metadata mMetadata;         //< Metadata associated with the message.
        T mPayload;                 //< Payload of the message (i.e. the actual data being sent).
    };
}

#endif