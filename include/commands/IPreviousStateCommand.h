#ifndef IPREVIOUSSTATECOMMAND_H
#define IPREVIOUSSTATECOMMAND_H

#include "ICommand.h"

class IPreviousStateCommand : public virtual ICommand {
public:
    virtual ~IPreviousStateCommand() = 0;

    virtual void execute() = 0;
};
#endif 