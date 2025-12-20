#ifndef NEXTSTATECOMMAND_H
#define NEXTSTATECOMMAND_H

#include "Command.h"
#include "INextStateCommand.h"

class NextStateCommand : public Command, public INextStateCommand {
public:
    NextStateCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    ~NextStateCommand() {}

    void execute() {
        //printf("Executing NextStateCommand: Restoring next state...\n");
        stateManager->restoreNext();
        logger->writeLog("StateRestore", "Restored Next State");
    }
};
#endif 