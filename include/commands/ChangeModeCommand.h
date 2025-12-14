#pragma once

#include "ICommand.h"
#include "IModeStrategy.h"

class ChangeModeCommand : public ICommand {
public:
    virtual ~ChangeModeCommand() = 0;

    IModeStrategy* mode;
};