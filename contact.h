#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
#define CONTACT_FILE "contact.csv"

// ANSI color codes
#define CLR_RESET   "\033[0m"
#define CLR_RED     "\033[31m"
#define CLR_GREEN   "\033[32m"
#define CLR_YELLOW  "\033[33m"
#define CLR_BLUE    "\033[34m"
#define CLR_CYAN    "\033[36m"
#define CLR_BOLD    "\033[1m"

typedef struct
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct
{
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook, int mode);
void editContact(AddressBook *addressBook, int mode);
void deleteContact(AddressBook *addressBook, int mode);
void listContacts(AddressBook *addressBook, int sortType);

void initialize(AddressBook *addressBook);

void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

int ValidName(const char *name);
int ValidPhone(const char *phone);
int ValidEmail(const char *email);

void trimAndFlush(char *str);

#endif