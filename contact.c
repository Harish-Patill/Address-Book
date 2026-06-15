#include "contact.h"
#include<ctype.h>

struct Contacts contact_details[100];
int  contact_count=0;

// Function Definitions

void create_contact(struct Contacts *eptr, int size){
    int is_valid;

    // Name validation
    do{
        is_valid = 1;
        printf("Enter Name: ");
        scanf(" %[^\n]", eptr[size].Name);

        for(int i = 0; i < strlen(eptr[size].Name); i++){
            if(!isalpha(eptr[size].Name[i])){
                is_valid = 0;
                break;
            }
        }
        if(!is_valid) printf("Invalid name! Only letters allowed.\n");

    }while(!is_valid);

    // Phone validation
    do{
        is_valid = 1;
        printf("Enter Mobile Num: ");
        scanf(" %[^\n]", eptr[size].Mobile_number);

        if(strlen(eptr[size].Mobile_number) != 10){
            is_valid = 0;
        } 
        
        else{
            
            for(int i = 0; i < 10; i++){
                if(!isdigit(eptr[size].Mobile_number[i])){
                    is_valid = 0;
                    break;
                }
            }
        }
        // Uniqueness check
        if(is_valid){
            for(int i = 0; i < size; i++){
                if(strcmp(eptr[i].Mobile_number, eptr[size].Mobile_number) == 0){
                    is_valid = 0;
                    printf("Mobile number already exists!\n");
                    break;
                }
            }
        }
        if(!is_valid && strlen(eptr[size].Mobile_number) != 10)
            printf("Invalid! Must be 10 digits only.\n");

    }while(!is_valid);

    // Email validation
    do{
        is_valid = 1;
        printf("Enter Email-id: ");
        scanf(" %[^\n]", eptr[size].Mail_ID);

        char *at = strchr(eptr[size].Mail_ID, '@');
        char *dot = strrchr(eptr[size].Mail_ID, '.');

        // Basic structural checks
        if(!at || !dot || dot < at){
            is_valid = 0;
        } 
        
        else{
            // Something before @
            if(at == eptr[size].Mail_ID) is_valid = 0;
            // At least one char between @ and .
            if(dot - at < 2) is_valid = 0;
            // Must end with .com
            if(strcmp(dot, ".com") != 0) is_valid = 0;
            // Lowercase only
            for(int i = 0; eptr[size].Mail_ID[i] != '\0'; i++){
                if(isupper(eptr[size].Mail_ID[i])){
                    is_valid = 0;
                    break;
                }
            }
            // Uniqueness check
            if(is_valid){
                for(int i = 0; i < size; i++){
                    if(strcmp(eptr[i].Mail_ID, eptr[size].Mail_ID) == 0){
                        is_valid = 0;
                        printf("Email already exists!\n");
                        break;
                    }
                }
            }
        }
        if(!is_valid) printf("Invalid email!\n");

    }while(!is_valid);

    contact_count++;
}

