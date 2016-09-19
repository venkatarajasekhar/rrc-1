/**
 *  @autor arssivka
 *  @date 8/24/16
 */

#pragma once


#include <forward_list>
#include "MessageListener.h"
#include "NonCopyable.h"

namespace {
    namespace pb = google::protobuf;
}

namespace rrc {
    class Topic {
    public:

        /**
         * @brief Constructor of Topic
         * @param id Type id of the message which this topic handles
         */
        Topic(TypeId id);

        /**
         * @brief Register message listener
         * @param listener Pointer to listener to register
         * @return True if succeed otherwise false
         */
        bool addListener(MessageListenerPtr listener);

        /**
         * @brief Unregisters specified listener
         * @param listener Pointer to listener that needs to be unregistred
         */
        void removeListener(MessageListenerPtr listener);

        /**
         * @brief Sends the message
         * @param message Pointer to message that needs to be sent
         */
        void sendMessage(MessagePtr message);

        /**
         * @brief Returns type id of the messages of this topic
         * @return Type id - unsigned int
         */
        TypeId getTypeId() const noexcept;

        /**
         * @brief Checks the capability of desried type id with this topic
         * @param typeId Type id ou meed check with
         * @return True of compatible otherwise false
         */
        bool checkCapability(TypeId typeId) const noexcept;

        /**
         * @brief Checks if this topic has listeners
         * @return True if topic has lesteners, otherwise false
         */
        bool hasListeners() const;

    private:
        TypeId mTypeId;
        std::forward_list<MessageListenerPtr> mListenersList;

    };

    typedef std::shared_ptr<Topic> TopicPtr;
}


