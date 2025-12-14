#pragma once

#include "ICommand.h"
#include "IState.h"

class PreviousStateCommand : public ICommand {
public:
    virtual ~PreviousStateCommand() = 0;

    IState* state;
};