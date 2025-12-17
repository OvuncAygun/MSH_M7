#ifndef ADDDEVICECOMMAND_H
#define ADDDEVICECOMMAND_H

#include "ICommand.h"
#include "DeviceCreationType.h"

#include <string>
#include <vector>

class IAddDeviceCommand : public ICommand {
public:
    virtual ~IAddDeviceCommand() = 0;

    DeviceCreationType deviceCreationType;
    std::string name;
    std::vector<std::string> config;
    int count;

    virtual void execute() = 0;

    
};

#endif