#ifndef GETSTATECOMMAND_H
#define GETSTATECOMMAND_H

#include "../Command.h"
#include "../external/IState.h"

class GetStateCommand : public Command {
public:
    GetStateCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    virtual ~GetStateCommand() {}

    virtual void execute() {
        IState* currentState = stateManager->getCurrentState();
        std::string stateName = currentState->getName();
        printf("Executing GetStateCommand: Current State is %s\n", stateName.c_str());
        logger->writeLog("GetState", "Current State: " + stateName);
    }
};
#endif // GETSTATECOMMAND_H