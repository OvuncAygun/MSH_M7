#ifndef ADDDEVICECOMMAND_H
#define ADDDEVICECOMMAND_H

#include "Command.h"
#include "IAddDeviceCommand.h"

class AddDeviceCommand : public Command, public IAddDeviceCommand {
public:
    // Constructor
    AddDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType type, int c)
        : Command(dm, mm, sm, l, secM){
    }

    ~AddDeviceCommand() {}

    void execute() {
        
        printf("Executing AddDevice: Type %d, Count %d\n", deviceCreationType, count);
       
        deviceManager->addDevice(deviceCreationType, name, config, count);

        std::string logDetails = "Type " + IntToString(static_cast<int>(deviceCreationType)) +
            ", Count " + IntToString(count);

        logger->writeLog("AddDevice", logDetails);
    }
};
#endif