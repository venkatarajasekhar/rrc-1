/**
 *  @autor nikitas
 *  @date 11/2/16
 */

#include <rrc/io/FileSystem.h>

#ifndef UNIX
#include <rrc/io/unix/UnixFile.h>
typedef rrc::UnixFile FImpl;
//TODO: else if WinFile
#endif

rrc::FileSystem::FileSystem(std::queue<rrc::IOCommand> &queue) : mCommandsQueue(queue) {

}

rrc::File rrc::FileSystem::createFile() {
    return File(new FImpl, mCommandsQueue);
}
