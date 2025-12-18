#ifndef CHANGESTATECOMMAND_H
#define CHANGESTATECOMMAND_H

#include "Command.h"
#include "IChangeStateCommand.h"
#include "IState.h"

class ChangeStateCommand : public Command, public IChangeStateCommand {
public:
    ChangeStateCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    ~ChangeStateCommand() {}

    void execute() {
        if (state == NULL) { // for C++98 checking null
            printf("ERROR: New state is null!\n");
            return;
        }

        printf("Executing ChangeState: Setting to %s\n", state->getName().c_str());


        stateManager->setState(*state);

        logger->writeLog("ChangeState", "New State: " + state->getName());
    }
};
#endif 