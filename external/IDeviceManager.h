#pragma once

#include "DeviceType.h"
#include "IDevice.h"

#include <string>
#include <vector>

class IDeviceManager {
public:
    virtual ~IDeviceManager() = 0;

    virtual void addDevice(DeviceType deviceType, std::string name,
        std::vector<std::string> config, int count) = 0;
    
    virtual std::vector<IDevice*> getDeviceByType(DeviceType deviceType) = 0;

    virtual IDevice* getDeviceByIndex(int index) = 0;

    virtual void removeDevice(IDevice* device) = 0;
};