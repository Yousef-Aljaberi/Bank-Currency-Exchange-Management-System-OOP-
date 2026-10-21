<<<<<<< Updated upstream
<div align="center">

# 🏦  Bank Management System

<p align="center">
  <b>An enterprise-grade, multi-tier, console-based banking platform built with Modern C++.</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++11%2F17-blue.svg" alt="C++">
  <img src="https://img.shields.io/badge/Architecture-Multi--Tier-orange.svg" alt="Architecture">
  <img src="https://img.shields.io/badge/Security%20%26%20Bitmask-green.svg" alt="Security">
</p>

---

[✨ Overview](#-overview) •
[🏗️ System Architecture](#️-system-architecture) •
[🛡️ Security ](#️-security--role-based-access-control-rbac) •
[📂 Project Modules](#-project-modules) •
[🗄️ Data Persistence](#️-data-persistence-layer) •
[🚀 Getting Started](#-getting-started) •
[👤 Author & Contact](#-author--contact)

</div>

## ✨ Overview

The **Bank Management System** is a sophisticated, object-oriented console application engineered using professional software design principles. It enforces a strict **separation of concerns** by cleanly decoupling the **Presentation Layer** (UI screens and menus), the **Business Logic Layer** (domain entities and validation rules), and the **Data Access Layer** (flat-file persistence and cryptographic utilities).

The platform features secure administrative authentication, granular permission bitmasks, full client/user lifecycle management, high-precision financial transactions, and comprehensive immutable audit logging.

---

## 🏗️ System Architecture

The application follows a clean **Multi-Tier Layered Pattern** to ensure high maintainability, modularity, and scalability:

```text
 ┌────────────────────────────────────────────────────────┐
 │              Presentation Layer (UI Screens)           │
 │       clsMainScreen | clsTransactionsScreen | ...      │
 └──────────────────────────┬─────────────────────────────┘
                            │ Delegates Logic & Operations
 ┌──────────────────────────▼─────────────────────────────┐
 │                Business Logic Layer                    │
 │        clsBankClient  │  clsUser  │  clsPerson         │
 └──────────────────────────┬─────────────────────────────┘
                            │ Reads/Writes Persisted Data
 ┌──────────────────────────▼─────────────────────────────┐
 │                 Data Access Layer                      │
 │     Clients.txt │ Users.txt │ TransferLog.txt          │
 └────────────────────────────────────────────────────────┘
```

1. **Presentation Layer (`cls*Screen.h`)**: Governs console UI formatting, input prompts, routing menus, and security rights validation.
2. **Business Logic Layer (`clsBankClient.h`, `clsUser.h`)**: Encapsulates core banking rules, entity models, data mutation, and state management.
3. **Infrastructure & Utilities**: Provides robust foundational tools for calendar calculations, string parsing, defensive input sanitization, and data encryption.

---

## 🛡️ Security & Role-Based Access Control

Security is deeply integrated into the core architecture using a **Bitmask Permission System**:

| Permission Flag | Hex Value | Access Granted Area |
| :--- | :---: | :--- |
| `pListClients` | `1` | View all registered bank clients |
| `pAddNewClient` | `2` | Register new bank accounts |
| `pDeleteClient` | `4` | Remove client profiles |
| `pUpdateClients` | `8` | Modify client information |
| `pFindClient` | `16` | Search client registry |
| `pTranactions` | `32` | Handle deposits, withdrawals, and transfers |
| `pManageUsers` | `64` | Administrative user management portal |
| `pShowLoginRegister` | `128` | View historical system login audits |
| `pTransferLog` | `256` | View immutable financial transfer logs |
| `eAll` | `-1` | **Full Administrative Access (Superuser)** |

* **Account Lockout Protection:** The system automatically locks sessions after **3 consecutive failed authentication attempts**.
* **Credential Encryption:** Passwords and sensitive logs are securely encrypted and decrypted using built-in cryptographic mechanisms.

---

## 📂 Project Modules

* **Core Models & Entities**: Manages base identities (`clsPerson`), bank clients (`clsBankClient`), and system operators (`clsUser`).
* **Client Management Screens**: Full lifecycle handlers for listing, adding, updating, deleting, and searching clients.
* **Financial Transactions Subsystem**: Handles deposits, withdrawals, total liquidity tracking, peer-to-peer transfers, and immutable audit logs (`clsTransferLogScreen`).
* **User Administration Portal**: Complete operator management interface for configuring user credentials and permission bitmasks.

---

## 🗄️ Data Persistence Layer

The application utilizes optimized flat text files acting as a lightweight, zero-dependency database using custom hash delimiters (`#//#`):

* 📁 **`Clients.txt`**: Stores client profile records and current account balances.
* 📁 **`Users.txt`**: Stores system operator credentials, encrypted passwords, and permission bitmasks.
* 📁 **`TransferLog.txt`**: Maintains an immutable audit trail of all monetary asset transfers between accounts.
* 📁 **`LoginRegister.txt`**: Records historical authentication sessions with timestamps and operational permissions.

---

## 🚀 Getting Started

### 📋 Prerequisites
Ensure you have a modern C++ compiler supporting **C++11** or higher:
* **GCC / MinGW** (Linux / Windows)
* **Clang** (macOS / Linux)
* **MSVC** (Visual Studio - Windows)

### ⚙️ Compilation & Execution
Clone the repository and compile all source files directly via your terminal:
```bash
g++ -std=c++11 *.cpp -o BankManagementSystem
./BankManagementSystem
```

---

## 💡 Engineering Highlights

* **Object-Oriented Excellence:** Extensive use of inheritance, encapsulation, polymorphism, and C++ property syntaxes (`__declspec(property)`).
* **Defensive Programming:** Rigorous stream exception handling ensuring the console never crashes from invalid user inputs.
* **Audit Transparency:** Complete tracking history for both administrative logins and financial transactions.

---

## 👤 Author & Contact

<div align="center">

### **Yousef Aljaberi**
*Software Developer*

[![GitHub](https://img.shields.io/badge/GitHub-Yousef--Aljaberi-black?style=for-the-badge&logo=github)](https://github.com/Yousef-Aljaberi)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Yousif%20Aljaberi-blue?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/yousif-aljaberi-004278408/)

</div>
=======
>>>>>>> Stashed changes
