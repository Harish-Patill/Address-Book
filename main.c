#include "contact.h"

int main()
{
    /* Variable and structre defintion */
    int option;
    int main_option = 1;
    int search_input=0;

    while (main_option)
    {
        printf("\nAddress book menu\n"); /* Give a prompt message for a user */
        printf("1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save contact\n7.Exit\n");
        printf("Enter the option : ");
        scanf("%d", &option);

        switch (option) /* Based on choosed option */{
        case 1:{
            create_contact(&contact_details,contact_count);
            break;
        }

        case 2:{
            printf("\n");
            printf("Search Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */
            scanf("%d",&search_input);
            search_contacts(&contact_details,contact_count,search_input);
            break;
        }
        // case 3:
        //     printf("Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */

        //     edit_contact(&contact_details,contact_count);
        //     break;

        // case 4:{
        //     printf("Delete Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */

        //     delete_contact(&contact_details,contact_count);
        //     break;
        // }
        // case 5:{
        //     printf("\n");
        //     printf("------------------------------------------------------------------------------------------------------------------\n");
        //     printf("Contacts List:\n");
        //     list_contacts(&contact_details,contact_count);
        //     break;
        // }

        // case 6:{
        //     printf("Saving Info\n");
        //     return 0;
        // }
        case 7:
            printf("Exit\n");
            main_option=0;

        default:
            printf("Invalid option \n");
            break;
        }
    }
    return 0;
}
