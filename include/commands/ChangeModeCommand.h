#ifndef CHANGEMODECOMMAND_H
#define CHANGEMODECOMMAND_H

#include "../Command.h"

class ChangeModeCommand : public Command {
private:
    IModeStrategy* newMode; // M3'teki somut bir strateji olmalý
public:
    ChangeModeCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        IModeStrategy* mode)
        : Command(dm, mm, sm, l, secM), newMode(mode) {
    }

    virtual ~ChangeModeCommand() {}

    virtual void execute() {
        printf("Executing ChangeMode: Setting to %s\n", newMode->getModeName().c_str());
        modeManager->setMode(newMode);
        logger->writeLog("ChangeMode", "New Mode: " + newMode->getModeName());
    }
};
#endif // CHANGEMODECOMMAND_H