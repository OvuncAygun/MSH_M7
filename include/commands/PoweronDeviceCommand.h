#pragma once

#include "ICommand.h"
#include "IDevice.h"

class PowerOnDeviceCommand : public ICommand {
public:
    virtual ~PowerOnDeviceCommand() = 0;

    IDevice* device;
};