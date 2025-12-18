#pragma once

#include "DeviceCreationType.h"
#include "DeviceType.h"
#include "IDevice.h"
#include <string>
#include <vector>

class IDeviceManager {
public:
    // Virtual Destroyer: Pure virtual destroyers require a body in the .cpp file. 
    // The cleanest solution is to make it virtual only.
    
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

    virtual void powerOnDevice(IDevice* device) = 0;
    
    virtual void powerOffDevice(IDevice* device) = 0;
}; 