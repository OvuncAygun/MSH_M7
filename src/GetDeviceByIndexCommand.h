#ifndef GETDEVICEBYINDEXCOMMAND_H
#define GETDEVICEBYINDEXCOMMAND_H

#include "Command.h"
#include "IGetDeviceByIndexCommand.h"

class GetDeviceByIndexCommand : public Command, public IGetDeviceByIndexCommand {
public:
    GetDeviceByIndexCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    virtual ~GetDeviceByIndexCommand() {}

    virtual void execute() {
        //printf("Executing GetDeviceByIndexCommand: Looking up Index %d\n", index);

        device = deviceManager->getDeviceByIndex(index);

        /*
        if (device != NULL) {
            printf("Device Found:\n");
            printf(" -> Name: %s\n", device->getName().c_str());
            printf(" -> Type: %d\n", device->getDeviceType());
            printf(" -> Power State: %s\n", device->getPowerState() ? "ON" : "OFF");
            printf(" -> Op. State: %s\n", device->getOperationState() ? "Working" : "Idle");
        }
        else {
            printf("ERROR: Device at index %d not found!\n", index);
        }
        */

        logger->writeLog("GetDeviceByIndex", "Fetched device at index " + IntToString(index));
    }
};
#endif