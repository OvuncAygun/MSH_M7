#ifndef ARMSECURITYCOMMAND_H
#define ARMSECURITYCOMMAND_H

#include "../Command.h"

class ArmSecurityCommand : public Command {
public:
    ArmSecurityCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    virtual ~ArmSecurityCommand() {}

    virtual void execute() {
        // Bu komut, M6'daki SecurityManager'ý aktifleþtirir.
        printf("Executing ArmSecurityCommand: Security system activated.\n");
     //   securityManager->armSystem(); // Varsayýmsal metod but bu hata verdi deðiþtirdim.
        securityManager->setIsSystemArmed(true);
        logger->writeLog("Security", "System Armed.");
    }
};
#endif // ARMSECURITYCOMMAND_H