/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#include <rrc/io/unix/UnixFile.h>

#include <unistd.h>
#include <fcntl.h>

rrc::UnixFile::UnixFile() : mFileDescriptor(-1) {
    
}

void rrc::UnixFile::open(const char *path, Mode mode) {
    const int o_flags = getFlags(mode);
    mFileDescriptor = ::open(path, o_flags);
}

void rrc::UnixFile::close() {
    ::close(mFileDescriptor);
    mFileDescriptor = -1;
}

bool rrc::UnixFile::isOpen() {
    return mFileDescriptor != -1;
}

bool rrc::UnixFile::read(char *buffer, size_t size) {
    const ssize_t read = ::read(mFileDescriptor, buffer, size);
    return read != -1;
}

bool rrc::UnixFile::write(const char *buffer, size_t size) {
    const ssize_t wrote = ::write(mFileDescriptor, buffer, size);
    return wrote != -1;
}

int rrc::UnixFile::getFlags(rrc::Mode mode) {
    switch (mode) {
        case Mode::Read: return O_RDONLY;
        case Mode::Write: return O_WRONLY;
        case Mode::Append: return O_APPEND;
        case Mode::Binary: return O_CREAT;
        default: return 0;
    }
}
