// Will include all the required header files in this file alone so that we can import this .h file in the rest of the files

#include<stdio.h>   // Input/output                                    
#include<string.h>  // String manipulation      → strcpy(), strlen()
#include<unistd.h>  // For linux and mac OS     → sleep()
#include<ctype.h>   // Char checks/conversions  → isalnum(), isalpha(), isdigit()

struct Contacts{
    char name[50];
    char number[11];
    char email[50];
};

extern struct Contacts contact_details[100];
extern int contact_count;

void create_contacts(struct Contacts *eptr,int size);       //size needed to keep check of the limit
void edit_contacts(struct Contacts *eptr,int size);
void list_all(struct Contacts *eptr);                       
void search_contacts(struct Contacts *eptr);                
void delete_contact(struct Contacts *eptr,int size);
void save_contacts(struct Contacts *eptr);
void load_contacts(struct Contacts *eptr);