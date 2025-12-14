#ifndef NEXTSTATECOMMAND_H
#define NEXTSTATECOMMAND_H

#include "../Command.h"

class NextStateCommand : public Command {
public:
    NextStateCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    virtual ~NextStateCommand() {}

    virtual void execute() {
        printf("Executing NextStateCommand: Restoring next state...\n");
        stateManager->restoreNext();
        logger->writeLog("StateRestore", "Restored Next State");
    }
};
#endif // NEXTSTATECOMMAND_H