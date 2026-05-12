# Address Book Application in C

A terminal-based Address Book Management System developed using the C programming language.

This project allows users to create, search, edit, delete, list, and save contacts using file handling and modular programming concepts.

---

# Features

- Create new contacts
- Search contacts by:
  - Name
  - Phone Number
  - Email
- Edit existing contacts
- Delete contacts
- List all contacts
- Automatic file saving
- File persistence using CSV
- Duplicate phone/email validation
- Input validation
- ANSI colored terminal UI
- Modular code structure
- Menu-driven interface

---

# Technologies Used

- C Programming
- GCC Compiler
- Makefile
- File Handling
- Structures
- Modular Programming

---

# Project Structure

```text
AddressBook/
│
├── main.c
├── contact.c
├── file.c
├── populate.c
│
├── contact.h
├── file.h
├── populate.h
│
├── Makefile
├── README.md
├── .gitignore
│
└── contact.csv
```

---

# Compilation

## Using Makefile

```bash
make
```

---

# Run the Project

## Linux / Mac

```bash
./addressbook
```

## Windows

```bash
addressbook.exe
```

---

# Clean Build Files

```bash
make clean
```

---

# Rebuild Project

```bash
make rebuild
```

---

# Screenshots

## Main Menu

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

# Contact Validation

The application validates:

- Empty input
- Invalid phone numbers
- Invalid emails
- Duplicate phone numbers
- Duplicate emails

---

# File Storage

Contacts are stored using CSV file handling.

Example:

```csv
John Doe,9876543210,john@gmail.com
Alice Smith,9123456780,alice@gmail.com
```

---

# Concepts Used

- Structures
- Arrays
- Functions
- File Handling
- String Handling
- Dynamic Menu Systems
- Modular Design
- Input Validation

---

# Future Improvements

- Sorting contacts
- Password protection
- Binary file storage
- Case-insensitive search
- Contact import/export
- Pagination support
- GUI version

---

# Author

Santhosh Pandian SG

GitHub:
https://github.com/santhoshpandiansg

---

# License

This project is developed for educational and learning purposes.