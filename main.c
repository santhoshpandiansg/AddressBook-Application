//Description: This file contains the main function and menu handling for the address book application.
/*
Name of the Project: Address Book Application
Date: 31-12-2025
Emertxe id : 25036_016
Name: Santhosh pandian SG
Purpose: Implement the main function and menu handling for the address book application.
Language: C
overview: This file contains the main function and menu handling logic for the address book application.
*/
#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

void createMenu(AddressBook *addressBook);
void searchMenu(AddressBook *addressBook);
void editMenu(AddressBook *addressBook);
void deleteMenu(AddressBook *addressBook);
void listMenu(AddressBook *addressBook);

int getChoice(int min, int max);

int main()
{
    AddressBook addressBook;

    initialize(&addressBook);

    while (1)
    {
        printf("\n");
        printf(CLR_CYAN CLR_BOLD);
        printf("==================================================\n");
        printf("                ADDRESS BOOK SYSTEM\n");
        printf("==================================================\n");
        printf(CLR_RESET);

        printf(CLR_YELLOW "1. Create Contact\n" CLR_RESET);
        printf(CLR_YELLOW "2. List Contacts\n" CLR_RESET);
        printf(CLR_YELLOW "3. Search Contact\n" CLR_RESET);
        printf(CLR_YELLOW "4. Edit Contact\n" CLR_RESET);
        printf(CLR_YELLOW "5. Delete Contact\n" CLR_RESET);
        printf(CLR_YELLOW "6. Save Contacts\n" CLR_RESET);
        printf(CLR_YELLOW "7. Exit\n" CLR_RESET);

        printf("\nEnter choice: ");

        int choice = getChoice(1, 7);

        switch (choice)
        {
            case 1:
                createMenu(&addressBook);
                break;

            case 2:
                listMenu(&addressBook);
                break;

            case 3:
                searchMenu(&addressBook);
                break;

            case 4:
                editMenu(&addressBook);
                break;

            case 5:
                deleteMenu(&addressBook);
                break;

            case 6:
                saveContactsToFile(&addressBook);
                printf(CLR_GREEN "\nContacts saved successfully\n" CLR_RESET);
                break;

            case 7:
                saveContactsToFile(&addressBook);
                printf(CLR_CYAN "\nExiting Address Book...\n" CLR_RESET);
                exit(0);
        }
    }

    return 0;
}

int getChoice(int min, int max)
{
    int choice;

    while (1)
    {
        if (scanf("%d", &choice) != 1)
        {
            printf(CLR_RED "Invalid input. Enter number only: " CLR_RESET);

            while (getchar() != '\n');

            continue;
        }

        if (choice < min || choice > max)
        {
            printf(CLR_RED "Enter valid option (%d-%d): " CLR_RESET,
                   min,
                   max);

            continue;
        }

        while (getchar() != '\n');

        return choice;
    }
}

void createMenu(AddressBook *addressBook)
{
    while (1)
    {
        printf("\n");
        printf(CLR_CYAN CLR_BOLD);
        printf("=============== CREATE MENU ===============\n");
        printf(CLR_RESET);

        printf(CLR_YELLOW "1. Create New Contact\n" CLR_RESET);
        printf(CLR_YELLOW "2. Back to Main Menu\n" CLR_RESET);

        printf("\nEnter choice: ");

        int choice = getChoice(1, 2);

        switch (choice)
        {
            case 1:
                createContact(addressBook);
                break;

            case 2:
                return;
        }
    }
}

void searchMenu(AddressBook *addressBook)
{
    while (1)
    {
        printf("\n");
        printf(CLR_CYAN CLR_BOLD);
        printf("=============== SEARCH MENU ===============\n");
        printf(CLR_RESET);

        printf(CLR_YELLOW "1. Search by Name\n" CLR_RESET);
        printf(CLR_YELLOW "2. Search by Phone\n" CLR_RESET);
        printf(CLR_YELLOW "3. Search by Email\n" CLR_RESET);
        printf(CLR_YELLOW "4. Back\n" CLR_RESET);

        printf("\nEnter choice: ");

        int choice = getChoice(1, 4);

        if (choice == 4)
        {
            return;
        }

        searchContact(addressBook, choice);
    }
}

void editMenu(AddressBook *addressBook)
{
    while (1)
    {
        printf("\n");
        printf(CLR_CYAN CLR_BOLD);
        printf("================ EDIT MENU ================\n");
        printf(CLR_RESET);

        printf(CLR_YELLOW "1. Edit by Name\n" CLR_RESET);
        printf(CLR_YELLOW "2. Edit by Phone\n" CLR_RESET);
        printf(CLR_YELLOW "3. Edit by Email\n" CLR_RESET);
        printf(CLR_YELLOW "4. Back\n" CLR_RESET);

        printf("\nEnter choice: ");

        int choice = getChoice(1, 4);

        if (choice == 4)
        {
            return;
        }

        editContact(addressBook, choice);
    }
}

void deleteMenu(AddressBook *addressBook)
{
    while (1)
    {
        printf("\n");
        printf(CLR_CYAN CLR_BOLD);
        printf("=============== DELETE MENU ===============\n");
        printf(CLR_RESET);

        printf(CLR_YELLOW "1. Delete by Name\n" CLR_RESET);
        printf(CLR_YELLOW "2. Delete by Phone\n" CLR_RESET);
        printf(CLR_YELLOW "3. Delete by Email\n" CLR_RESET);
        printf(CLR_YELLOW "4. Back\n" CLR_RESET);

        printf("\nEnter choice: ");

        int choice = getChoice(1, 4);

        if (choice == 4)
        {
            return;
        }

        deleteContact(addressBook, choice);
    }
}

void listMenu(AddressBook *addressBook)
{
    while (1)
    {
        printf("\n");
        printf(CLR_CYAN CLR_BOLD);
        printf("================ LIST MENU ================\n");
        printf(CLR_RESET);

        printf(CLR_YELLOW "1. List All Contacts\n" CLR_RESET);
        printf(CLR_YELLOW "2. Back\n" CLR_RESET);

        printf("\nEnter choice: ");

        int choice = getChoice(1, 2);

        switch (choice)
        {
            case 1:
                listContacts(addressBook, 0);
                break;

            case 2:
                return;
        }
    }
}