#ifndef POWEROFFDEVICECOMMAND_H
#define POWEROFFDEVICECOMMAND_H

#include "../Command.h"

class PoweroffDeviceCommand : public Command {
private:
    DeviceType deviceType;
    int index;
public:
    PoweroffDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType type, int idx)
        : Command(dm, mm, sm, l, secM), deviceType(type), index(idx) {
    }

    virtual ~PoweroffDeviceCommand() {}

    virtual void execute() {
        printf("Executing PowerOff: Type %d, Index %d\n", deviceType, index);
        deviceManager->powerOffDevice(deviceType, index);
        logger->writeLog("PowerOffDevice", "Type " + std::to_string(deviceType) + ", Index " + std::to_string(index));
    }
};
#endif 
