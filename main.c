#include "project_header.h"

struct Contacts contact_details[100];
int contact_count=0;
int max_size=100;

int main(){
    int flag=1;
    int main_option=0;

    load_contacts(contact_details);

    printf("\n\t\t:: Address Book ::");
    while(flag){
        printf("\n1. Add Contacts\n2. Search Contacts\n3. Edit Contacts\n4. Delete Contacts\n5. Display all Contacts\n6. Save and Exit\n7. Exit\n\nSelect any of the above options: ");
        scanf("%d",&main_option);

        switch(main_option){
            case 1:{
                create_contacts(contact_details,max_size);
                break;
            }

            case 2:{
                search_contacts(contact_details);
                break;
            }

            case 3:{
                edit_contacts(contact_details,contact_count);
                break;
            }
            
            case 4:{
                delete_contact(contact_details,contact_count);
                break;
            }

            case 5:{
                list_all(contact_details);
                break;
            }

            case 6:{
                save_contacts(contact_details);
                printf("\n\t\t :: Thank You ::\n");

                flag=0;
                break;
            }

            case 7:{
                flag=0;
                printf("\n\t\t :: Thank You ::\n");
                break;
            }

            default:
                printf("Invalid Input!");
                break;
        }
    }
    return 0;
}