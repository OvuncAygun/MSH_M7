
#ifndef COMMAND_H
#define COMMAND_H

#include "ICommand.h"
#include "IDeviceManager.h"
#include "IModeManager.h"
#include "IStateManager.h"
#include "ILogger.h"
#include "ISecurityManager.h"
#include "DeviceType.h"       
#include "Utility.h" // yard�mc� fonksiyon

// Command, t�m y�neticileri tutan soyut temel s�n�ft�r.
class Command : public ICommand {
protected:
    // T�m somut komutlar�n kullanaca�� y�neticiler
    IDeviceManager* deviceManager;
    IModeManager* modeManager;
    IStateManager* stateManager;
    ILogger* logger;
    ISecurityManager* securityManager;

public:
    // Kurucu: T�m 5 y�neticiyi al�r (C++98)
    Command(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM)
        : deviceManager(dm), modeManager(mm), stateManager(sm), logger(l), securityManager(secM) {
    }

    virtual ~Command() {}
};

#endif 