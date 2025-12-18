#ifndef ICHANGESTATECOMMAND_H
#define ICHANGESTATECOMMAND_H

#include "ICommand.h"
#include "IState.h"

class IChangeStateCommand : public virtual ICommand {
public:
    virtual ~IChangeStateCommand() = 0;

    IState* state;

    virtual void execute() = 0;
};
#endif 