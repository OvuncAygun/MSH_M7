#ifndef GETSTATECOMMAND_H
#define GETSTATECOMMAND_H

#include "../Command.h"
#include "../../external/IState.h"

class GetStateCommand : public Command {
private:
    IState** stateResult; // M8'deki IState* adresi

public:
    GetStateCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM, IState** res)
        : Command(dm, mm, sm, l, secM), stateResult(res) {
    }

    // 1. BURAYA EKLE: Sanal Yýkýcý (Destructor)
    // Bellek sýzýntýlarýný önlemek için her komutun kendi sanal yýkýcýsý olmalýdýr.
    virtual ~GetStateCommand() {}

    virtual void execute() {
        // 1. Mevcut durumu güvenli bir þekilde al
        IState* currentState = stateManager->getCurrentState();

        // 2. Modül 8'deki pointer'ý güncelle (Her zaman güvenli)
        if (stateResult != 0) {
            *stateResult = currentState;
        }

        // 3. NULL Kontrolü: Eðer state varsa logla ve yazdýr, yoksa uyar
        if (currentState != 0) {
            printf("Executing GetStateCommand: Current state is %s\n", currentState->getName().c_str());
            logger->writeLog("GetState", "Current State: " + currentState->getName());
        }
        else {
            // Çökme riskini önleyen güvenli çýkýþ
            printf("Executing GetStateCommand: WARNING - Current state is NULL!\n");
            logger->writeLog("GetState", "Warning: Current state is null.");
        }
    }
};
#endif