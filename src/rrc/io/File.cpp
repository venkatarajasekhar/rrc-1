/**
 *  @autor nikitas
 *  @date 10/19/16
 */

#include <rrc/io/File.h>

rrc::File::File(rrc::FileImpl *mFileImpl, rrc::IOQueue &queue)
        : mFileImpl(mFileImpl), mIoQueue(queue) { }

std::shared_ptr<rrc::IOResult> rrc::File::open(const std::string &path, rrc::Mode mode) {
    auto result = std::make_shared<IOResult>();
    auto impl = mFileImpl;
    result->setState(false);
    mIoQueue.push([impl, path, mode, result]() {
        if (result.use_count() < 2) return;
        impl->open(path.c_str(), mode);
        result->setState(true);
    });
    return result;
}

std::shared_ptr<rrc::IOResult> rrc::File::close() {
    std::shared_ptr<rrc::IOResult> result;
    return result;
}

std::shared_ptr<rrc::IOResult> rrc::File::isOpen() {
    std::shared_ptr<rrc::IOResult> result;
    return result;
}

std::shared_ptr<rrc::IOResult> rrc::File::read() {
    std::shared_ptr<rrc::IOResult> result;
    return result;
}

std::shared_ptr<rrc::IOResult> rrc::File::write() {
    std::shared_ptr<rrc::IOResult> result;
    return result;
}
