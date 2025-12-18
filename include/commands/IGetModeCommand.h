#ifndef IGETMODECOMMAND_H
#define IGETMODECOMMAND_H

#include "ICommand.h"
#include <string>
#include "IModeStrategy.h"

class IGetModeCommand : public virtual ICommand {
public:
    virtual ~IGetModeCommand() = 0;

    std::string modeName; // Mod�l 8'deki std::string de�i�keninin adresi

    virtual void execute() = 0;
};
#endif