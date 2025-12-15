#ifndef MSH_M7_H
#define MSH_M7_H

#include "ICommand.h"
#include "../external/IDeviceManager.h" 
#include "../external/IModeManager.h"
#include "../external/IStateManager.h"
#include "../external/ILogger.h"
#include "../external/ISecurityManager.h"
#include <map>
#include <string>
#include <cstdio>

// Modül 8: MenuCommandManager (Singleton)
class MenuCommandManager {
private:
    static MenuCommandManager* instance;
    std::map<std::string, ICommand*> commandMap;

    IDeviceManager* deviceManager;
    IModeManager* modeManager;
    IStateManager* stateManager;
    ILogger* logger;
    ISecurityManager* securityManager;

    MenuCommandManager()
        : deviceManager(0), modeManager(0), stateManager(0), logger(0), securityManager(0) {
    }

    // Singleton C++98 Kurallarý
    ~MenuCommandManager();
    MenuCommandManager(const MenuCommandManager&);
    MenuCommandManager& operator=(const MenuCommandManager&);

public:
    static MenuCommandManager* getInstance();

    void initialize(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM);
    void registerCommand(const std::string& key, ICommand* command);
    bool executeCommand(const std::string& key);
    void displayMenu() const;

    // Command nesneleri oluþturulurken kullanýlmak üzere tüm yöneticilere eriþim saðlar
    IDeviceManager* getDeviceManager() const { return deviceManager; }
    IModeManager* getModeManager() const { return modeManager; }
    IStateManager* getStateManager() const { return stateManager; }
    ILogger* getLogger() const { return logger; }
    ISecurityManager* getSecurityManager() const { return securityManager; }
};

#endif 