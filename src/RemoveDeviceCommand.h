#ifndef REMOVEDEVICECOMMAND_H
#define REMOVEDEVICECOMMAND_H

#include "Command.h"
#include "IRemoveDeviceCommand.h"

class RemoveDeviceCommand : public Command, public IRemoveDeviceCommand {
public:
    RemoveDeviceCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType type, int idx)
        : Command(dm, mm, sm, l, secM) {
    }

    ~RemoveDeviceCommand() {}

    void execute() {
        printf("Executing RemoveDevice: Type %d, Index %d\n", deviceType, index);
        deviceManager->removeDevice(deviceType, index);
        logger->writeLog("RemoveDevice", "Type " + IntToString(static_cast<int>(deviceType)) + ", Index " + IntToString(index));
    }
};
#endif 