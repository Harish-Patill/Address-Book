#include "contact.h"

struct Contacts contact_details[100];
int  contact_count=0;

// Function Definitions
void create_contact(struct Contacts *eptr, int size){

    printf("Enter Name: ");
    scanf("%s", eptr[size].Name);

    printf("Enter Mobile Num: ");
    scanf("%s", eptr[size].Mobile_number);

    printf("Enter Email-id: ");
    scanf("%s", eptr[size].Mail_ID);

    contact_count++;
}



void search_contacts(struct Contacts *eptr, int size,int user_input){

    
    
    switch(user_input){
        case 1:{
            int value=0;
            char search_name[50];
            printf("Enter Name: ");
            scanf("%s",search_name);
            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].Name,search_name)==0){
                    printf("Contact Details: ");
                    printf("%s %s %s\n",eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
                    printf("\n");
                    value = 1;
                    break;
                }
            }
            if(value==0){
                printf("No User found with Name: %s\n",search_name);
                printf("\n");
            }
            break;
        }
        case 2:{
            int value=0;
            char search_mobile_number[50];
            printf("Enter Mobile Number: ");
            scanf("%s",search_mobile_number);
            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].Mobile_number,search_mobile_number)==0){
                    printf("Contact Details: ");
                    printf("%s %s %s\n", eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
                    printf("\n");
                    value = 1;
                    break;
                }
            }
            if(value==0){
                printf("No employee found with ID %s\n",search_mobile_number);
                printf("\n");
            }
            break;
        }
        case 3:{
            int value=0;
            char search_email[50];
            printf("Enter Email_ID: ");
            scanf("%s",search_email);
            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].Mail_ID,search_email)==0){
                    printf("Contact Details: ");
                    printf("%s %s %s\n", eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
                    printf("\n");
                    value = 1;
                    break;
                }
            }
            if(value==0){
                printf("No employee found with ID %s\n",search_email);
                printf("\n");
            }
            break;
            }
        case 4:
            printf("Exiting Search\n");        
            user_input=0;
            break;
            
        default:
            printf("Invalid Input\n Try AGAIN\n");    
        }
}

void edit_contact(struct Contacts *eptr, int size, int edit_user_input){
    char search_name[50];
    char search_mobile_number[50];
    char search_email[50];
    
    
    switch(edit_user_input){
        case 1:{
        int value=0;
        printf("Enter Name: ");
        scanf("%s",search_name);
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Name,search_name)==0){
                
                printf("Enter new Name: ");
                scanf("%s", eptr[i].Name);
                printf("Enter new Mobile: ");
                scanf("%s", eptr[i].Mobile_number);
                printf("Enter new Mail-ID: ");
                scanf("%s", eptr[i].Mail_ID);

                value = 1;
                break;
            }
        }
        if(value==0){
            printf("No User found with Name: %s\n",search_name);
            printf("\n");
        }
        break;
    }
    case 2:{
        int value=0;
        printf("Enter Mobile Number: ");
        scanf("%s",search_mobile_number);
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mobile_number,search_mobile_number)==0){

                printf("Enter new Name: ");
                scanf("%s", eptr[i].Name);
                printf("Enter new Mobile: ");
                scanf("%s", eptr[i].Mobile_number);
                printf("Enter new Mail-ID: ");
                scanf("%s", eptr[i].Mail_ID);

                value = 1;
                break;
            }
        }
        if(value==0){
            printf("No employee found with ID %s\n",search_name);
            printf("\n");
        }
        break;
    }
    case 3:{
        int value=0;
        
        printf("Enter Email_ID: ");
        scanf("%s",search_email);
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mail_ID,search_email)==0){

                printf("Enter new Name: ");
                scanf("%s", eptr[i].Name);
                printf("Enter new Mobile: ");
                scanf("%s", eptr[i].Mobile_number);
                printf("Enter new Mail-ID: ");
                scanf("%s", eptr[i].Mail_ID);

                value = 1;
                break;
            }
        }
        if(value==0){
            printf("No employee found with ID %s\n",search_name);
            printf("\n");
        }
        break;
        }
    case 4:
        printf("Exiting Search\n");        
        edit_user_input=0;
        break;
        
    
    default:
        printf("Invalid Input\n Try AGAIN\n");    
    }
}

void list_contacts(struct Contacts *eptr, int size){
    if(size == 0){
        printf("No contacts found.\n");
        return;
    }
    for(int i = 0; i < size; i++){
        printf("%d. %s %s %s\n", i+1, eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
    }
}


void delete_contact(struct Contacts *eptr, int size, int delete_input){
    char target_name[50];
    char target_mobile_number[50];
    char target_email[50];
    int case_option=1;
    int value=0;
    
    switch(delete_input){
    case 1:{
        printf("Enter the target Name: ");
        scanf("%s",target_name);
        printf("\n");
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Name,target_name) == 0){
                for(int j = i; j < size- 1; j++){
                    strcpy(eptr[j].Name,eptr[j+1].Name);
                    strcpy(eptr[j].Mobile_number,eptr[j+1].Mobile_number);
                    strcpy(eptr[j].Mail_ID,eptr[j+1].Mail_ID);
                    
                }
                contact_count--;      // decrement after shifting
                value=1;
                printf("Contact deleted.\n");      // confirm to user
            }
        }
        if(value==0){
            printf("No user found with name %s\n",target_name);
            printf("\n");
        }
        break;    
        }
    case 2:{
        printf("Enter the target Mobile no: ");
        scanf("%s",target_mobile_number);
        printf("\n");
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mobile_number,target_mobile_number) == 0){
                for(int j = i; j < size- 1; j++){
                    strcpy(eptr[j].Name,eptr[j+1].Name);
                    strcpy(eptr[j].Mobile_number,eptr[j+1].Mobile_number);
                    strcpy(eptr[j].Mail_ID,eptr[j+1].Mail_ID);
                    
                }
                contact_count--;      // decrement after shifting
                value=1;
                printf("Contact deleted.\n");      // confirm to user
            }
        }
        if(value==0){
            printf("No user found with mobile no %s\n",target_mobile_number);
            printf("\n");
        }
        break;    
        }
        
    case 3:{
        printf("Enter the target Email_ID: ");
        scanf("%s",target_email);
        printf("\n");
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mail_ID,target_email) == 0){
                for(int j = i; j < size- 1; j++){
                    strcpy(eptr[j].Name,eptr[j+1].Name);
                    strcpy(eptr[j].Mobile_number,eptr[j+1].Mobile_number);
                    strcpy(eptr[j].Mail_ID,eptr[j+1].Mail_ID);
                    
                    
                }
                contact_count--;      // decrement after shifting
                value=1;
                printf("Contact deleted.\n");      // confirm to user
            }
        }
        if(value==0){
            printf("No user found with email-id %s\n",target_email);
            printf("\n");
        }
        break;  
        }
    case 4:
        delete_input=0;
        break;
    
    default:
        printf("Invalid Input\nTry again\n\n");
        break;
    
    }
}
