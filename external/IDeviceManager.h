#pragma once

#include "DeviceCreationType.h"
#include "DeviceType.h"
#include "IDevice.h"
#include <string>
#include <vector>

class IDeviceManager {
public:
    // Sanal Y�k�c�: Saf sanal y�k�c�lar,.cpp dosyas�nda g�vde gerektirir.En temiz ��z�m, sadece sanal yapmakt�r.
    
    virtual ~IDeviceManager() {}

    virtual void addDevice(
        DeviceCreationType deviceCreationType,
        const std::string& name,
        const std::vector<std::string>& config,
        int count
    ) = 0;

    virtual std::vector<IDevice*> getDeviceByType(DeviceType deviceType) = 0;

    virtual IDevice* getDeviceByIndex(int index) = 0;

    virtual void removeDevice(DeviceType deviceType, int index) = 0;

    virtual void powerOnDevice(DeviceType deviceType, int index) = 0;
    
    virtual void powerOffDevice(DeviceType deviceType, int index) = 0;

}; 