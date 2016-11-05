/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#pragma once

#include <queue>
#include <memory>

#include <rrc/io/Buffer.h>
#include <rrc/io/IOResult.h>
#include <rrc/io/FileImpl.h>

namespace rrc {

    typedef std::queue<IOCommand> IOQueue;

    class File {
        friend class FileSystem;
    public:
        std::shared_ptr<IOResult> open(const std::string &path, Mode mode);

        std::shared_ptr<IOResult> close();

        std::shared_ptr<IOResult> isOpen();

        std::shared_ptr<IOResult> read();

        std::shared_ptr<IOResult> write();

    private:
        File (FileImpl* mFileImpl, IOQueue &queue);

        std::shared_ptr<FileImpl> mFileImpl;
        IOQueue &mIoQueue;
    };
}
