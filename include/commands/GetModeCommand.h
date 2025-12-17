#ifndef GETMODECOMMAND_H
#define GETMODECOMMAND_H

#include "../Command.h"
#include <string>

class GetModeCommand : public Command {
private:
    std::string* modeNameResult; // Modül 8'deki std::string deðiþkeninin adresi

public:
    // Constructor'a Modül 8'den gelecek olan adres parametresini ekledik
    GetModeCommand(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM, std::string* res)
        : Command(dm, mm, sm, l, secM), modeNameResult(res) {
    }

    virtual ~GetModeCommand() {}

    virtual void execute() {
        // IModeManager arayüzü üzerinden mevcut mod ismini alýyoruz
        std::string modeName = modeManager->getModeName();

        // Eðer bir sonuç adresi (pointer) saðlanmýþsa, Modül 8'in içindeki deðiþkeni güncelliyoruz
        if (modeNameResult != 0) {
            *modeNameResult = modeName;
        }

        printf("Executing GetModeCommand: Current Mode is %s\n", modeName.c_str());

        // Loglama iþlemi
        logger->writeLog("GetMode", "Current Mode: " + modeName);
    }
};
#endif