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

extern struct Contacts contact_details[100];
extern int  contact_count;


/* Function declarations */



void create_contact(struct Contacts *eptr, int size);
void list_contacts(struct Contacts *eptr, int size);
void search_contacts(struct Contacts *eptr, int size,int user_input);
void edit_contact(struct Contacts *eptr, int size, int edit_user_input);
void delete_contact(struct Contacts *eptr, int size, int delete_input);
void save_contacts(struct Contacts contact_details[], int *contact_count);
void load_contacts(struct Contacts contact_details[], int *contact_count);

#endif
