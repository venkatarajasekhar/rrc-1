/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#pragma once

#include <rrc/io/FileImpl.h>

namespace rrc {

    class UnixFile : public FileImpl {
    public:
        UnixFile();

        virtual void open(const char *path, Mode mode) override;

        virtual void close() override;

        virtual bool isOpen() override;

        virtual bool read(char *buffer, size_t size) override;

        virtual bool write(const char *buffer, size_t size) override;

    private:
        static int getFlags(Mode mode);

        int mFileDescriptor;
    };

}


