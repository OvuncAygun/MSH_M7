#ifndef GETMODECOMMAND_H
#define GETMODECOMMAND_H

#include "Command.h"
#include "IGetModeCommand.h"
#include <string>

class GetModeCommand : public Command, public IGetModeCommand {
public:
    // Constructor'a Mod�l 8'den gelecek olan adres parametresini ekledik
    GetModeCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : Command(dm, mm, sm, l, secM) {
    }

    ~GetModeCommand() {}

    void execute() {
        // IModeManager aray�z� �zerinden mevcut mod ismini al�yoruz
        std::string modeNameReturn = modeManager->getModeName();

        // E�er bir sonu� adresi (pointer) sa�lanm��sa, Mod�l 8'in i�indeki de�i�keni g�ncelliyoruz
        if (!modeNameReturn.empty()) {
            modeName = modeNameReturn;
        }

        printf("Executing GetModeCommand: Current Mode is %s\n", modeName.c_str());

        // Loglama i�lemi
        logger->writeLog("GetMode", "Current Mode: " + modeName);
    }
};
#endif