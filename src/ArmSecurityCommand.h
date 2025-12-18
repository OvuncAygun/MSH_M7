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
     // This command activates the SecurityManager on M6.
        printf("Executing ArmSecurityCommand: Security system activated.\n");
     // securityManager->armSystem(); The hypothetical method gave an error, so I changed it.
        securityManager->setIsSystemArmed(true);
        logger->writeLog("Security", "System Armed.");
    }
};
#endif 