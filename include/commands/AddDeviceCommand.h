#ifndef ADDDEVICECOMMAND_H
#define ADDDEVICECOMMAND_H

#include "../Command.h"

class AddDeviceCommand : public Command {
private:
    DeviceType deviceType;
    int count;

public:
    // Kurucu (Constructor): Tüm mantýk burada
    AddDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType type, int c)
        : Command(dm, mm, sm, l, secM), deviceType(type), count(c) {
    }

    virtual ~AddDeviceCommand() {}

    virtual void execute() {
        // Konsol çýktýsý
        printf("Executing AddDevice: Type %d, Count %d\n", deviceType, count);

        // Manager çaðrýsý
        deviceManager->addDevice(deviceType, count);

        // Loglama iþlemi: static_cast ile enum'ý int'e çeviriyoruz (Tür güvenliði için)
        std::string logDetails = "Type " + IntToString(static_cast<int>(deviceType)) +
            ", Count " + IntToString(count);

        logger->writeLog("AddDevice", logDetails);
    }
};

#endif