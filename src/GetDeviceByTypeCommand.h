#ifndef GETDEVICEBYTYPECOMMAND_H
#define GETDEVICEBYTYPECOMMAND_H

#include "Command.h"
#include "IGetDeviceByTypeCommand.h"
#include <vector>

class GetDeviceByTypeCommand : public Command, public IGetDeviceByTypeCommand {
public:
    GetDeviceByTypeCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    ~GetDeviceByTypeCommand() {}

    void execute() {
        printf("Executing GetDeviceByTypeCommand: Listing all devices of Type %d\n", type);

        // IDeviceManager'dan bu t�rdeki t�m cihazlar� al�yoruz
        std::vector<IDevice*> devices = deviceManager->getDeviceByType(type);

        if (devices.empty()) {
            printf("No devices found for this type.\n");
        }
        else {
            for (size_t i = 0; i < devices.size(); ++i) {
                // Her cihaz�n ad�n� ve durumunu ekrana yazd�r�yoruz
                printf(" - [%d] Name: %s, Power: %s\n",
                    devices[i]->getIndex(),
                    devices[i]->getName().c_str(),
                    devices[i]->getPowerState() ? "ON" : "OFF");
            }
        }

        logger->writeLog("GetDeviceByType", "Listed devices of type " + IntToString(type));
    }
};
#endif