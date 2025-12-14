#ifndef GETDEVICEBYTYPECOMMAND_H
#define GETDEVICEBYTYPECOMMAND_H

#include "../Command.h"

class GetDeviceByTypeCommand : public Command {
private:
    DeviceType type;
public:
    GetDeviceByTypeCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType t)
        : Command(dm, mm, sm, l, secM), type(t) {
    }

    virtual ~GetDeviceByTypeCommand() {}

    virtual void execute() {
        printf("Executing GetDeviceByTypeCommand: Listing all devices of Type %d\n", type);
        // IDeviceManager'dan bu türdeki tüm cihazlarý alýp listelemelidir.
        // deviceManager->getAllDevicesByType(type); 
        logger->writeLog("GetDevice", "Listed devices of type " + std::to_string(type));
    }
};
#endif // GETDEVICEBYTYPECOMMAND_H