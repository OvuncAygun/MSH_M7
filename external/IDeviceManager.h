#pragma once

#include <string>
#include <vector>
#include "DeviceType.h"
#include "DeviceCreationType.h"
#include "IDevice.h"

class IDeviceManager {
public:
    virtual ~IDeviceManager() {}

    virtual void addDevice(
        DeviceCreationType deviceCreationType,
        const std::string& name,
        const std::vector<std::string>& config,
        int count
    ) = 0;

    virtual std::vector<IDevice*> getDeviceByType(DeviceType deviceType) = 0;
    virtual IDevice* getDeviceByIndex(int index) = 0;
    virtual void removeDevice(IDevice* device) = 0;
};
