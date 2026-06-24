#include"contact.h"
#include<ctype.h>

struct Contacts contact_details[100];
int contact_count=0;

void create_contact(struct Contacts *eptr, int size){
    int is_valid;

    // Name validation loop
    do{
        is_valid = 1;
        printf("Enter Name: ");
        scanf(" %[^\n]", eptr[size].Name);

        // Check each character is alphabetic
        for(int i = 0; i < strlen(eptr[size].Name); i++){
            if(!isalpha(eptr[size].Name[i])){ is_valid = 0; break; }
        }
        if(!is_valid) printf("Invalid name! Only letters allowed.\n");
    }while(!is_valid);

    // Phone validation loop
    do{
        is_valid = 1;
        printf("Enter Mobile Num: ");
        scanf(" %[^\n]", eptr[size].Mobile_number);

        // Check length is exactly 10
        if(strlen(eptr[size].Mobile_number) != 10){
            is_valid = 0;
        }else{
            // Check each character is a digit
            for(int i = 0; i < 10; i++){
                if(!isdigit(eptr[size].Mobile_number[i])){ is_valid = 0; break; }
            }
        }
        // Check mobile uniqueness
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

    // Email validation loop
    do{
        is_valid = 1;
        printf("Enter Email-id: ");
        scanf(" %[^\n]", eptr[size].Mail_ID);

        char *at = strchr(eptr[size].Mail_ID, '@');   // find @ position
        char *dot = strrchr(eptr[size].Mail_ID, '.'); // find last . position

        // Check basic structure: @ and . must exist, . must come after @
        if(!at || !dot || dot < at){
            is_valid = 0;
        }else{
            if(at == eptr[size].Mail_ID) is_valid = 0;        // nothing before @
            if(dot - at < 2) is_valid = 0;                    // nothing between @ and .
            if(strcmp(dot, ".com") != 0) is_valid = 0;        // must end with .com
            // Check all characters are lowercase
            for(int i = 0; eptr[size].Mail_ID[i] != '\0'; i++){
                if(isupper(eptr[size].Mail_ID[i])){ is_valid = 0; break; }
            }
            // Check email uniqueness
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

void search_contacts(struct Contacts *eptr, int size, int user_input){
    switch(user_input){
        case 1:{
            int value=0;
            int is_valid;
            char search_name[50];

            // Validate name input
            do{
                is_valid = 1;
                printf("Enter Name: ");
                scanf(" %[^\n]", search_name);
                for(int i=0;i<strlen(search_name);i++){
                    if(!isalpha(search_name[i])){ is_valid = 0; }
                }
                if(!is_valid) printf("Invalid name! Only letters allowed.\n");
            }while(!is_valid);

            // Search and print all matching contacts
            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].Name,search_name)==0){
                    printf("Contact Details: ");
                    printf("%s %s %s\n",eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
                    printf("\n");
                    value = 1;
                }
            }
            if(value==0) printf("No User found with Name: %s\n\n",search_name);
            break;
        }
        case 2:{
            int value=0;
            int is_valid;
            char search_mobile_number[50];

            // Validate mobile input
            do{
                is_valid = 1;
                printf("Enter Mobile Number: ");
                scanf(" %[^\n]", search_mobile_number);
                if(strlen(search_mobile_number) != 10){
                    is_valid = 0;
                }else{
                    for(int i=0;i<10;i++){
                        if(!isdigit(search_mobile_number[i])){ is_valid = 0; }
                    }
                }
                if(!is_valid) printf("Invalid! Mobile number must be 10 digits.\n");
            }while(!is_valid);

            // Search and print matching contact
            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].Mobile_number,search_mobile_number)==0){
                    printf("Contact Details: ");
                    printf("%s %s %s\n", eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
                    printf("\n");
                    value = 1;
                }
            }
            if(value==0) printf("No contact found with Mobile: %s\n\n",search_mobile_number);
            break;
        }
        case 3:{
            int value=0;
            int is_valid;
            char search_email[50];

            // Validate email input (lowercase check only for search)
            do{
                is_valid = 1;
                printf("Enter Email_ID: ");
                scanf(" %[^\n]", search_email);
                for(int i=0; search_email[i] != '\0'; i++){
                    if(isupper(search_email[i])){ is_valid = 0; }
                }
                if(!is_valid) printf("Invalid! Email must be lowercase.\n");
            }while(!is_valid);

            // Search and print matching contact
            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].Mail_ID,search_email)==0){
                    printf("Contact Details: ");
                    printf("%s %s %s\n", eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
                    printf("\n");
                    value = 1;
                }
            }
            if(value==0) printf("No contact found with Email: %s\n\n",search_email);
            break;
        }
        case 4:
            printf("Exiting Search\n");
            user_input=0;
            break;
        default:
            printf("Invalid Input\nTry AGAIN\n");
    }
}