void search_contacts(struct Contacts *eptr, int size,int user_input){
    switch(user_input){
        case 1:{
            int value=0;
            int is_valid;
            char search_name[50];

            do{
                is_valid = 1;
                printf("Enter Name: ");
                scanf(" %[^\n]", search_name);

                for(int i=0;i<strlen(search_name);i++){
                    if(!isalpha(search_name[i])){
                        is_valid = 0;
                        break;
                    }
                }
                if(!is_valid) printf("Invalid name! Only letters allowed.\n");
            }while(!is_valid);

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
            int is_valid;
            char search_mobile_number[50];

            do{
                is_valid = 1;
                printf("Enter Mobile Number: ");
                scanf(" %[^\n]", search_mobile_number);

                if(strlen(search_mobile_number) != 10){
                    is_valid = 0;
                }else{
                    for(int i=0;i<10;i++){
                        if(!isdigit(search_mobile_number[i])){
                            is_valid = 0;
                            break;
                        }
                    }
                }
                if(!is_valid) printf("Invalid! Mobile number must be 10 digits.\n");
            }while(!is_valid);

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
            int is_valid;
            char search_email[50];

            do{
                is_valid = 1;
                printf("Enter Email_ID: ");
                scanf(" %[^\n]", search_email);

                for(int i=0; search_email[i] != '\0'; i++){
                    if(isupper(search_email[i])){
                        is_valid = 0;
                        break;
                    }
                }
                if(!is_valid) printf("Invalid! Email must be lowercase.\n");
            }while(!is_valid);

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
    int is_valid;

    switch(edit_user_input){
    case 1:{
        int value=0;

        // Validate search name input
        do{
            is_valid = 1;
            printf("Enter Name: ");
            scanf(" %[^\n]", search_name);

            for(int i=0;i<strlen(search_name);i++){
                if(!isalpha(search_name[i])){
                    is_valid = 0;
                    break;
                }
            }
            if(!is_valid) printf("Invalid name! Only letters allowed.\n");
        }while(!is_valid);

        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Name,search_name)==0){

                // New Name
                do{
                    is_valid = 1;
                    printf("Enter new Name: ");
                    scanf(" %[^\n]", eptr[i].Name);
                    for(int j=0;j<strlen(eptr[i].Name);j++){
                        if(!isalpha(eptr[i].Name[j])){
                            is_valid = 0;
                            break;
                        }
                    }
                    if(!is_valid) printf("Invalid name! Only letters allowed.\n");
                }while(!is_valid);

                // New Mobile
                do{
                    is_valid = 1;
                    printf("Enter new Mobile: ");
                    scanf(" %[^\n]", eptr[i].Mobile_number);
                    if(strlen(eptr[i].Mobile_number) != 10){
                        is_valid = 0;
                    }else{
                        for(int j=0;j<10;j++){
                            if(!isdigit(eptr[i].Mobile_number[j])){
                                is_valid = 0;
                                break;
                            }
                        }
                    }
                    if(is_valid){
                        for(int j=0;j<size;j++){
                            if(j!=i && strcmp(eptr[j].Mobile_number, eptr[i].Mobile_number)==0){
                                is_valid = 0;
                                printf("Mobile number already exists!\n");
                                break;
                            }
                        }
                    }
                    if(!is_valid && strlen(eptr[i].Mobile_number)!=10)
                        printf("Invalid! Mobile number must be 10 digits.\n");
                }while(!is_valid);

                // New Mail-ID
                do{
                    is_valid = 1;
                    printf("Enter new Mail-ID: ");
                    scanf(" %[^\n]", eptr[i].Mail_ID);

                    char *at = strchr(eptr[i].Mail_ID, '@');
                    char *dot = strrchr(eptr[i].Mail_ID, '.');

                    if(!at || !dot || dot < at){
                        is_valid = 0;
                    }else{
                        if(at == eptr[i].Mail_ID) is_valid = 0;
                        if(dot - at < 2) is_valid = 0;
                        if(strcmp(dot, ".com") != 0) is_valid = 0;
                        for(int j=0; eptr[i].Mail_ID[j] != '\0'; j++){
                            if(isupper(eptr[i].Mail_ID[j])){
                                is_valid = 0;
                                break;
                            }
                        }
                        if(is_valid){
                            for(int j=0;j<size;j++){
                                if(j!=i && strcmp(eptr[j].Mail_ID, eptr[i].Mail_ID)==0){
                                    is_valid = 0;
                                    printf("Email already exists!\n");
                                    break;
                                }
                            }
                        }
                    }
                    if(!is_valid) printf("Invalid email!\n");
                }while(!is_valid);

                value = 1;
                printf("Contact updated successfully.\n");
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

        // Validate search mobile input
        do{
            is_valid = 1;
            printf("Enter Mobile Number: ");
            scanf(" %[^\n]", search_mobile_number);

            if(strlen(search_mobile_number) != 10){
                is_valid = 0;
            }else{
                for(int i=0;i<10;i++){
                    if(!isdigit(search_mobile_number[i])){
                        is_valid = 0;
                        break;
                    }
                }
            }
            if(!is_valid) printf("Invalid! Mobile number must be 10 digits.\n");
        }while(!is_valid);

        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mobile_number,search_mobile_number)==0){

                // New Name
                do{
                    is_valid = 1;
                    printf("Enter new Name: ");
                    scanf(" %[^\n]", eptr[i].Name);
                    for(int j=0;j<strlen(eptr[i].Name);j++){
                        if(!isalpha(eptr[i].Name[j])){
                            is_valid = 0;
                            break;
                        }
                    }
                    if(!is_valid) printf("Invalid name! Only letters allowed.\n");
                }while(!is_valid);

                // New Mobile
                do{
                    is_valid = 1;
                    printf("Enter new Mobile: ");
                    scanf(" %[^\n]", eptr[i].Mobile_number);
                    if(strlen(eptr[i].Mobile_number) != 10){
                        is_valid = 0;
                    }else{
                        for(int j=0;j<10;j++){
                            if(!isdigit(eptr[i].Mobile_number[j])){
                                is_valid = 0;
                                break;
                            }
                        }
                    }
                    if(is_valid){
                        for(int j=0;j<size;j++){
                            if(j!=i && strcmp(eptr[j].Mobile_number, eptr[i].Mobile_number)==0){
                                is_valid = 0;
                                printf("Mobile number already exists!\n");
                                break;
                            }
                        }
                    }
                    if(!is_valid && strlen(eptr[i].Mobile_number)!=10)
                        printf("Invalid! Mobile number must be 10 digits.\n");
                }while(!is_valid);

                // New Mail-ID
                do{
                    is_valid = 1;
                    printf("Enter new Mail-ID: ");
                    scanf(" %[^\n]", eptr[i].Mail_ID);

                    char *at = strchr(eptr[i].Mail_ID, '@');
                    char *dot = strrchr(eptr[i].Mail_ID, '.');

                    if(!at || !dot || dot < at){
                        is_valid = 0;
                    }else{
                        if(at == eptr[i].Mail_ID) is_valid = 0;
                        if(dot - at < 2) is_valid = 0;
                        if(strcmp(dot, ".com") != 0) is_valid = 0;
                        for(int j=0; eptr[i].Mail_ID[j] != '\0'; j++){
                            if(isupper(eptr[i].Mail_ID[j])){
                                is_valid = 0;
                                break;
                            }
                        }
                        if(is_valid){
                            for(int j=0;j<size;j++){
                                if(j!=i && strcmp(eptr[j].Mail_ID, eptr[i].Mail_ID)==0){
                                    is_valid = 0;
                                    printf("Email already exists!\n");
                                    break;
                                }
                            }
                        }
                    }
                    if(!is_valid) printf("Invalid email!\n");
                }while(!is_valid);

                value = 1;
                printf("Contact updated successfully.\n");
                break;
            }
        }
        if(value==0){
            printf("No employee found with Mobile %s\n",search_mobile_number);
            printf("\n");
        }
        break;
    }
    case 3:{
        int value=0;

        // Validate search email input
        do{
            is_valid = 1;
            printf("Enter Email_ID: ");
            scanf(" %[^\n]", search_email);

            for(int i=0; search_email[i] != '\0'; i++){
                if(isupper(search_email[i])){
                    is_valid = 0;
                    break;
                }
            }
            if(!is_valid) printf("Invalid! Email must be lowercase.\n");
        }while(!is_valid);

        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mail_ID,search_email)==0){

                // New Name
                do{
                    is_valid = 1;
                    printf("Enter new Name: ");
                    scanf(" %[^\n]", eptr[i].Name);
                    for(int j=0;j<strlen(eptr[i].Name);j++){
                        if(!isalpha(eptr[i].Name[j])){
                            is_valid = 0;
                            break;
                        }
                    }
                    if(!is_valid) printf("Invalid name! Only letters allowed.\n");
                }while(!is_valid);

                // New Mobile
                do{
                    is_valid = 1;
                    printf("Enter new Mobile: ");
                    scanf(" %[^\n]", eptr[i].Mobile_number);
                    if(strlen(eptr[i].Mobile_number) != 10){
                        is_valid = 0;
                    }else{
                        for(int j=0;j<10;j++){
                            if(!isdigit(eptr[i].Mobile_number[j])){
                                is_valid = 0;
                                break;
                            }
                        }
                    }
                    if(is_valid){
                        for(int j=0;j<size;j++){
                            if(j!=i && strcmp(eptr[j].Mobile_number, eptr[i].Mobile_number)==0){
                                is_valid = 0;
                                printf("Mobile number already exists!\n");
                                break;
                            }
                        }
                    }
                    if(!is_valid && strlen(eptr[i].Mobile_number)!=10)
                        printf("Invalid! Mobile number must be 10 digits.\n");
                }while(!is_valid);

                // New Mail-ID
                do{
                    is_valid = 1;
                    printf("Enter new Mail-ID: ");
                    scanf(" %[^\n]", eptr[i].Mail_ID);

                    char *at = strchr(eptr[i].Mail_ID, '@');
                    char *dot = strrchr(eptr[i].Mail_ID, '.');

                    if(!at || !dot || dot < at){
                        is_valid = 0;
                    }else{
                        if(at == eptr[i].Mail_ID) is_valid = 0;
                        if(dot - at < 2) is_valid = 0;
                        if(strcmp(dot, ".com") != 0) is_valid = 0;
                        for(int j=0; eptr[i].Mail_ID[j] != '\0'; j++){
                            if(isupper(eptr[i].Mail_ID[j])){
                                is_valid = 0;
                                break;
                            }
                        }
                        if(is_valid){
                            for(int j=0;j<size;j++){
                                if(j!=i && strcmp(eptr[j].Mail_ID, eptr[i].Mail_ID)==0){
                                    is_valid = 0;
                                    printf("Email already exists!\n");
                                    break;
                                }
                            }
                        }
                    }
                    if(!is_valid) printf("Invalid email!\n");
                }while(!is_valid);

                value = 1;
                printf("Contact updated successfully.\n");
                break;
            }
        }
        if(value==0){
            printf("No employee found with Email %s\n",search_email);
            printf("\n");
        }
        break;
    }
    case 4:
        printf("Exiting Search\n");
        edit_user_input=0;
        break;

    default:
        printf("Invalid Input\nTry AGAIN\n");
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
    int value=0;
    int is_valid;
    char confirm;

    switch(delete_input){
    case 1:{
        // Validate name input
        do{
            is_valid = 1;
            printf("Enter the target Name: ");
            scanf(" %[^\n]", target_name);

            for(int i=0;i<strlen(target_name);i++){
                if(!isalpha(target_name[i])){
                    is_valid = 0;
                    break;
                }
            }
            if(!is_valid) printf("Invalid name! Only letters allowed.\n");
        }while(!is_valid);
        printf("\n");

        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Name,target_name) == 0){

                printf("Are you sure you want to delete the contact?\n");
                printf("%s %s %s\n", eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
                printf("[Y/N]: ");
                scanf(" %c", &confirm);

                if(confirm=='Y' || confirm=='y'){
                    for(int j = i; j < size-1; j++){
                        strcpy(eptr[j].Name,eptr[j+1].Name);
                        strcpy(eptr[j].Mobile_number,eptr[j+1].Mobile_number);
                        strcpy(eptr[j].Mail_ID,eptr[j+1].Mail_ID);
                    }
                    contact_count--;
                    printf("Contact deleted.\n");
                }else{
                    printf("Deletion cancelled.\n");
                }
                value=1;
                break;
            }
        }
        if(value==0){
            printf("No user found with name %s\n",target_name);
            printf("\n");
        }
        break;
    }
    case 2:{
        // Validate mobile input
        do{
            is_valid = 1;
            printf("Enter the target Mobile no: ");
            scanf(" %[^\n]", target_mobile_number);

            if(strlen(target_mobile_number) != 10){
                is_valid = 0;
            }else{
                for(int i=0;i<10;i++){
                    if(!isdigit(target_mobile_number[i])){
                        is_valid = 0;
                        break;
                    }
                }
            }
            if(!is_valid) printf("Invalid! Mobile number must be 10 digits.\n");
        }while(!is_valid);
        printf("\n");

        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mobile_number,target_mobile_number) == 0){

                printf("Are you sure you want to delete the contact?\n");
                printf("%s %s %s\n", eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
                printf("[Y/N]: ");
                scanf(" %c", &confirm);

                if(confirm=='Y' || confirm=='y'){
                    for(int j = i; j < size-1; j++){
                        strcpy(eptr[j].Name,eptr[j+1].Name);
                        strcpy(eptr[j].Mobile_number,eptr[j+1].Mobile_number);
                        strcpy(eptr[j].Mail_ID,eptr[j+1].Mail_ID);
                    }
                    contact_count--;
                    printf("Contact deleted.\n");
                }else{
                    printf("Deletion cancelled.\n");
                }
                value=1;
                break;
            }
        }
        if(value==0){
            printf("No user found with mobile no %s\n",target_mobile_number);
            printf("\n");
        }
        break;
    }
    case 3:{
        // Validate email input
        do{
            is_valid = 1;
            printf("Enter the target Email_ID: ");
            scanf(" %[^\n]", target_email);

            for(int i=0; target_email[i] != '\0'; i++){
                if(isupper(target_email[i])){
                    is_valid = 0;
                    break;
                }
            }
            if(!is_valid) printf("Invalid! Email must be lowercase.\n");
        }while(!is_valid);
        printf("\n");

        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mail_ID,target_email) == 0){

                printf("Are you sure you want to delete the contact?\n");
                printf("%s %s %s\n", eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
                printf("[Y/N]: ");
                scanf(" %c", &confirm);

                if(confirm=='Y' || confirm=='y'){
                    for(int j = i; j < size-1; j++){
                        strcpy(eptr[j].Name,eptr[j+1].Name);
                        strcpy(eptr[j].Mobile_number,eptr[j+1].Mobile_number);
                        strcpy(eptr[j].Mail_ID,eptr[j+1].Mail_ID);
                    }
                    contact_count--;
                    printf("Contact deleted.\n");
                }else{
                    printf("Deletion cancelled.\n");
                }
                value=1;
                break;
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

void save_contacts(struct Contacts contact_details[], int *contact_count){
    FILE *fp = fopen("contacts.txt","w");
    if(fp==NULL){
        printf("File Not Open\n");
        return;
    }
    for(int i=0; i<*contact_count; i++){
        fprintf(fp,"%s %s %s\n",contact_details[i].Name,contact_details[i].Mobile_number,contact_details[i].Mail_ID);
    }
    fclose(fp);
    printf("Contacts Saved Successfully.\n");
}

void load_contacts(struct Contacts contact_details[], int *contact_count){
    FILE *fp = fopen("contacts.txt","r");
    if(fp==NULL){
        printf("No contacts file found.\n");
        return;
    }
    while(fscanf(fp,"%s %s %s\n",contact_details[*contact_count].Name,contact_details[*contact_count].Mobile_number,contact_details[*contact_count].Mail_ID)==3){
        (*contact_count)++;
    }
    printf("%d contacts loaded successfully.\n", *contact_count);
    fclose(fp);
}