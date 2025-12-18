#ifndef ARMSECURITYCOMMAND_H
#define ARMSECURITYCOMMAND_H

#include "Command.h"
#include "IArmSecurityCommand.h"


class ArmSecurityCommand : public Command, public IArmSecurityCommand {
public:
    ArmSecurityCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    ~ArmSecurityCommand() {}

    void execute() {
        printf("Executing ArmSecurityCommand: Security system activated.\n");
        securityManager->setIsSystemArmed(true);
        logger->writeLog("Security", "System Armed.");
    }
};
#endif 