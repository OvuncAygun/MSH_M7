#pragma once

#include "ICommand.h"
#include "IState.h"

class NextStateCommand : public ICommand {
public:
    virtual ~NextStateCommand() = 0;

    IState* state;
};