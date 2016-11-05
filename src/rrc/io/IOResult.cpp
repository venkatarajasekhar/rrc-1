/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#include <rrc/io/IOResult.h>

void rrc::IOResult::setState(bool ready) {
    mReady = ready;
}

bool rrc::IOResult::isReady() {
    return mReady;
}
