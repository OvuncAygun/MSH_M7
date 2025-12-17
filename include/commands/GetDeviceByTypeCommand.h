#ifndef GETDEVICEBYTYPECOMMAND_H
#define GETDEVICEBYTYPECOMMAND_H

#include "../Command.h"
#include <vector>

class GetDeviceByTypeCommand : public Command {
private:
    DeviceType type;
    std::vector<IDevice*>* listResult; // M8'deki listenin adresi

public:
    GetDeviceByTypeCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType t, std::vector<IDevice*>* res)
        : Command(dm, mm, sm, l, secM), type(t), listResult(res) {
    }

    virtual ~GetDeviceByTypeCommand() {}

    virtual void execute() {
        printf("Executing GetDeviceByTypeCommand: Listing all devices of Type %d\n", type);

        // IDeviceManager'dan bu türdeki tüm cihazlarý alýyoruz
        std::vector<IDevice*> devices = deviceManager->getDeviceByType(type);

        if (devices.empty()) {
            printf("No devices found for this type.\n");
        }
        else {
            for (size_t i = 0; i < devices.size(); ++i) {
                // Her cihazýn adýný ve durumunu ekrana yazdýrýyoruz
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