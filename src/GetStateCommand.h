#ifndef GETSTATECOMMAND_H
#define GETSTATECOMMAND_H

#include "Command.h"
#include "IGetStateCommand.h"
#include "IState.h"

class GetStateCommand : public Command, public IGetStateCommand {
public:
    GetStateCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    ~GetStateCommand() {}

    void execute() {
        IState* currentState = stateManager->getCurrentState();

        if (state != 0) {
            state = currentState;
        }

        if (currentState != 0) {
            //printf("Executing GetStateCommand: Current state is %s\n", currentState->getName().c_str());
            logger->writeLog("GetState", "Current State: " + currentState->getName());
        }
        else {
            //printf("Executing GetStateCommand: WARNING - Current state is NULL!\n");
            logger->writeLog("GetState", "Warning: Current state is null.");
        }
    }
};
#endif