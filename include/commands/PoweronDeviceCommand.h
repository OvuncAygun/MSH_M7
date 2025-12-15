#ifndef POWERONDEVICECOMMAND_H
#define POWERONDEVICECOMMAND_H

#include "../Command.h"

class PoweronDeviceCommand : public Command {
private:
    DeviceType deviceType;
    int index;
public:
    PoweronDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType type, int idx)
        : Command(dm, mm, sm, l, secM), deviceType(type), index(idx) {
    }

    virtual ~PoweronDeviceCommand() {}

    virtual void execute() {
        printf("Executing PowerOn: Type %d, Index %d\n", deviceType, index);
        deviceManager->powerOnDevice(deviceType, index);
        logger->writeLog("PowerOnDevice", "Type " + std::to_string(deviceType) + ", Index " + std::to_string(index));
    }
};
#endif 