/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#pragma once

#include <rrc/io/IODevice.h>

namespace rrc {
    class File : public IODevice {
    public:
        enum {
            Read, Write
        };

        virtual IOResult open(const std::string& path, int mode) = 0;

        virtual IOResult close(IOCallback&& callback) = 0;

        virtual IOResult read(Buffer buffer, IOCallback&& callback) = 0;

        virtual IOResult write(Buffer buffer, IOCallback&& callback) = 0;

    private:
    };
}


