/**
 *  @autor arssivka
 *  @date 7/8/16
 */

#pragma once


#include "ID.h"
#include "Message.h"
#include "NonCopyable.h"

namespace rrc {
    template <typename T>
    class Subscriber : private NonCopyable {
    public:
        typedef T type;

        Subscriber(const ID& id, const std::string& topic, size_t queueSize);

        void getQueueSize() const;

        bool isConnected() const;

        void push(Message<T>::Ptr msg);

        Message<T>::Ptr pop();

    private:

    };
}

