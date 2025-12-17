#include "MSH_M7.h" 
#include <iostream>
#include <string>

MenuCommandManager* MenuCommandManager::instance = 0;

// Varsay�lan Kurucu Tan�m� (C2084 ��z�m�)
MenuCommandManager::MenuCommandManager()
    : deviceManager(0), modeManager(0), stateManager(0), logger(0), securityManager(0),
    lastFoundDevice(0), lastFoundState(0), lastFoundModeName("") //
{
}

// --- Y�k�c� Uygulamas� (Geli�tirilmi� Versiyon) ---
MenuCommandManager::~MenuCommandManager() {
    // 1. Kay�tl� komut nesnelerini temizle
    std::map<std::string, ICommand*>::iterator it;
    for (it = commandMap.begin(); it != commandMap.end(); ++it) {
        delete it->second; // Her bir komut nesnesini siler
    }
    commandMap.clear();

    // 2. Kendisine emanet edilen Manager nesnelerini temizle
    // Not: Bu nesneler d��ar�da 'new' ile olu�turulup initialize ile verildiyse silinmelidir.
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
        it->second->execute(); // Bu �a�r� M7 komutlar�n� �al��t�r�r ve M8 verilerini g�nceller.
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

// Singleton K�s�tlay�c�lar� (C2264 ��z�m�)
MenuCommandManager::MenuCommandManager(const MenuCommandManager& other)
    : deviceManager(0), modeManager(0), stateManager(0), logger(0), securityManager(0),
    lastFoundDevice(0), lastFoundState(0), lastFoundModeName("")
{
}

MenuCommandManager& MenuCommandManager::operator=(const MenuCommandManager& other) {
    return *this;
}