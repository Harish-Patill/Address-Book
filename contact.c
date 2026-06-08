#include "contact.h"

// Function Definitions
void create_contact(struct AddressBook *addressbook){
    printf("Enter Name: ");
    scanf("%s", addressbook->contact_details[addressbook->contact_count].Name);

    printf("Enter Mobile Num: ");
    scanf("%s", addressbook->contact_details[addressbook->contact_count].Mobile_number);

    printf("Enter Email-id: ");
    scanf("%s", addressbook->contact_details[addressbook->contact_count].Mail_ID);

    addressbook->contact_count++;
}

void list_contacts(struct AddressBook *addressbook){
    for(int i=0;i<addressbook->contact_count;i++){
        printf("%s %s %s\n\n", addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
    }
}

void search_contacts(struct AddressBook *addressbook){
    char target_name[50];
    char target_mobile_number[50];
    char target_email[50];
    int case_option=1;
    int sub_switch_option=1;
    
    while(case_option){
        // printf("Search using \n01 Name\n02 Mobile no\n03 Email_ID\n04 Exit\n\n");
        // printf("Enter here: ");
        scanf("%d",&sub_switch_option);
        
        switch(sub_switch_option){
            case 1:
                printf("Enter the target Name: ");
                scanf("%s",target_name);
                printf("\n");
                for(int i=0;i<addressbook->contact_count;i++){
                    if(strcmp(addressbook->contact_details[i].Name,target_name) == 0){
                        printf("User information: ");
                        printf("%s %s %s\n\n", addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
                        printf("\n");
                    }
                }
                break;    
            
            case 2:
                printf("Enter the target Mobile number: ");
                scanf("%s",target_mobile_number);
                printf("\n");
                for(int i=0;i<addressbook->contact_count;i++){
                    if(strcmp(addressbook->contact_details[i].Mobile_number,target_mobile_number) == 0){
                        printf("User information: ");
                        printf("%s %s %s\n\n", addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
                        printf("\n");
                    }
                }
                break;
            
            case 3:
                printf("Enter the target Email_ID: ");
                scanf("%s",target_email);
                printf("\n");
                for(int i=0;i<addressbook->contact_count;i++){
                    if(strcmp(addressbook->contact_details[i].Mail_ID,target_email) == 0){
                        printf("User information: ");
                        printf("%s %s %s\n\n", addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
                        printf("\n");
                    }
                }
                break;
            
            case 4:
                case_option=0;
                break;
            
            default:
                printf("Invalid Input\nTry again\n\n");
                break;
        }
    }
}

void edit_contact(struct AddressBook *addressbook){
    char target_name[50];
    char target_mobile_number[50];
    char target_email[50];
    int case_option=1;
    int sub_switch_option=1;
    
    while(case_option){
        // printf("Search using \n01 Name\n02 Mobile no\n03 Email_ID\n04 Exit\n\n");
        // printf("Enter here: ");
        scanf("%d",&sub_switch_option);
        
        switch(sub_switch_option){
        case 1:
            printf("Enter the target Name: ");
            scanf("%s",target_name);
            printf("\n");
            for(int i=0;i<addressbook->contact_count;i++){
                if(strcmp(addressbook->contact_details[i].Name,target_name) == 0){
                    printf("Enter new Name: ");
                    scanf("%s", addressbook->contact_details[i].Name);
                    printf("Enter new Mobile: ");
                    scanf("%s", addressbook->contact_details[i].Mobile_number);
                    printf("Enter new Email: ");
                    scanf("%s", addressbook->contact_details[i].Mail_ID);
                    printf("\n");
                    case_option = 0;
                }
            }
            break;    
        
        case 2:
            printf("Enter the target Mobile number: ");
            scanf("%s",target_mobile_number);
            printf("\n");
            for(int i=0;i<addressbook->contact_count;i++){
                if(strcmp(addressbook->contact_details[i].Mobile_number,target_mobile_number) == 0){
                    printf("Enter new Name: ");
                    scanf("%s", addressbook->contact_details[i].Name);
                    printf("Enter new Mobile: ");
                    scanf("%s", addressbook->contact_details[i].Mobile_number);
                    printf("Enter new Email: ");
                    scanf("%s", addressbook->contact_details[i].Mail_ID);
                    printf("\n");
                    case_option = 0;

                }
            }
            break;
            
        case 3:
            printf("Enter the target Email_ID: ");
            scanf("%s",target_email);
            printf("\n");
            for(int i=0;i<addressbook->contact_count;i++){
                if(strcmp(addressbook->contact_details[i].Mail_ID,target_email) == 0){
                    printf("Enter new Name: ");
                    scanf("%s", addressbook->contact_details[i].Name);
                    printf("Enter new Mobile: ");
                    scanf("%s", addressbook->contact_details[i].Mobile_number);
                    printf("Enter new Email: ");
                    scanf("%s", addressbook->contact_details[i].Mail_ID);
                    printf("\n");  
                    case_option = 0;
 
                }
            }
            break;
            
        case 4:
            case_option=0;
            break;
        
        default:
            printf("Invalid Input\nTry again\n\n");
            break;
        
        }
    }
}

void delete_contact(struct AddressBook *addressbook){
    char target_name[50];
    char target_mobile_number[50];
    char target_email[50];
    int case_option=1;
    int sub_switch_option=1;
    
    while(case_option){
        // printf("Search using \n01 Name\n02 Mobile no\n03 Email_ID\n04 Exit\n\n");
        // printf("Enter here: ");
        scanf("%d",&sub_switch_option);
        
        switch(sub_switch_option){
        case 1:
            printf("Enter the target Name: ");
            scanf("%s",target_name);
            printf("\n");
            for(int i=0;i<addressbook->contact_count;i++){
                if(strcmp(addressbook->contact_details[i].Name,target_name) == 0){
                    for(int j = i; j < addressbook->contact_count - 1; j++){
                        strcpy(addressbook->contact_details[j].Name,          addressbook->contact_details[j+1].Name);
                        strcpy(addressbook->contact_details[j].Mobile_number, addressbook->contact_details[j+1].Mobile_number);
                        strcpy(addressbook->contact_details[j].Mail_ID,       addressbook->contact_details[j+1].Mail_ID);   
                        
                    }
                    addressbook->contact_count--;      // decrement after shifting
                    printf("Contact deleted.\n");      // confirm to user
                }
            }

            break;    
            
        case 2:
            
            printf("Enter the target Mobile no: ");
            scanf("%s",target_mobile_number);
            printf("\n");
            for(int i=0;i<addressbook->contact_count;i++){
                if(strcmp(addressbook->contact_details[i].Mobile_number,target_mobile_number) == 0){
                    for(int j = i; j < addressbook->contact_count - 1; j++){
                        strcpy(addressbook->contact_details[j].Name,          addressbook->contact_details[j+1].Name);
                        strcpy(addressbook->contact_details[j].Mobile_number, addressbook->contact_details[j+1].Mobile_number);
                        strcpy(addressbook->contact_details[j].Mail_ID,       addressbook->contact_details[j+1].Mail_ID);   
                        
                    }
                    addressbook->contact_count--;      // decrement after shifting
                    printf("Contact deleted.\n");      // confirm to user
                }
            }

            break;    
            
            
            
        case 3:
            printf("Enter the target Email_ID: ");
            scanf("%s",target_email);
            printf("\n");
            for(int i=0;i<addressbook->contact_count;i++){
                if(strcmp(addressbook->contact_details[i].Mail_ID,target_email) == 0){
                    for(int j = i; j < addressbook->contact_count - 1; j++){
                        strcpy(addressbook->contact_details[j].Name,          addressbook->contact_details[j+1].Name);
                        strcpy(addressbook->contact_details[j].Mobile_number, addressbook->contact_details[j+1].Mobile_number);
                        strcpy(addressbook->contact_details[j].Mail_ID,       addressbook->contact_details[j+1].Mail_ID);   
                    
                    }
                    addressbook->contact_count--;      // decrement after shifting
                    printf("Contact deleted.\n");      // confirm to user
                }
            }

            break;    
            
        case 4:
            case_option=0;
            break;
        
        default:
            printf("Invalid Input\nTry again\n\n");
            break;
        
        }
    }
    // return 0;
}
