#ifndef REMOVEDEVICECOMMAND_H
#define REMOVEDEVICECOMMAND_H

#include "../Command.h"

class RemoveDeviceCommand : public Command {
private:
    DeviceType deviceType;
    int index;
public:
    RemoveDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType type, int idx)
        : Command(dm, mm, sm, l, secM), deviceType(type), index(idx) {
    }

    virtual ~RemoveDeviceCommand() {}

    virtual void execute() {
        printf("Executing RemoveDevice: Type %d, Index %d\n", deviceType, index);
        deviceManager->removeDevice(deviceType, index);
        logger->writeLog("RemoveDevice", "Type " + IntToString(static_cast<int>(deviceType)) + ", Index " + IntToString(index));
    }
};
#endif 