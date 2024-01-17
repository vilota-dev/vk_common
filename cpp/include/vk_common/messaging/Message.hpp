#ifndef VKC_MESSAGE_HPP
#define VKC_MESSAGE_HPP

#include <cstdint>

namespace vkc {
    struct Metadata {
        uint64_t mSequenceNumber;   //< Sequence number of message in its queue.
        uint64_t mPublishTime;      //< Time instant, in miscroseconds, when the message is published.
    };

    /// Message containing a payload and its metadata.
    template<typename T>
    struct Message {
        Metadata mMetadata;         //< Metadata associated with the message.
        T mPayload;                 //< Payload of the message (i.e. the actual data being sent).
    };
}

#endif