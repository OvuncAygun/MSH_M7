#ifndef GETMODECOMMAND_H
#define GETMODECOMMAND_H

#include "Command.h"
#include "IGetModeCommand.h"
#include "IModeStrategy.h"
#include <string>

class GetModeCommand : public Command, public IGetModeCommand {
public:
    GetModeCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    ~GetModeCommand() {}

    void execute() {
        std::string modeNameReturn = modeManager->getModeName();

        if (!modeNameReturn.empty()) {
            modeName = modeNameReturn;
        }

        printf("Executing GetModeCommand: Current Mode is %s\n", modeName.c_str());

        logger->writeLog("GetMode", "Current Mode: " + modeName);
    }
};
#endif