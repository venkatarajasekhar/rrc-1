/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#pragma once

#include <rrc/io/File.h>
#include <rrc/io/Socket.h>
#include <rrc/io/CommandLine.h>

namespace rrc {
    class AbstractDeviceFactory {
    public:
        template <class Device>
        std::shared_ptr<Device> create();

        virtual std::shared_ptr<File> createFile() = 0;
        virtual std::shared_ptr<Socket> createSocket() = 0;
        virtual std::shared_ptr<CommandLine> createCommandLine() = 0;
    };
}


