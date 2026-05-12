#include "contact.h"

static Contact dummyContacts[] =
{
    {"John Doe", "1234567890", "john@gmail.com"},
    {"Alice Smith", "9876543210", "alice@gmail.com"},
    {"Bob Johnson", "9998887776", "bob@gmail.com"}
};

void populateAddressBook(AddressBook *addressBook)
{
    int count = sizeof(dummyContacts) / sizeof(dummyContacts[0]);

    for (int i = 0; i < count && addressBook->contactCount < MAX_CONTACTS; i++)
    {
        addressBook->contacts[addressBook->contactCount++] = dummyContacts[i];
    }
}