#ifndef POWEROFFDEVICECOMMAND_H
#define POWEROFFDEVICECOMMAND_H

#include "Command.h"
#include "IPoweroffDeviceCommand.h"

class PoweroffDeviceCommand : public Command, public IPoweroffDeviceCommand {
public:
    PoweroffDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    ~PoweroffDeviceCommand() {}

    void execute() {
        printf("Executing PowerOff: Type %d, Index %d\n", device->getDeviceType(), device->getIndex());
        deviceManager->powerOffDevice(device);
        logger->writeLog("PowerOffDevice", "Type " + IntToString(static_cast<int>(device->getDeviceType())) + ", Index " + IntToString(device->getIndex()));
    }
};
#endif 
