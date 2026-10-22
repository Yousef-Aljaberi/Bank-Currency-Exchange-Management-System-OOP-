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

Welcome to the **Bank Management & Currency Exchange System**, a sophisticated multi-module C++ solution engineered for high reliability, clean architectural separation, and seamless user interaction. Built entirely from scratch using robust **Object-Oriented Programming (OOP)** principles, this project unifies secure retail banking operations and multi-currency exchange management into a single, cohesive console application.

Designed with scalability in mind, every screen, business rule, and data model is isolated into clean, reusable classes. It serves as an exemplary showcase of modern C++ system design, data validation, and custom string parsing without external dependencies.

---

## 🚀 Core Systems

### 1. 🏦 Bank Management System (BMS)

A comprehensive backend-style banking administrative engine designed to manage high-integrity client accounts, granular user security permissions, and core ledger transactions.

- **Client Portfolio Control:** Complete CRUD operations (Create, Read, Update, Delete) with instant account balance tracking.
- **Financial Ledger Transactions:** Secure processing for deposits, withdrawals, and multi-account fund transfers with complete historical auditing.
- **Granular Role & Access Control (RBAC):** Bitmask-style permission flags allowing administrators to configure custom access levels for individual system operators.
- **Activity & Audit Logging:** Automatic recording of login attempts (`LoginRegister.txt`) and transfer histories (`TransferLog.txt`) for complete operational transparency.

**Key Structural Modules:**

- `clsBankClient.h` — Core client entity handling validation, balance alterations, and record serialization.
- `clsUser.h` — Operator credential management, authentication, and access permission matrices.
- `clsMainScreen.h` & Associated `cls*Screen.h` — Modular routing screens for menus, client lookup, and transactional workflows.

---

### 2. 💱 Currency Exchange & Management System

An advanced financial conversion module capable of querying global currencies, adjusting live valuation rates, and executing cross-currency computations relative to USD.

- **Currencies Listing Matrix:** Renders beautifully formatted tabular data detailing countries, ISO currency codes, human-readable names, and base conversion rates against 1 USD (`clsCurrenciesListScreen.h`).
- **Multi-Parameter Search Engine:** Instant lookup mechanism supporting queries by unique Currency Code (e.g., `EUR`, `GBP`, `JPY`) or full Country Name (`clsFindCurrencyScreen.h`).
- **Dynamic Rate Updating:** Secure administrative override capability to modify live currency exchange rates with instant file persistence (`clsUpdateCurrencyRateScreen.h`).
- **Cross-Currency Exchange Calculator:** Intelligent calculation pipeline routing all conversions through USD as an intermediary base currency to compute accurate values between any two global assets (`clsCurrencyCalculaterScreen.h`).

**The Conversion Logic Formula:**
The system uses USD as the universal pivot currency to derive calculations:
$$\text{Target Amount} = \left(\frac{\text{Source Amount}}{\text{Source Rate}}\right) \times \text{Target Rate}$$

**Key Structural Modules:**

- `clsCurrency.h` — Core currency model housing serialization logic, search algorithms, and cross-rate math.
- `clsCurrencyMenue.h` — Centralized navigation hub routing users seamlessly across conversion tools.
- `Currencies.txt` — Pre-seeded flat-file database populated with extensive global exchange statistics.

---

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
- **Inheritance & Polymorphism:** User interfaces inherit shared layout rendering mechanisms from a robust base class (`clsScreen.h`).
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

3. **Terminal Compilation (GCC Example):**
   ```bash
   g++ -std=c++17 *.cpp -o BankSystem
   ./BankSystem
   ```

---

## 🔐 Security & Production Disclaimer

- **Data Security:** Flat-file data persistence is structured primarily for performance, learning, and architectural elegance. Production deployment demands standard relational or NoSQL database implementation with encrypted storage.
- **Financial Calculations:** Currency rates are stored locally and initialized via dataset files; verify real-time market feeds externally before running production-level monetary transactions.

---

## 👤 Author

<div align="center">

### **Yousif Aljaberi**

_Software Developer_

[![GitHub](https://img.shields.io/badge/GitHub-Yousef--Aljaberi-181717?style=for-the-badge&logo=github)](https://github.com/Yousef-Aljaberi)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Yousif%20Aljaberi-0A66C2?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/yousif-aljaberi-004278408/)

</div>

---

<div align="center">

**Powered by robust C++ • Delivering clean, modular, and object-oriented software**

</div>
