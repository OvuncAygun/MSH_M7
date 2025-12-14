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
        printf("Executing ChangeState: Setting to %s\n", newState->getName().c_str());
    //    stateManager->setState(newState);
        // ChangeStateCommand.h, Satýr 20 (Düzeltilmiþ Kod)
        stateManager->setState(*newState);
        logger->writeLog("ChangeState", "New State: " + newState->getName());
    }
};
#endif // CHANGESTATECOMMAND_H