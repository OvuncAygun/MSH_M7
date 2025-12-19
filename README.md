# My Sweet Home (MSH) - Smart Home Management System

![Project Status](https://img.shields.io/badge/Status-Completed-success)
![Standard](https://img.shields.io/badge/Standard-C%2B%2B98-blue)
![Architecture](https://img.shields.io/badge/Architecture-Modular-orange)

**My Sweet Home (MSH)** is a high-integrity, modular smart home management system designed with a centralized architecture to manage devices, security, and environmental modes. It focuses on clean code principles and the implementation of advanced architectural design patterns.

---

## 🛠 Project Roadmap & Phases
The development followed a rigorous 5-phase engineering lifecycle:
1.  **Analysis:** Ensuring full traceability from High-Level Requirements (HLR) to Low-Level Requirements (LLR).
2. **API Definition:** Enforcing the "Dependency Inversion" principle through abstract interfaces.
3.  **Core Logic:** Development of Strategy and Memento-based managers for dynamic configurations.
4.  **Integration:** Orchestrating commands and emergency security chains.
5.  **Validation:** Scenario-based system testing to verify compliance.

---

## Module 7: Command & Menu Orchestration (My Role)
As the owner of Module 7, I implemented the system's "Control Center," serving as the bridge between user interaction and backend execution logic.

### Key Responsibilities:
* **CLI Implementation:** Developed the main Command Line Interface for real-time user interaction.
* **Command Encapsulation:** Converted system requests into stand-alone `ICommand` objects.
* **Centralized Registry:** Built a `MenuCommandManager` (Singleton) for dynamic command lifecycle management.
* **Cross-Module Sync:** Utilized "Double Pointer" (**) Result Holders for asynchronous data sharing with the Orchestrator (M8).

### Design Patterns Applied:
* **Command Pattern:** Decouples UI requests from manager logic.
* **Singleton Pattern:** Provides a single, centralized source of truth for command execution.
* **Strategy Pattern:** Enables runtime switching of system modes through `IModeStrategy`.
* **Template Method:** Maintains modularity and a standardized flow for menu actions.



---

## Engineering Challenges & Solutions

### 1. Manual Memory Management (C++98)
Due to the lack of modern smart pointers, we implemented deep-cleaning destructors in our managers to traverse polymorphic objects and prevent memory leaks.

### 2. Breaking Circular Dependencies
To prevent headers from recursively including each other, we utilized **Forward Declarations** and **Abstract Interfaces** instead of direct includes.

### 3. Cross-Platform Build Compatibility
Resolved OS-level inconsistencies by refactoring `CMakeLists.txt` for universal paths and creating platform-independent timing wrappers.

---

## Architectural Overview
The system is divided into 8 specialized modules:
* **M1-M2:** Device Core & Management.
* **M3-M4:** Mode & State Strategy.
* **M5-M6:** Logging, Security & Emergency Chains.
* **M7: Menu & Command Orchestration**.
* **M8:** System Orchestrator.



---

## Getting Started
1.  **Prerequisites:** CMake 3.10+ and a C++98 compliant compiler.
2.  **Build:**
    ```bash
    mkdir build && cd build
    cmake ..
    make
    ```
3.  **Run:** Execute the generated binary to enter the CLI and manage your smart home.

---
*Developed as a collaborative effort by the My Sweet Home (MSH) project team.*
