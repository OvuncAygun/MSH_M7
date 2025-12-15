#ifndef ADDDEVICECOMMAND_H
#define ADDDEVICECOMMAND_H

#include "../Command.h" // inheritance from Command.h

class AddDeviceCommand : public Command {
private:
    DeviceType deviceType;
    int count;
public:
    // Command constructor
    AddDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType type, int c)
        : Command(dm, mm, sm, l, secM), deviceType(type), count(c) {
    }

    virtual ~AddDeviceCommand() {}

    virtual void execute() {
        printf("Executing AddDevice: Type %d, Count %d\n", deviceType, count);

        // IDeviceManager::addDevice'a sadece 2 argüman gönderiyoruz (C2660 hatasýnýn çözümü)
        deviceManager->addDevice(deviceType, count);

        // Loglama için C++98 uyumlu IntToString kullanýyoruz (E0415/E0165 hatasýnýn çözümü)
        std::string logDetails = "Type " + IntToString(deviceType) + ", Count " + IntToString(count);
        logger->writeLog("AddDevice", logDetails);
    }
};
#endif 
