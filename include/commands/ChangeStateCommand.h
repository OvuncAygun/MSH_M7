#ifndef CHANGESTATECOMMAND_H
#define CHANGESTATECOMMAND_H

#include "../Command.h"
#include "../external/IState.h"

class ChangeStateCommand : public Command {
private:
    IState* newState; // M4'teki somut bir durum olmalý
public:
    ChangeStateCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM,
        IState* state)
        : Command(dm, mm, sm, l, secM), newState(state) {
    }

    virtual ~ChangeStateCommand() {}

    virtual void execute() {
        if (newState == NULL) { // C++98 için NULL kontrolü
            printf("ERROR: New state is null!\n");
            return;
        }

        printf("Executing ChangeState: Setting to %s\n", newState->getName().c_str());

        // State Manager'a referans üzerinden aktarým
        stateManager->setState(*newState);

        logger->writeLog("ChangeState", "New State: " + newState->getName());
    }
};
#endif 