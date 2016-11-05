/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#pragma once

namespace rrc {
    class IOResult {
    public:
        bool isReady();
        void setState(bool ready);
    private:
        bool mReady;
    };
}
