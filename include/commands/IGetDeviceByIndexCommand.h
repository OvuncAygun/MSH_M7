#ifndef IGETDEVICEBYINDEXCOMMAND_H
#define IGETDEVICEBYINDEXCOMMAND_H

#include "ICommand.h"
#include "IDevice.h"

class IGetDeviceByIndexCommand : public ICommand {
public:
    virtual ~IGetDeviceByIndexCommand() = 0;

    int index;
    IDevice** resultHolder; // The address of the IDevice* variable in Module 8.

    virtual void execute() = 0;
};
#endif