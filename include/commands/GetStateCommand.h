#pragma once

#include "ICommand.h"
#include "IState.h"

class GetStateCommand : public ICommand {
public:
    virtual ~GetStateCommand() = 0;

    IState* state;
};