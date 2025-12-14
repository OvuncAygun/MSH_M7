#ifndef PREVIOUSSTATECOMMAND_H
#define PREVIOUSSTATECOMMAND_H

#include "../Command.h"

class PreviousStateCommand : public Command {
public:
    PreviousStateCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    virtual ~PreviousStateCommand() {}

    virtual void execute() {
        printf("Executing PreviousStateCommand: Restoring previous state...\n");
        stateManager->restorePrev();
        logger->writeLog("StateRestore", "Restored Previous State");
    }
};
#endif // PREVIOUSSTATECOMMAND_H