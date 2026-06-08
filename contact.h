#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>
#include<string.h>

// Structures for the Fields
struct Contacts
{
    char Name[20];
    char Mobile_number[11];
    char Mail_ID[20];
};

// Structures foe the Contact deatils
struct AddressBook
{
    // Array of structures for the Fields sturucture
    struct Contacts contact_details[100];
    // To keep the track no of contact count
    int contact_count;
};

/* Function declarations */

void create_contact(struct AddressBook *);
void list_contacts(struct AddressBook *);
void search_contacts(struct AddressBook *);
void edit_contact(struct AddressBook *);
void delete_contact(struct AddressBook *);
void save_contacts(struct AddressBook *);

#endif
// CONTACT_H
// CONTACT_H