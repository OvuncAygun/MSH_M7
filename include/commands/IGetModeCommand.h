#ifndef IGETMODECOMMAND_H
#define IGETMODECOMMAND_H

#include "ICommand.h"
#include <string>

class IGetModeCommand : public ICommand {
public:
    virtual ~IGetModeCommand() = 0;

    std::string* modeNameResult; // The address of the std::string variable in Module 8.

    virtual void execute() = 0;
};
#endif