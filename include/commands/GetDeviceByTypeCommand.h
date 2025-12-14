#pragma once

#include "ICommand.h"
#include "IDevice.h"
#include "DeviceType.h"

#include <vector>

class GetDeviceByTypeCommand : public ICommand {
public:
    virtual ~GetDeviceByTypeCommand() = 0;

    std::vector<IDevice*> devices;
    DeviceType deviceType;
};