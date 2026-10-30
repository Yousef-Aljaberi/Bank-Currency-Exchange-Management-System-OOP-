<div align="center">

# 🏦 & 💱 Bank & Currency Exchange Management System

**A comprehensive, enterprise-grade C++ console ecosystem featuring advanced Object-Oriented Programming, secure access controls, transaction logging, and robust file-based persistence.**

<p>
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue.svg?style=flat-square&logo=c%2B%2B" alt="C++">
  <img src="https://img.shields.io/badge/Paradigm-OOP-orange.svg?style=flat-square&logo=codewars" alt="Object-Oriented Programming">
  <img src="https://img.shields.io/badge/Interface-Console-lightgrey.svg?style=flat-square&logo=gnubash" alt="Console application">
  <img src="https://img.shields.io/badge/Storage-Flat%20Files-green.svg?style=flat-square&logo=files" alt="File-based storage">
  <img src="https://img.shields.io/badge/Architecture-Modular-purple.svg?style=flat-square" alt="Modular Architecture">
</p>

[Core Systems](#-core-systems) • [Architecture & Design](#️-architecture--design-patterns) • [Data Persistence](#-data-persistence) • [Getting Started](#-getting-started) • [Author](#-author--contact)

</div>

---

## 🌟 Executive Overview

Welcome to the **Bank Management & Currency Exchange System**! This project is a comprehensive C++ console application developed as part of my programming journey to apply Object-Oriented Programming (OOP) concepts, clean code practices, and modular system design.

The core idea was to build a complete financial management system from scratch—combining secure bank account operations with a multi-currency conversion engine—without relying on external libraries or databases. Every screen, business rule, and data model is organized into clean, reusable classes.

---

## 🚀 Core Systems

### 1. 🏦 Bank Management System (BMS)

A structured console module designed to manage client accounts, operator permissions, and core banking transactions securely.

- **Client Account Management:** Full CRUD operations (Create, Read, Update, Delete) with direct account balance tracking.
- **Financial Transactions:** Secure processing for deposits, withdrawals, and multi-account fund transfers with historical auditing.
- **User Permissions & Access Control:** Role-based permission system allowing administrators to configure access levels for system operators.
- **Activity & Audit Logging:** Automatic recording of login sessions (`LoginRegister.txt`) and transfer histories (`TransferLog.txt`).

**Key Classes:**

- `clsCurrency.h` — Currency data model, search algorithms, and cross-rate calculation logic.
- `clsCurrencyMenue.h` — Centralized navigation hub for currency tools.
- `Currencies.txt` — Pre-seeded flat-file dataset containing global exchange rates.
- 
### 2. 💱 Currency Exchange System

A dedicated financial module built to manage global currencies, lookup exchange rates, and compute cross-currency conversions using USD as a standard base.

- **Currencies Directory:** Displays formatted lists of global currencies, ISO codes, country names, and exchange rates (`clsCurrenciesListScreen.h`).
- **Flexible Search Engine:** Instant lookup by Currency Code (e.g., `EUR`, `GBP`) or Country Name (`clsFindCurrencyScreen.h`).
- **Rate Updating:** Administrative tool to modify and persist exchange rates (`clsUpdateCurrencyRateScreen.h`).
- **Currency Calculator:** Converts amounts between any two global currencies using USD as an intermediary base.

**Conversion Logic Formula:**
The system uses USD as the base currency to derive calculations:
$$\text{Target Amount} = \left(\frac{\text{Source Amount}}{\text{Source Rate}}\right) \times \text{Target Rate}$$

**Key Classes:**

- `clsCurrency.h` — Currency data model, search algorithms, and cross-rate calculation logic.
- `clsCurrencyMenue.h` — Centralized navigation hub for currency tools.
- `Currencies.txt` — Pre-seeded flat-file dataset containing global exchange rates.
- 
## 🏗️ Architecture & Design Patterns

The codebase adheres strictly to enterprise-level separation of concerns, ensuring that user interface logic remains entirely decoupled from core business execution and data storage layers.

```text
                 +--------------------------+
                 |    Interactive Menus     |
                 +--------------------------+
                              |
                 +--------------------------+
                 |    UI Screen Modules     |  (cls*Screen.h)
                 +--------------------------+
                              |
                 +--------------------------+
                 |   Business / Domain OOP  |  (clsBankClient.h, clsCurrency.h)
                 +--------------------------+
                              |
                 +--------------------------+
                 |  Validation & Utilities  |  (clsInputValidate.h, clsString.h)
                 +--------------------------+
                              |
                 +--------------------------+
                 | Flat-File Persistence IO |  (.txt Data Storage)
                 +--------------------------+
```

### Core Design Principles

- **Encapsulation:** State variables and operational methods are tightly bound within respective domain classes.
- **Inheritance :** User interfaces inherit shared layout rendering mechanisms from a robust base class (`clsScreen.h`).
- **Centralized Data Sanitization:** All user inputs are rigorously verified via `clsInputValidate` to mitigate invalid states, range errors, and buffer corruption.

---

## 🗄️ Data Persistence & Files

To maintain absolute independence from heavy external database engines, the project uses a customized **flat-file serialization protocol** utilizing the unique delimiter token `#//#`.

| File Path           | Description               | Contents                                                               |
| :------------------ | :------------------------ | :--------------------------------------------------------------------- |
| `Clients.txt`       | Core Bank Ledger          | Account numbers, PIN codes, client names, phone numbers, and balances. |
| `Users.txt`         | Security Database         | System operators, encrypted passphrases, and bitmasked permissions.    |
| `Currencies.txt`    | Global Market Asset Table | Country metadata, ISO codes, friendly names, and USD exchange rates.   |
| `TransferLog.txt`   | Financial Audit Trail     | Timestamped records of cross-account transfers.                        |
| `LoginRegister.txt` | Access History Log        | Login telemetry tracking system operator sessions.                     |

---

## ⚙️ Getting Started & Installation

### Prerequisites

Ensure you have a modern C++ compiler supporting **C++17** or higher installed on your machine:

- **Windows:** Visual Studio (MSVC)
- **Linux / macOS:** GCC / MinGW or Clang

### Quick Setup

1. **Clone the repository:**

   ```bash
   git clone https://github.com/Yousef-Aljaberi/Bank-Currency-Exchange-Management-System-OOP-.git
   cd Bank-Management-System-and-Currency-Exchange
   ```

2. **Open & Build via Visual Studio:**
   - Open the primary solution file (`.sln`) inside Visual Studio.
   - Verify that all required `.txt` data files reside within the working execution directory.
   - Build the solution (`Ctrl + Shift + B`) and launch the application (`F5`).

---

## 👤 Author

<div align="center">

### **Yousif Aljaberi**


[![GitHub](https://img.shields.io/badge/GitHub-Yousef--Aljaberi-181717?style=for-the-badge&logo=github)](https://github.com/Yousef-Aljaberi)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Yousif%20Aljaberi-0A66C2?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/yousif-aljaberi-004278408/)

</div>

---
