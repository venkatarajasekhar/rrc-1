/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#pragma once

#include <queue>
#include <memory>
#include <functional>

#include <rrc/io/IOResult.h>
#include <rrc/io/Buffer.h>

namespace rrc {

    typedef std::function<IOResult()> IOOperation;
    typedef std::function<void(IOResult)> IOCallback;

    class IODevice {
    public:
        virtual IOResult read(Buffer buffer, IOCallback&& callback) = 0;

        virtual IOResult write(Buffer buffer, IOCallback&& callback) = 0;

        virtual IOResult close(IOCallback&& callback) = 0;

    protected:
        std::queue<IOOperation> mOperations;
        std::shared_ptr<IODevice> mDeviceImplementation;
    };

    typedef std::shared_ptr<IODevice> IODevicePtr;
}

