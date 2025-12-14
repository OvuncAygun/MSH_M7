#pragma once

#include "ICommand.h"
#include "IDevice.h"

class RemoveDeviceCommand : public ICommand {
public:
    virtual ~RemoveDeviceCommand() = 0;

    IDevice* device;
};