#ifndef CHANGEMODECOMMAND_H
#define CHANGEMODECOMMAND_H

#include "Command.h"
#include "IChangeModeCommand.h"

class ChangeModeCommand : public Command, public IChangeModeCommand {
public:
    ChangeModeCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        IModeStrategy* mode)
        : Command(dm, mm, sm, l, secM) {}

    ~ChangeModeCommand() {}

    void execute() {
        printf("Executing ChangeMode: Setting to %s\n", newMode->getModeName().c_str());
        modeManager->setMode(newMode);
        logger->writeLog("ChangeMode", "New Mode: " + newMode->getModeName());
    }
};
#endif 