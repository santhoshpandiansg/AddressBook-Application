//Description: This file contains functions related to file I/O for the address book application.
/*
Name of the Project: Address Book Application
Date: 31-12-2025
Emertxe id : 25036_016
Name: Santhosh pandian SG
Purpose: Implement file I/O functions for saving and loading contacts.
Language: C
overview: This file includes functions for saving and loading contacts to/from a file.
*/

#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fp = fopen(CONTACT_FILE, "w");

    if (fp == NULL)
    {
        fprintf(stderr, CLR_RED "Error opening file.\n" CLR_RESET);
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp = fopen(CONTACT_FILE, "r");

    if (fp == NULL)
    {
        return;
    }

    while (addressBook->contactCount < MAX_CONTACTS &&
           fscanf(fp,
                  "%49[^,],%19[^,],%49[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
    }

    fclose(fp);
}