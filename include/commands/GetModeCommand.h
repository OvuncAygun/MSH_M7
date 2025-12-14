#pragma once

#include "ICommand.h"
#include "IModeStrategy.h"

class GetModeCommand : public ICommand {
public:
    virtual ~GetModeCommand() = 0;

    IModeStrategy* mode;
};