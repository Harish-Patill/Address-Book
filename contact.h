#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>

struct Contacts
{
    char Name[20];
    char Mobile_number[11];
    char Mail_ID[20];
};

struct Contacts contact_details[100];
int contact_count=0;


/* Function declarations */

void create_contact(struct Contacts *eptr, int size);
void list_contacts(struct Contacts *eptr, int size);
void search_contacts(struct Contacts *eptr, int size);
void edit_contact(struct Contacts *eptr, int size);
void delete_contact(struct Contacts *eptr, int size);
void save_contacts(struct Contacts *eptr, int size);

#endif
CONTACT_H
CONTACT_H