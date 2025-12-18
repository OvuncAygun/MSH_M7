#ifndef POWERONDEVICECOMMAND_H
#define POWERONDEVICECOMMAND_H

#include "Command.h"
#include "IPoweronDeviceCommand.h"

class PoweronDeviceCommand : public Command, public IPoweronDeviceCommand {
public:
    PoweronDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    virtual ~PoweronDeviceCommand() {}

    void execute() {
        printf("Executing PowerOn: Type %d, Index %d\n", device->getDeviceType(), device->getIndex());
        deviceManager->powerOnDevice(device);
        logger->writeLog("PowerOnDevice", "Type " + IntToString(static_cast<int>(device->getDeviceType())) + ", Index " + IntToString(device->getIndex()));
    }
};
#endif 