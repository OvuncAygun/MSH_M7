#ifndef IPOWERONDEVICECOMMAND_H
#define IPOWERONDEVICECOMMAND_H

#include "ICommand.h"
#include "DeviceType.h"
#include "IDevice.h"

class IPoweronDeviceCommand : public virtual ICommand {
public:
    virtual ~IPoweronDeviceCommand() = 0;

    IDevice* device;

    virtual void execute() = 0;
};
#endif 