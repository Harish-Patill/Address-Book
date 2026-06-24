#include "contact.h"

int main(){
    int option;
    int main_option = 1;
    int search_input=0;
    int edit_input=0;
    int user_input_delete_contact=0;

    load_contacts(contact_details, &contact_count);  

    while (main_option)    {
        printf("\nAddress book menu\n");
        printf("1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save contact\n7.Exit\n");
        printf("Enter the option : ");
        scanf("%d", &option);

        switch (option){
        case 1:{
            create_contact(contact_details,contact_count);
            break;
        }

        case 2:{
            printf("\n");
            printf("Search Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : ");
            scanf("%d",&search_input);
            search_contacts(contact_details,contact_count,search_input);
            break;
        }
        case 3:
            printf("\n");
            printf("Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : ");
            scanf("%d",&edit_input);
            edit_contact(contact_details,contact_count,edit_input);
            break;

        case 4:{
            printf("Delete Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : ");
            scanf("%d",&user_input_delete_contact);
            delete_contact(contact_details,contact_count,user_input_delete_contact);
            break;
        }
        case 5:{
            printf("\n");
            printf("------------------------------------------------------------------------------------------------------------------\n");
            printf("Contacts List:\n");
            list_contacts(contact_details,contact_count);
            break;
        }

        case 6:{
            save_contacts(contact_details, &contact_count);  
            break;
        }
        case 7:
            save_contacts(contact_details, &contact_count);  
            printf("Exit\n");
            main_option=0;
            break;

        default:
            printf("Invalid option \n");
            break;
        }
    }
    return 0;
}