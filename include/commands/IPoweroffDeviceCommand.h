#ifndef IPOWEROFFDEVICECOMMAND_H
#define IPOWEROFFDEVICECOMMAND_H

#include "ICommand.h"
#include "DeviceType.h"
#include "IDevice.h"

class IPoweroffDeviceCommand : public virtual ICommand {
public:
    virtual ~IPoweroffDeviceCommand() = 0;
    
    IDevice* device;

    virtual void execute() = 0;
};
#endif 
