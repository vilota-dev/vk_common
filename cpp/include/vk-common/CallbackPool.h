#pragma once

#include <memory>
#include <mutex>
#include <vector>
#include <functional>

namespace vkc {

    template<typename T> class Publisher;
    template<typename T> class Subscriber;
    template<typename T> class CallbackPool;

    template<typename T>
    using SharedCallbackPool = std::shared_ptr<CallbackPool<T>>;

    class AbstractCP {
    public:
        virtual ~AbstractCP() = default;
    };

    template<typename T>
    class CallbackPool : public AbstractCP {
    public:
        CallbackPool(const CallbackPool<T>&) = delete;
        CallbackPool<T>& operator=(const CallbackPool<T>&) = delete;

        static SharedCallbackPool<T> create() {
            return std::shared_ptr<CallbackPool<T>>(new CallbackPool());
        }

        void addCallback(std::function<void(T&)> f) {
            std::scoped_lock<std::mutex> lock(mMutex);
            mPool.push_back(f);
        }

    private:
        CallbackPool() = default;

        friend class Publisher<T>;
        friend class Subscriber<T>;
        
        std::mutex mMutex;
        std::vector<std::function<void(T&)>> mPool; // it is important the callback is quick to run, so not to block the caller
    };

} // namespace