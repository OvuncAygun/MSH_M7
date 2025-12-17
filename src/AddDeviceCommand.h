#ifndef ADDDEVICECOMMAND_H
#define ADDDEVICECOMMAND_H

#include "Command.h"
#include "IAddDeviceCommand.h"

class AddDeviceCommand : public Command, public IAddDeviceCommand {
public:
    // Kurucu (Constructor): T�m mant�k burada
    AddDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType type, int c)
        : Command(dm, mm, sm, l, secM){
    }

    ~AddDeviceCommand() {}

    void execute() {
        // Konsol ��kt�s�
        printf("Executing AddDevice: Type %d, Count %d\n", deviceCreationType, count);

        // Manager �a�r�s�
        deviceManager->addDevice(deviceCreationType, name, config, count);

        // Loglama i�lemi: static_cast ile enum'� int'e �eviriyoruz (T�r g�venli�i i�in)
        std::string logDetails = "Type " + IntToString(static_cast<int>(deviceCreationType)) +
            ", Count " + IntToString(count);

        logger->writeLog("AddDevice", logDetails);
    }
};
#endif