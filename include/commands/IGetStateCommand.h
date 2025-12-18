#ifndef IGETSTATECOMMAND_H
#define IGETSTATECOMMAND_H

#include "ICommand.h"
#include "IState.h"

class IGetStateCommand : public ICommand {
public:
    // Virtual Destructor
    // To prevent memory leaks, each instruction must have its own virtual unloader.
    virtual ~IGetStateCommand() = 0;

    IState** stateResult; // The IState* address is on M8.

    virtual void execute() = 0;
};
#endif