int resolve_duplicate(struct Contacts *eptr, int size, char *search_name){
    // Count how many contacts share this name
    int match_count = 0;
    for(int i=0;i<size;i++){
        if(strcmp(eptr[i].Name, search_name)==0) match_count++;
    }

    // If only one match, return it directly
    if(match_count == 1){
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Name, search_name)==0) return i;
        }
    }

    // Multiple matches found — print them all and ask for mobile or email
    if(match_count > 1){
        printf("Multiple contacts found with name '%s':\n", search_name);
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Name, search_name)==0){
                printf("  %s %s %s\n", eptr[i].Name, eptr[i].Mobile_number, eptr[i].Mail_ID);
            }
        }

        // Ask user to identify by mobile or email
        printf("Enter Mobile or Email to select the contact: ");
        char identifier[50];
        scanf(" %[^\n]", identifier);

        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Name, search_name)==0){
                if(strcmp(eptr[i].Mobile_number, identifier)==0 ||
                   strcmp(eptr[i].Mail_ID, identifier)==0){
                    return i; // found the specific contact
                }
            }
        }
        printf("No contact matched that mobile/email.\n");
    }
    return -1; // not found
}

void update_fields(struct Contacts *eptr, int size, int i){
    int is_valid;

    // Validate and update name
    do{
        is_valid = 1;
        printf("Enter new Name: ");
        scanf(" %[^\n]", eptr[i].Name);
        for(int j=0;j<strlen(eptr[i].Name);j++){
            if(!isalpha(eptr[i].Name[j])){ is_valid = 0; break; }
        }
        if(!is_valid) printf("Invalid name! Only letters allowed.\n");
    }while(!is_valid);

    // Validate and update mobile (skip uniqueness check against itself)
    do{
        is_valid = 1;
        printf("Enter new Mobile: ");
        scanf(" %[^\n]", eptr[i].Mobile_number);
        if(strlen(eptr[i].Mobile_number) != 10){
            is_valid = 0;
        }else{
            for(int j=0;j<10;j++){
                if(!isdigit(eptr[i].Mobile_number[j])){ is_valid = 0; break; }
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

    // Validate and update email
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
                if(isupper(eptr[i].Mail_ID[j])){ is_valid = 0; break; }
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

    printf("Contact updated successfully.\n");
}

void edit_contact(struct Contacts *eptr, int size, int edit_user_input){
    char search_name[50];
    char search_mobile_number[50];
    char search_email[50];
    int is_valid;
    int index = -1;

    switch(edit_user_input){
    case 1:{
        // Validate search name
        do{
            is_valid = 1;
            printf("Enter Name: ");
            scanf(" %[^\n]", search_name);
            for(int i=0;i<strlen(search_name);i++){
                if(!isalpha(search_name[i])){ is_valid = 0; break; }
            }
            if(!is_valid) printf("Invalid name! Only letters allowed.\n");
        }while(!is_valid);

        // Resolve duplicates and get index
        index = resolve_duplicate(eptr, size, search_name);
        if(index == -1){
            printf("No User found with Name: %s\n\n", search_name);
            break;
        }
        update_fields(eptr, size, index);
        break;
    }
    case 2:{
        // Validate search mobile
        do{
            is_valid = 1;
            printf("Enter Mobile Number: ");
            scanf(" %[^\n]", search_mobile_number);
            if(strlen(search_mobile_number) != 10){
                is_valid = 0;
            }else{
                for(int i=0;i<10;i++){
                    if(!isdigit(search_mobile_number[i])){ is_valid = 0; break; }
                }
            }
            if(!is_valid) printf("Invalid! Mobile number must be 10 digits.\n");
        }while(!is_valid);

        // Find contact by mobile
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mobile_number, search_mobile_number)==0){ index = i; break; }
        }
        if(index == -1){
            printf("No contact found with Mobile: %s\n\n", search_mobile_number);
            break;
        }
        update_fields(eptr, size, index);
        break;
    }
    case 3:{
        // Validate search email
        do{
            is_valid = 1;
            printf("Enter Email_ID: ");
            scanf(" %[^\n]", search_email);
            for(int i=0; search_email[i] != '\0'; i++){
                if(isupper(search_email[i])){ is_valid = 0; break; }
            }
            if(!is_valid) printf("Invalid! Email must be lowercase.\n");
        }while(!is_valid);

        // Find contact by email
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mail_ID, search_email)==0){ index = i; break; }
        }
        if(index == -1){
            printf("No contact found with Email: %s\n\n", search_email);
            break;
        }
        update_fields(eptr, size, index);
        break;
    }
    case 4:
        printf("Exiting Edit\n");
        edit_user_input=0;
        break;
    default:
        printf("Invalid Input\nTry AGAIN\n");
    }
}

