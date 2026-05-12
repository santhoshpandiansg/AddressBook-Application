//Description: This file contains functions related to contact management in the address book application.
/*
Name of the Project: Address Book Application
Date: 31-12-2025
Emertxe id : 25036_016
Name: Santhosh pandian SG
Purpose: Implement contact management functions for an address book application.
Language: C
overview: This file includes functions for creating, searching, editing, deleting, listing contacts, and validating input data.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "file.h"

void trimAndFlush(char *str)
{
    int i = 0;
    int found = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            found = 1;
            break;
        }

        i++;
    }

    if (!found)
    {
        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;

    loadContactsFromFile(addressBook);
}

int ValidName(const char *name)
{
    if (name[0] == '\0')
    {
        return 0;
    }

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
              (name[i] >= 'a' && name[i] <= 'z') ||
               name[i] == ' '))
        {
            return 0;
        }
    }

    return 1;
}

int ValidPhone(const char *phone)
{
    if (strlen(phone) != 10)
    {
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
        {
            return 0;
        }
    }

    return 1;
}

int ValidEmail(const char *email)
{
    return (strchr(email, '@') && strchr(email, '.'));
}

void createContact(AddressBook *addressBook)
{
    if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf(CLR_RED "Address book full\n" CLR_RESET);
        return;
    }

    while (getchar() != '\n');

    Contact *c = &addressBook->contacts[addressBook->contactCount];

    while (1)
    {
        printf("Enter name: ");

        fgets(c->name, sizeof(c->name), stdin);

        trimAndFlush(c->name);

        if (ValidName(c->name))
        {
            break;
        }

        printf(CLR_RED "Invalid name\n" CLR_RESET);
    }

    while (1)
    {
        int duplicate = 0;

        printf("Enter phone: ");

        fgets(c->phone, sizeof(c->phone), stdin);

        trimAndFlush(c->phone);

        if (!ValidPhone(c->phone))
        {
            printf(CLR_RED "Invalid phone\n" CLR_RESET);
            continue;
        }

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, c->phone) == 0)
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            break;
        }

        printf(CLR_RED "Phone exists\n" CLR_RESET);
    }

    while (1)
    {
        int duplicate = 0;

        printf("Enter email: ");

        fgets(c->email, sizeof(c->email), stdin);

        trimAndFlush(c->email);

        if (!ValidEmail(c->email))
        {
            printf(CLR_RED "Invalid email\n" CLR_RESET);
            continue;
        }

        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, c->email) == 0)
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            break;
        }

        printf(CLR_RED "Email exists\n" CLR_RESET);
    }

    addressBook->contactCount++;

    saveContactsToFile(addressBook);

    printf(CLR_GREEN "Contact added\n" CLR_RESET);
}

void listContacts(AddressBook *addressBook, int sortType)
{
    (void)sortType;

    if (addressBook->contactCount == 0)
    {
        printf(CLR_RED "\nNo contacts available\n" CLR_RESET);
        return;
    }

    printf("\n");

    printf(CLR_CYAN CLR_BOLD);
    printf("================================================================================\n");
    printf("                               CONTACT LIST\n");
    printf("================================================================================\n");
    printf(CLR_RESET);

    printf(CLR_BOLD "%-5s %-25s %-18s %-35s\n" CLR_RESET,
           "No",
           "Name",
           "Phone",
           "Email");

    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%-5d %-25s %-18s %-35s\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    printf("================================================================================\n");

    printf(CLR_GREEN "\nTotal Contacts : %d\n" CLR_RESET,
           addressBook->contactCount);
}

void searchContact(AddressBook *addressBook, int mode)
{
    while (getchar() != '\n');

    char key[50];

    printf("Enter search value: ");

    fgets(key, sizeof(key), stdin);

    trimAndFlush(key);

    int found = 0;

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        Contact *c = &addressBook->contacts[i];

        if ((mode == 1 && strstr(c->name, key)) ||
            (mode == 2 && strcmp(c->phone, key) == 0) ||
            (mode == 3 && strstr(c->email, key)))
        {
            printf("%-20s %-15s %-30s\n",
                   c->name,
                   c->phone,
                   c->email);

            found = 1;
        }
    }

    if (!found)
    {
        printf(CLR_RED "No match found\n" CLR_RESET);
    }
}

void editContact(AddressBook *addressBook, int mode)
{
    while (getchar() != '\n');

    char key[50];

    printf("Enter value to edit: ");

    fgets(key, sizeof(key), stdin);

    trimAndFlush(key);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        Contact *c = &addressBook->contacts[i];

        int match = 0;

        if ((mode == 1 && strstr(c->name, key)) ||
            (mode == 2 && strcmp(c->phone, key) == 0) ||
            (mode == 3 && strcmp(c->email, key) == 0))
        {
            match = 1;
        }

        if (match)
        {
            int choice;

            printf("\n1.Name\n2.Phone\n3.Email\n");
            printf("Enter choice: ");

            scanf("%d", &choice);

            while (getchar() != '\n');

            char newValue[50];

            printf("Enter new value: ");

            fgets(newValue, sizeof(newValue), stdin);

            trimAndFlush(newValue);

            if (choice == 1 && ValidName(newValue))
            {
                strncpy(c->name, newValue, sizeof(c->name) - 1);
            }
            else if (choice == 2 && ValidPhone(newValue))
            {
                strncpy(c->phone, newValue, sizeof(c->phone) - 1);
            }
            else if (choice == 3 && ValidEmail(newValue))
            {
                strncpy(c->email, newValue, sizeof(c->email) - 1);
            }
            else
            {
                printf(CLR_RED "Invalid input\n" CLR_RESET);
                return;
            }

            saveContactsToFile(addressBook);

            printf(CLR_GREEN "Updated successfully\n" CLR_RESET);

            return;
        }
    }

    printf(CLR_RED "Contact not found\n" CLR_RESET);
}

void deleteContact(AddressBook *addressBook, int mode)
{
    while (getchar() != '\n');

    char key[50];

    printf("Enter value to delete: ");

    fgets(key, sizeof(key), stdin);

    trimAndFlush(key);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        Contact *c = &addressBook->contacts[i];

        int match = 0;

        if ((mode == 1 && strstr(c->name, key)) ||
            (mode == 2 && strcmp(c->phone, key) == 0) ||
            (mode == 3 && strcmp(c->email, key) == 0))
        {
            match = 1;
        }

        if (match)
        {
            for (int j = i; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] =
                addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;

            saveContactsToFile(addressBook);

            printf(CLR_GREEN "Deleted successfully\n" CLR_RESET);

            return;
        }
    }

    printf(CLR_RED "Contact not found\n" CLR_RESET);
}