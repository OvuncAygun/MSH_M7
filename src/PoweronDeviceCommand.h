#ifndef POWERONDEVICECOMMAND_H
#define POWERONDEVICECOMMAND_H

#include "Command.h"
#include "IPoweronDeviceCommand.h"

class PoweronDeviceCommand : public Command, public IPoweronDeviceCommand {
public:
    PoweronDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType type, int idx)
        : Command(dm, mm, sm, l, secM) {
    }

    virtual ~PoweronDeviceCommand() {}

    void execute() {
        printf("Executing PowerOn: Type %d, Index %d\n", deviceType, index);
        deviceManager->powerOnDevice(deviceType, index);
        logger->writeLog("PowerOnDevice", "Type " + IntToString(static_cast<int>(deviceType)) + ", Index " + IntToString(index));
    }
};
#endif 