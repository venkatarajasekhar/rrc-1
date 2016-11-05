/**
 *  @autor nikitas
 *  @date 11/2/16
 */
#pragma once

#include <queue>

#include <rrc/io/File.h>

namespace rrc {

    class FileSystem {
    public:
        FileSystem(IOQueue& queue);

        FileSystem(const FileSystem &) = delete;
        FileSystem& operator=(const FileSystem&) = delete;

        File createFile();

    private:
        IOQueue& mCommandsQueue;
    };

}


