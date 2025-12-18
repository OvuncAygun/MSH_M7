#ifndef ICHANGEMODECOMMAND_H
#define ICHANGEMODECOMMAND_H

#include "ICommand.h"
#include "IModeStrategy.h"

class IChangeModeCommand : public virtual ICommand {
public:
    virtual ~IChangeModeCommand() = 0;

    IModeStrategy* mode;

    virtual void execute() = 0;
};
#endif 