# 📒 Address Book Application

> A terminal-based Address Book Management System written in pure C with file persistence, modular programming, contact validation, and interactive CLI menus.

![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Build](https://img.shields.io/badge/Build-GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white)
![Storage](https://img.shields.io/badge/Storage-CSV-blue?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

---

# 📌 What is this Project?

The Address Book Application is a menu-driven terminal application developed using the C programming language.

It allows users to:

- Create contacts
- Search contacts
- Edit contact details
- Delete contacts
- List all contacts
- Save contacts permanently using CSV file handling

The application demonstrates core system programming concepts such as:

- Structures
- File handling
- Modular programming
- Input validation
- String handling
- Dynamic menu systems

---

# 🗂️ Project Structure

```text
AddressBook-Application/
├── main.c          # Main menu system and navigation
├── contact.c       # Contact operations and validation logic
├── contact.h       # Structures, constants, function declarations
├── file.c          # File save/load operations
├── file.h          # File handling declarations
├── populate.c      # Dummy contact population
├── populate.h      # Populate function declaration
├── Makefile        # Build automation
├── contact.csv     # Persistent contact storage
├── .gitignore      # Git ignored files
└── README.md       # Project documentation
```

---

# ⚙️ Features

## Contact Management

- Add new contacts
- Edit existing contacts
- Delete contacts
- Search contacts

---

## Search Modes

Search contacts using:

- Name
- Phone Number
- Email Address

---

## Validation System

The application validates:

- Empty input
- Invalid names
- Invalid phone numbers
- Invalid email addresses
- Duplicate phone numbers
- Duplicate emails

---

## File Persistence

Contacts are automatically stored using CSV file handling.

Even after closing the application, contact data remains saved.

Example:

```csv
John Doe,9876543210,john@gmail.com
Alice Smith,9123456780,alice@gmail.com
```

---

# 🖥️ Terminal UI

The project uses ANSI escape sequences for:

- Colored menus
- Better readability
- Highlighted errors
- Success messages
- Structured terminal tables

Example:

```text
==================================================
                ADDRESS BOOK SYSTEM
==================================================

1. Create Contact
2. List Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Save Contacts
7. Exit
```

---

# 🔄 Application Flow

```text
Start Program
      ↓
Load Contacts From CSV
      ↓
Display Main Menu
      ↓
User Selects Operation
      ↓
Perform Validation
      ↓
Execute Contact Operation
      ↓
Auto Save to CSV
      ↓
Return to Menu
```

---

# 🚀 Getting Started

## Prerequisites

- GCC Compiler
- Linux / Unix Environment
- Terminal with ANSI color support

---

# ⚒️ Build Project

## Using Makefile

```bash
make
```

---

## Manual Compilation

```bash
gcc main.c contact.c file.c populate.c -Wall -Wextra -Werror -std=c11 -o addressbook
```

---

# ▶️ Run the Application

## Linux / Mac

```bash
./addressbook
```

## Windows

```bash
addressbook.exe
```

---

# 🧹 Clean Build Files

```bash
make clean
```

---

# 🔁 Rebuild Project

```bash
make rebuild
```

---

# 📋 Core Concepts Demonstrated

| Concept | Usage |
|---|---|
| Structures | Contact data management |
| File Handling | CSV storage |
| String Functions | Search and validation |
| Arrays | Contact storage |
| Modular Programming | Separate source modules |
| ANSI Escape Codes | Colored terminal UI |
| Input Validation | User safety checks |
| Makefile | Build automation |

---

# 📂 Contact Structure

```c
typedef struct
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;
```

---

# 🔍 Search Functionality

The application supports:

- Partial name matching
- Exact phone matching
- Email-based lookup

Example:

```text
Search by Name → "John"
Matches:
- John Doe
- Johnson Mark
```

---

# ⚠️ Limitations

- Fixed maximum contacts (`MAX_CONTACTS = 100`)
- Terminal-only interface
- CSV storage only
- Single-user application

---

# 🚀 Future Improvements

- Contact sorting
- Password protection
- Binary file storage
- Case-insensitive search
- Import/export support
- Contact categories
- GUI version
- Dynamic memory allocation

---

# 👨‍💻 Author

**Santhosh Pandian SG**  
Embedded Systems Engineer | Emertxe ECEP Trainee

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0077B5?style=flat&logo=linkedin)](https://linkedin.com/in/santhoshpandian06)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-181717?style=flat&logo=github)](https://github.com/santhoshpandiansg)

---

# 📄 License

This project is licensed under the MIT License.
