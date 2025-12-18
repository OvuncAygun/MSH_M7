#include "MSH_M7.h" 
#include <iostream>
#include <string>

MenuCommandManager* MenuCommandManager::instance = 0;

MenuCommandManager::MenuCommandManager()
    : deviceManager(0), modeManager(0), stateManager(0), logger(0), securityManager(0),
    lastFoundDevice(0), lastFoundState(0), lastFoundModeName("") 
{
}

MenuCommandManager::~MenuCommandManager() {

    std::map<std::string, ICommand*>::iterator it;
    for (it = commandMap.begin(); it != commandMap.end(); ++it) {
        delete it->second; 
    }
    commandMap.clear();

    if (deviceManager) { delete deviceManager; deviceManager = 0; }
    if (modeManager) { delete modeManager; modeManager = 0; }
    if (stateManager) { delete stateManager; stateManager = 0; }
    if (logger) { delete logger; logger = 0; }
    if (securityManager) { delete securityManager; securityManager = 0; }

    printf("MenuCommandManager: All managers and commands cleaned up.\n");
}

MenuCommandManager* MenuCommandManager::getInstance() {
    if (instance == 0) {
        instance = new MenuCommandManager();
    }
    return instance;
}


void MenuCommandManager::initialize(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM) {
    deviceManager = dm;
    modeManager = mm;
    stateManager = sm;
    logger = l;
    securityManager = secM;
    printf("Menu Command Manager initialized successfully.\n");
}

void MenuCommandManager::registerCommand(const std::string& key, ICommand* command) {
    commandMap[key] = command;
}

bool MenuCommandManager::executeCommand(const std::string& key) {
    std::map<std::string, ICommand*>::iterator it = commandMap.find(key);

    if (it != commandMap.end()) {
        it->second->execute(); 
        return true;
    }
    else {
        std::cout << "ERROR: Unknown command '" << key << "'.\n";
        return false;
    }
}

void MenuCommandManager::displayMenu() const {
    std::cout << "\n--- MSH MENU ---\n";
    printf("[1] Get Home Status\n");
    printf("[10] Shutdown\n");
}

MenuCommandManager::MenuCommandManager(const MenuCommandManager& other)
    : deviceManager(0), modeManager(0), stateManager(0), logger(0), securityManager(0),
    lastFoundDevice(0), lastFoundState(0), lastFoundModeName("")
{
}

MenuCommandManager& MenuCommandManager::operator=(const MenuCommandManager& other) {
    return *this;
}