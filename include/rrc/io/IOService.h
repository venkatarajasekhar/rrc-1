/**
 *  @autor nikitas
 *  @date 10/19/16
 */
#pragma once

#include <list>

#include <rrc/io/IODevice.h>
#include <rrc/io/AbstractDeviceFactory.h>

namespace rrc {
    class IOService {
        friend class IODevice;
    public:
        template <class Device>
        void registrateDevice(std::shared_ptr<Device> device) {
            static_assert(std::is_base_of<Device, IODevice>::value,
                "Device must be base of IODevice");
            static_cast<std::shared_ptr<IODevice>>(device);
            mDevices.push_back(device);
        }

        void run();

        void step();
    private:
        std::list<IODevicePtr> mDevices;
        std::shared_ptr<AbstractDeviceFactory> mDeviceFactory;
    };

}


