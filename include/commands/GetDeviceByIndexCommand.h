#ifndef GETDEVICEBYINDEXCOMMAND_H
#define GETDEVICEBYINDEXCOMMAND_H

#include "../Command.h"

class GetDeviceByIndexCommand : public Command {
private:
    DeviceType type;
    int index;
public:
    GetDeviceByIndexCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType t, int idx)
        : Command(dm, mm, sm, l, secM), type(t), index(idx) {
    }

    virtual ~GetDeviceByIndexCommand() {}

    virtual void execute() {
        printf("Executing GetDeviceByIndexCommand: Looking up Type %d, Index %d\n", type, index);
        // IDeviceManager'dan cihazý alýp detaylarýný göstermelidir.
        // deviceManager->getDeviceByIndex(type, index); 
        logger->writeLog("GetDevice", "Fetched device at index " + std::to_string(index));
    }
};
#endif 