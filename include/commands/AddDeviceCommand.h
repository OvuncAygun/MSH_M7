#pragma once

#include "ICommand.h"
#include "DeviceType.h"

#include <string>
#include <vector>

class AddDeviceCommand : public ICommand {
public:
    virtual ~AddDeviceCommand() = 0;

    DeviceType deviceType;
    std::string name;
    std::vector<std::string> config;
    int count;
};