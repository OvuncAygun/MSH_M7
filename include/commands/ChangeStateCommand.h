#pragma once

#include "ICommand.h"
#include "IState.h"

class ChangeStateCommand : public ICommand {
public:
    virtual ~ChangeStateCommand() = 0;

    IState* state;
};