/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#include "include/rrc/io/AbstractDeviceFactory.h"

namespace rrc {
    template <File>
    std::shared_ptr<File> AbstractDeviceFactory::create() {
        return createFile();
    }

    template <CommandLine>
    std::shared_ptr<CommandLine> AbstractDeviceFactory::create() {
        return createCommandLine();
    }

    template <Socket>
    std::shared_ptr<Socket> AbstractDeviceFactory::create() {
        return createSocket();
    }
}