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

    // 1. BURAYA EKLE: Sanal Y�k�c� (Destructor)
    // Bellek s�z�nt�lar�n� �nlemek i�in her komutun kendi sanal y�k�c�s� olmal�d�r.
    ~GetStateCommand() {}

    void execute() {
        // 1. Mevcut durumu g�venli bir �ekilde al
        IState* currentState = stateManager->getCurrentState();

        // 2. Mod�l 8'deki pointer'� g�ncelle (Her zaman g�venli)
        if (state != 0) {
            state = currentState;
        }

        // 3. NULL Kontrol�: E�er state varsa logla ve yazd�r, yoksa uyar
        if (currentState != 0) {
            printf("Executing GetStateCommand: Current state is %s\n", currentState->getName().c_str());
            logger->writeLog("GetState", "Current State: " + currentState->getName());
        }
        else {
            // ��kme riskini �nleyen g�venli ��k��
            printf("Executing GetStateCommand: WARNING - Current state is NULL!\n");
            logger->writeLog("GetState", "Warning: Current state is null.");
        }
    }
};
#endif