void list_contacts(struct Contacts *eptr, int size){
    if(size == 0){ printf("No contacts found.\n"); return; }
    // Print all contacts with index
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
    int index = -1;

    switch(delete_input){
    case 1:{
        // Validate name input
        do{
            is_valid = 1;
            printf("Enter the target Name: ");
            scanf(" %[^\n]", target_name);
            for(int i=0;i<strlen(target_name);i++){
                if(!isalpha(target_name[i])){ is_valid = 0; break; }
            }
            if(!is_valid) printf("Invalid name! Only letters allowed.\n");
        }while(!is_valid);

        // Resolve duplicates and get index
        index = resolve_duplicate(eptr, size, target_name);
        if(index == -1){
            printf("No user found with name %s\n\n", target_name);
            break;
        }

        // Confirm before deleting
        printf("Are you sure you want to delete this contact?\n");
        printf("%s %s %s\n", eptr[index].Name, eptr[index].Mobile_number, eptr[index].Mail_ID);
        printf("[Y/N]: ");
        scanf(" %c", &confirm);

        if(confirm=='Y' || confirm=='y'){
            // Shift all contacts left to fill the gap
            for(int j=index; j<size-1; j++){
                strcpy(eptr[j].Name, eptr[j+1].Name);
                strcpy(eptr[j].Mobile_number, eptr[j+1].Mobile_number);
                strcpy(eptr[j].Mail_ID, eptr[j+1].Mail_ID);
            }
            contact_count--;
            printf("Contact deleted.\n");
        }else{
            printf("Deletion cancelled.\n");
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
                    if(!isdigit(target_mobile_number[i])){ is_valid = 0; break; }
                }
            }
            if(!is_valid) printf("Invalid! Mobile number must be 10 digits.\n");
        }while(!is_valid);

        // Find contact by mobile
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mobile_number, target_mobile_number)==0){ index = i; break; }
        }
        if(index == -1){
            printf("No user found with mobile no %s\n\n", target_mobile_number);
            break;
        }

        // Confirm before deleting
        printf("Are you sure you want to delete this contact?\n");
        printf("%s %s %s\n", eptr[index].Name, eptr[index].Mobile_number, eptr[index].Mail_ID);
        printf("[Y/N]: ");
        scanf(" %c", &confirm);

        if(confirm=='Y' || confirm=='y'){
            for(int j=index; j<size-1; j++){
                strcpy(eptr[j].Name, eptr[j+1].Name);
                strcpy(eptr[j].Mobile_number, eptr[j+1].Mobile_number);
                strcpy(eptr[j].Mail_ID, eptr[j+1].Mail_ID);
            }
            contact_count--;
            printf("Contact deleted.\n");
        }else{
            printf("Deletion cancelled.\n");
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
                if(isupper(target_email[i])){ is_valid = 0; break; }
            }
            if(!is_valid) printf("Invalid! Email must be lowercase.\n");
        }while(!is_valid);

        // Find contact by email
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].Mail_ID, target_email)==0){ index = i; break; }
        }
        if(index == -1){
            printf("No user found with email-id %s\n\n", target_email);
            break;
        }

        // Confirm before deleting
        printf("Are you sure you want to delete this contact?\n");
        printf("%s %s %s\n", eptr[index].Name, eptr[index].Mobile_number, eptr[index].Mail_ID);
        printf("[Y/N]: ");
        scanf(" %c", &confirm);

        if(confirm=='Y' || confirm=='y'){
            for(int j=index; j<size-1; j++){
                strcpy(eptr[j].Name, eptr[j+1].Name);
                strcpy(eptr[j].Mobile_number, eptr[j+1].Mobile_number);
                strcpy(eptr[j].Mail_ID, eptr[j+1].Mail_ID);
            }
            contact_count--;
            printf("Contact deleted.\n");
        }else{
            printf("Deletion cancelled.\n");
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
    // Open file in write mode (overwrites previous data)
    FILE *fp = fopen("contacts.txt","w");
    if(fp==NULL){ printf("File Not Open\n"); return; }

    // Write each contact as a line
    for(int i=0; i<*contact_count; i++){
        fprintf(fp,"%s %s %s\n",contact_details[i].Name,contact_details[i].Mobile_number,contact_details[i].Mail_ID);
    }
    fclose(fp);
    printf("Contacts Saved Successfully.\n");
}

void load_contacts(struct Contacts contact_details[], int *contact_count){
    // Open file in read mode
    FILE *fp = fopen("contacts.txt","r");
    if(fp==NULL){ printf("No contacts file found.\n"); return; }

    // Read contacts until EOF
    while(fscanf(fp,"%s %s %s\n",contact_details[*contact_count].Name,contact_details[*contact_count].Mobile_number,contact_details[*contact_count].Mail_ID)==3){
        (*contact_count)++;
    }
    printf("%d contacts loaded successfully.\n", *contact_count);
    fclose(fp);
}