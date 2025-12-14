#pragma once

#include "ICommand.h"
#include "IDevice.h"

class PoweroffDeviceCommand : public ICommand {
public:
    virtual ~PoweroffDeviceCommand() = 0;

    IDevice* device;
};