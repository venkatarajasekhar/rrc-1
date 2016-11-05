/**
 *  @autor nikitas
 *  @date 11/2/16
 */
#pragma once

#include <cstddef>
#include <functional>

namespace rrc {

    typedef std::function<void()> IOCommand;

    enum class Mode : int {
        Read    = 0x00,
        Write   = 0x01,
        Append  = 0x02,
        Binary  = 0x04
    };

    class FileImpl {
    public:
        virtual void open(const char *path, Mode mode) = 0;

        virtual void close() = 0;

        virtual bool isOpen() = 0;

        virtual bool read(char *buffer, size_t size) = 0;

        virtual bool write(const char *buffer, size_t size) = 0;
    };

}

