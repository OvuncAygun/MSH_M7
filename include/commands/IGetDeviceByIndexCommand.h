#ifndef IGETDEVICEBYINDEXCOMMAND_H
#define IGETDEVICEBYINDEXCOMMAND_H

#include "ICommand.h"
#include "IDevice.h"

class IGetDeviceByIndexCommand : public virtual ICommand {
public:
    virtual ~IGetDeviceByIndexCommand() = 0;

    int index;
    IDevice* device;

    virtual void execute() = 0;
};
#endif