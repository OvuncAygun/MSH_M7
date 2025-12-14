#pragma once

#include "ICommand.h"

class ArmSecurityCommand : public ICommand {
public:
    virtual ~ArmSecurityCommand() = 0;

    bool isSecurityArmed;
};