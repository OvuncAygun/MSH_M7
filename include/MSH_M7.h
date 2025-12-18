#ifndef MSH_M7_H
#define MSH_M7_H

#include "ICommand.h"
#include "../external/IDeviceManager.h" 
#include "../external/IModeManager.h"
#include "../external/IStateManager.h"
#include "../external/ILogger.h"
#include "../external/ISecurityManager.h"
#include "../external/IDevice.h" 
#include <map>
#include <string>
#include <vector> 
#include <cstdio>

class MenuCommandManager {
private:
    static MenuCommandManager* instance;
    std::map<std::string, ICommand*> commandMap;

    IDeviceManager* deviceManager;
    IModeManager* modeManager;
    IStateManager* stateManager;
    ILogger* logger;
    ISecurityManager* securityManager;

    // --- Result Holders: Module 7 commands data
    IDevice* lastFoundDevice;       
    IState* lastFoundState;         
    std::string lastFoundModeName;  
    std::vector<IDevice*> lastDeviceList; 

    // error delete { }, only ; 
    MenuCommandManager();

    ~MenuCommandManager();
    MenuCommandManager(const MenuCommandManager&);
    MenuCommandManager& operator=(const MenuCommandManager&);

public:
    static MenuCommandManager* getInstance();
    
    static void releaseInstance() {
         if (instance != 0) {
             delete instance;
         instance = 0;
    }
}
    void initialize(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM);
    void registerCommand(const std::string& key, ICommand* command);
    bool executeCommand(const std::string& key);
    void displayMenu() const;

    // --- Result Accessors ---
    IDevice** getLastDevicePtr() { return &lastFoundDevice; }
    IState** getLastStatePtr() { return &lastFoundState; }
    std::string* getLastModeNamePtr() { return &lastFoundModeName; }
    std::vector<IDevice*>* getLastDeviceListPtr() { return &lastDeviceList; }

    IDeviceManager* getDeviceManager() const { return deviceManager; }
    IModeManager* getModeManager() const { return modeManager; }
    IStateManager* getStateManager() const { return stateManager; }
    ILogger* getLogger() const { return logger; }
    ISecurityManager* getSecurityManager() const { return securityManager; }
};

#endif