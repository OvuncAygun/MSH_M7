#ifndef GETDEVICEBYINDEXCOMMAND_H
#define GETDEVICEBYINDEXCOMMAND_H

#include "../Command.h"
#include "../../external/IDevice.h"

class GetDeviceByIndexCommand : public Command {
private:
    DeviceType type;
    int index;
    IDevice** resultHolder; // Modül 8'deki IDevice* deðiþkeninin adresi

public:
    GetDeviceByIndexCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        DeviceType t, int idx, IDevice** res)
        : Command(dm, mm, sm, l, secM), type(t), index(idx), resultHolder(res) {
    }

    virtual ~GetDeviceByIndexCommand() {}

    virtual void execute() {
        printf("Executing GetDeviceByIndexCommand: Looking up Index %d\n", index);

        // IDeviceManager'dan indekse göre cihazý çekiyoruz
        IDevice* device = deviceManager->getDeviceByIndex(index);

        if (device != NULL) {
            // Cihazýn detaylý bilgilerini yazdýrýyoruz
            printf("Device Found:\n");
            printf(" -> Name: %s\n", device->getName().c_str());
            printf(" -> Type: %d\n", device->getDeviceType());
            printf(" -> Power State: %s\n", device->getPowerState() ? "ON" : "OFF");
            printf(" -> Op. State: %s\n", device->getOperationState() ? "Working" : "Idle");
        }
        else {
            printf("ERROR: Device at index %d not found!\n", index);
        }

        logger->writeLog("GetDeviceByIndex", "Fetched device at index " + IntToString(index));
    }
};
#endif