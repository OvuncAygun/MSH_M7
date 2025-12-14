#include "../include/MSH_M7.h" 
#include <iostream>
#include <string>

// --- Statik Üye Baþlatma ---
// C++98 kuralý
MenuCommandManager* MenuCommandManager::instance = 0;

// --- Yýkýcý Uygulamasý (VCR0001 çözümü) ---
MenuCommandManager::~MenuCommandManager() {
    std::map<std::string, ICommand*>::iterator it;
    for (it = commandMap.begin(); it != commandMap.end(); ++it) {
        delete it->second;
    }
}

// --- Singleton Eriþim (VCR0001 çözümü) ---
MenuCommandManager* MenuCommandManager::getInstance() {
    if (instance == 0) {
        instance = new MenuCommandManager();
    }
    return instance;
}

// --- Yönetici Baþlatma ---
void MenuCommandManager::initialize(IDeviceManager* dm, IModeManager* mm, IStateManager* sm, ILogger* l, ISecurityManager* secM) {
    deviceManager = dm;
    modeManager = mm;
    stateManager = sm;
    logger = l;
    securityManager = secM;
    printf("Menu Command Manager initialized successfully.\n");
}

// --- Komut Kaydetme ---
void MenuCommandManager::registerCommand(const std::string& key, ICommand* command) {
    commandMap[key] = command;
}

// --- Komut Yürütme ---
bool MenuCommandManager::executeCommand(const std::string& key) {
    std::map<std::string, ICommand*>::iterator it = commandMap.find(key);

    if (it != commandMap.end()) {
        it->second->execute();
        return true;
    }
    else {
        std::cout << "ERROR: Unknown command '" << key << "'.\n";
        return true;
    }
}

// --- Menü Gösterme ---
void MenuCommandManager::displayMenu() const {
    std::cout << "\n--- MSH MENU ---\n";
    printf("[1] Get Home Status\n");
    // ...
    printf("[10] Shutdown\n");
}

// --- Singleton Kýsýtlayýcýlarýnýn Uygulanmasý (VCR0001 ve C26495 çözümü) ---

// 1. Kopyalama Kurucusu: C26495 Uyarýsýný çözmek için tüm üyeler baþlatýlmalýdýr.
// C++98'de, bu fonksiyonun gövdesi .cpp'de olmalýdýr (VCR0001 çözümü).
MenuCommandManager::MenuCommandManager(const MenuCommandManager& other)
    : deviceManager(0), modeManager(0), stateManager(0), logger(0), securityManager(0)
{
    // Yalnýzca tanýmýný saðlarýz, fonksiyonun içeriði boþ kalýr.
}

// 2. Atama Operatörü: VCR0001 çözümü
MenuCommandManager& MenuCommandManager::operator=(const MenuCommandManager& other) {
    return *this;
}