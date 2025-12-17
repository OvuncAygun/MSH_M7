#ifndef CHANGESTATECOMMAND_H
#define CHANGESTATECOMMAND_H

#include "Command.h"
#include "IChangeStateCommand.h"
#include "IState.h"

class ChangeStateCommand : public Command, public IChangeStateCommand {
public:
    ChangeStateCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        IState* state)
        : Command(dm, mm, sm, l, secM) {
    }

    ~ChangeStateCommand() {}

    void execute() {
        if (newState == NULL) { // C++98 i�in NULL kontrol�
            printf("ERROR: New state is null!\n");
            return;
        }

        printf("Executing ChangeState: Setting to %s\n", newState->getName().c_str());

        // State Manager'a referans �zerinden aktar�m
        stateManager->setState(*newState);

        logger->writeLog("ChangeState", "New State: " + newState->getName());
    }
};
#endif 