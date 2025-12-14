#ifndef GETMODECOMMAND_H
#define GETMODECOMMAND_H

#include "../Command.h"

class GetModeCommand : public Command {
public:
    GetModeCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    virtual ~GetModeCommand() {}

    virtual void execute() {
        std::string modeName = modeManager->getModeName();
        printf("Executing GetModeCommand: Current Mode is %s\n", modeName.c_str());
        logger->writeLog("GetMode", "Current Mode: " + modeName);
    }
};
#endif // GETMODECOMMAND_H