#ifndef ICHANGESTATECOMMAND_H
#define ICHANGESTATECOMMAND_H

#include "ICommand.h"
#include "IState.h"

class IChangeStateCommand : public ICommand {
public:
    virtual ~IChangeStateCommand() = 0;

    IState* newState; // There is a concrete (somut) situation on the M4.

    virtual void execute() = 0;
};
#endif 