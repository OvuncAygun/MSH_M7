#pragma once

#include "ICommand.h"
#include "IDevice.h"

class GetDeviceByIndexCommand : public ICommand {
public:
    virtual ~GetDeviceByIndexCommand() = 0;

    IDevice* device;
};