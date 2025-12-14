// external/IDeviceManager.h (TÜM ÝÇERÝÐÝ BUNUNLA DEÐÝÞTÝRÝN)

#pragma once

#include "DeviceType.h"
#include "IDevice.h"
#include <string>
#include <vector>

class IDeviceManager {
public:
    // Sanal Yýkýcý: Saf sanal yýkýcýlar, .cpp dosyasýnda gövde gerektirir.
    // En temiz çözüm, sadece sanal yapmaktýr.
    virtual ~IDeviceManager() {}

    virtual void addDevice(DeviceType deviceType, int count) = 0;

    virtual std::vector<IDevice*> getDeviceByType(DeviceType deviceType) = 0;
    //bunu denedim olmadý
  //  virtual void addDevice(DeviceType deviceType, std::string name,
  //      std::vector<std::string> config, int count) = 0;

    virtual IDevice* getDeviceByIndex(int index) = 0;

    virtual void removeDevice(DeviceType deviceType, int index) = 0;

    // powerOnDevice sýnýfýn içine taþýndý
    virtual void powerOnDevice(DeviceType deviceType, int index) = 0;
    // powerOffDevice de eklenmiþtir (Eðer projeniz gerektiriyorsa)
    virtual void powerOffDevice(DeviceType deviceType, int index) = 0;

}; // Sýnýf kapatma parantezi sadece burada olmalý.