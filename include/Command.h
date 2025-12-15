
#ifndef COMMAND_H
#define COMMAND_H

#include "ICommand.h"
#include "../external/IDeviceManager.h"
#include "../external/IModeManager.h"
#include "../external/IStateManager.h"
#include "../external/ILogger.h"
#include "../external/ISecurityManager.h"
#include "../external/DeviceType.h"       
#include "Utility.h" // yardýmcý fonksiyon

// Command, tüm yöneticileri tutan soyut temel sýnýftýr.
class Command : public ICommand {
protected:
    // Tüm somut komutlarýn kullanacaðý yöneticiler
    IDeviceManager* deviceManager;
    IModeManager* modeManager;
    IStateManager* stateManager;
    ILogger* logger;
    ISecurityManager* securityManager;

public:
    // Kurucu: Tüm 5 yöneticiyi alýr (C++98)
    Command(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : deviceManager(dm), modeManager(mm), stateManager(sm), logger(l), securityManager(secM) {
    }

    virtual ~Command() {}
};

#endif 