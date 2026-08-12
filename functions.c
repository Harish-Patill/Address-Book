#include "project_header.h"

void list_all(struct Contacts *eptr){
    for(int i=0;i<contact_count;i++){
        printf("%s %s %s\n",eptr[i].name,eptr[i].number,eptr[i].email);
    }
}


/* Completed
Validations: 
    - Name should be only be alphabet

    - Mobile number should be only 10 digits
    - Mobile number should be only digits
    - no duplicates

    - @ or . should not be missing
    - if @ comes after . then invalid email as it contains no domain
    - length cant be less than 7, as 7 is the lowest an email can be
    - must end with .com
    - no duplicates
*/
void create_contacts(struct Contacts *eptr,int max_size){
    int add_contacts_flag=0;
    int add_contacts_loop=1;
    char add_contacts_user_input;
    
    if(contact_count >= max_size){                                                              //to keep track of the address books capacity
        printf("Address Book is Full!\nDelete few Contacts if you want to Continue\n");
        return;
    }
    
    while(add_contacts_loop){                                                                   // Run in a loop to add as many contacts
        
        do{                                                                                     // Name input with validation
            add_contacts_flag=0;
            printf("\nEnter Name: ");
            scanf(" %[^\n]",eptr[contact_count].name);

            for(int i=0;i<strlen(eptr[contact_count].name);i++){
                if(isalpha(eptr[contact_count].name[i]) == 0){
                    add_contacts_flag=1;
                    break;
                }
            }
            if(add_contacts_flag){
                printf("Enter Valid Name, Only letters allowed.\n");
            }

        }while(add_contacts_flag);
        
        do{                                                                                      // Mobile Number input with validation 
            add_contacts_flag=0;
            printf("Enter Mobile Number: ");
            scanf(" %[^\n]",eptr[contact_count].number);

            if(strlen(eptr[contact_count].number) != 10){                                       // M.no Length should be always 10
                if(strlen(eptr[contact_count].number)>10){
                    printf("Length must not exceed 10.\n");
                }
                else if(strlen(eptr[contact_count].number)<10){
                    printf("Length must not be less than 10.\n");
                }
                add_contacts_flag=1;
            }
            else{                                                                               // M.no should be number only
                for(int i=0;i<strlen(eptr[contact_count].number);i++){
                    if(isdigit(eptr[contact_count].number[i]) == 0){
                        add_contacts_flag=1;
                        break;
                    }
                }
                if(add_contacts_flag){
                    printf("Enter Valid Mobile Number, Only Digits.\n");
                }
            }

            if(!add_contacts_flag){                                                             // M.no should be unique
                for(int i=0;i<contact_count;i++){
                    if(strcmp(eptr[i].number,eptr[contact_count].number) == 0){
                        add_contacts_flag=1;
                        printf("Mobile Number already Exists.\n");
                        break;
                    }
                }
            }

        }while(add_contacts_flag);

        do{
            add_contacts_flag=0;

            printf("Enter Email-ID: ");
            scanf(" %[^\n]",eptr[contact_count].email);
        
            int len = strlen(eptr[contact_count].email);
            char *at_position_ptr = strchr(eptr[contact_count].email, '@');     // finds @ position
            char *dot_position_ptr = strrchr(eptr[contact_count].email, '.');   // finds . position
        
            if(at_position_ptr == NULL || dot_position_ptr == NULL){            // check @ exists
                if(at_position_ptr == NULL){
                    printf("Invalid Email, must contain '@'\n");
                }
                else{
                    printf("Invalid Email, must contain '.'\n");
                }
                add_contacts_flag=1;
            }   
            else if(at_position_ptr > dot_position_ptr){                        // check for poper domain in email
                add_contacts_flag=1;
                printf("Invalid Email, dosent contain proper domain\n");
            }
            else if(len < 7){                                                   // minimum: a@b.com = 7 chars
                add_contacts_flag=1;
                printf("Invalid Email, too short.\n");
            }
            else if((dot_position_ptr - at_position_ptr) < 2){                  // check for proper domain
                add_contacts_flag=1;
                printf("Invalid Email, doesn't contain domain\n");
            }
            else if(strcmp(&eptr[contact_count].email[len-4], ".com") != 0){    // chekck email ends with .com
                add_contacts_flag=1;
                printf("Invalid Email, must end with .com\n");
            }
            else{
                for(int i=0;i<contact_count;i++){                               // check duplicate
                    if(strcmp(eptr[i].email, eptr[contact_count].email) == 0){
                        add_contacts_flag=1;
                        printf("Email already exists.\n");
                        break;
                    }
                }
            }
        }while(add_contacts_flag);
        
        contact_count++;
        
        printf("\nDo you want to add another contact? [Y/n]: ");
        scanf(" %c",&add_contacts_user_input);

        if(add_contacts_user_input == 'Y' || add_contacts_user_input == 'y'){
            add_contacts_loop=1;
        }
        else{
            add_contacts_loop=0;
        }
    }
}


/* Completed
Validations:
    - Searched contact should be present, if not proper validation statement must be printed
    - when taking input so search to edit a contact, it must be valid
    - while editing, the new info must be valid too
*/
void edit_contacts(struct Contacts *eptr,int size){
    int name_count=0;
    int edit_flag=0;
    int new_info_validation_flag=0;
    int validaion_edit_flag=0;
    int user_edit_option=0;
    int sub_user_edit_option=0;
    char edit_name[50];
    char edit_number[11];
    char edit_email[50];
    
    printf("\nSeach the Contact you want to edit using any of the below options\n1. Name\n2. Mobile Number\n3. Email-ID\n4. Exit\nEnter Here: ");
    scanf("%d",&user_edit_option);
    
    switch(user_edit_option){
    case 1:{

        do{
            validaion_edit_flag=0;

            printf("Enter the Name: ");
            scanf(" %[^\n]",edit_name);

            for(int i=0;i<strlen(edit_name);i++){                             // should be only alphabets
                if(isalpha(edit_name[i]) == 0 && edit_name[i] != ' '){
                    validaion_edit_flag=1;
                    break;
                }
            }
            if(validaion_edit_flag){
                printf("Enter Valid Name, Only letters allowed.\n");
            }
                
        }while(validaion_edit_flag);

        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].name,edit_name) == 0){
                name_count++;
            }
        }
        if(name_count>1){                                                                                   // when multiple contacts with same name
            printf("\nThere are %d contacts with the same name as '%s'\n",name_count,edit_name);

            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].name,edit_name) == 0){
                    printf("%s %s %s\n",eptr[i].name,eptr[i].number,eptr[i].email);
                }
            }
            
            printf("\nEdit the contact by searching for Mobile Number or Email instead\n");
            
            printf("1. Mobile Number\n2. Email-ID\nSelect any of the above options: ");
            scanf("%d",&sub_user_edit_option);
            
            switch(sub_user_edit_option){                                                                   // so will edit the contact by searching using email or mobile
                case 1:{

                    do{
                        validaion_edit_flag=0;

                        printf("Enter the Mobile Number: ");
                        scanf(" %[^\n]",edit_number);

                         if(strlen(edit_number) != 10){                                       // M.no Length should be always 10
                            if(strlen(edit_number)>10){
                                printf("Length must not exceed 10.\n");
                            }
                            else if(strlen(edit_number)<10){
                                printf("Length must not be less than 10.\n");
                            }
                            validaion_edit_flag=1;
                        }
                    }while(validaion_edit_flag);
                    
                    for(int i=0;i<size;i++){
                        if(strcmp(eptr[i].number,edit_number) == 0){
                            
                            printf("\nEnter New Details Below:\n");

                            do{
                                new_info_validation_flag=0;

                                printf("Enter Name: ");
                                scanf(" %[^\n]",eptr[i].name);

                                for(int j=0; j<strlen(eptr[i].name); j++){
                                    if(isalpha(eptr[i].name[j]) == 0 && eptr[i].name[j] != ' '){
                                        new_info_validation_flag=1;
                                        break;
                                    }
                                }
                                if(new_info_validation_flag){
                                    printf("Enter Valid Name, Only letters allowed.\n");
                                }

                            }while(new_info_validation_flag);

                            
                            do{
                                new_info_validation_flag=0;

                                printf("Enter Mobile Number: ");
                                scanf("%s",eptr[i].number);

                                if(strlen(eptr[i].number) != 10){                                       // M.no Length should be always 10
                                    if(strlen(eptr[i].number)>10){
                                        printf("Length must not exceed 10.\n");
                                    }
                                    else if(strlen(eptr[i].number)<10){
                                        printf("Length must not be less than 10.\n");
                                    }
                                    new_info_validation_flag=1;
                                }
                                else{                                                                  // M.no should be number only
                                    for(int j=0; j<strlen(eptr[i].number); j++){
                                        if(isdigit(eptr[i].number[j]) == 0){
                                            new_info_validation_flag=1;
                                            break;
                                        }   
                                    }
                                    if(new_info_validation_flag){
                                    printf("Enter Valid Mobile Number, Only Digits.\n");
                                    }
                                }                    

                            }while(new_info_validation_flag);


                            do{
                                new_info_validation_flag=0;

                                printf("Enter Email-ID: ");
                                scanf("%s",eptr[i].email);

                                int len = strlen(eptr[i].email);                                         // finding length of email
                                char *at_position_ptr = strchr(eptr[i].email, '@');                      // finding @ position
                                char *dot_position_ptr = strrchr(eptr[i].email, '.');                    // finding . position

                                if(at_position_ptr == NULL || dot_position_ptr == NULL){                // email not having @/.
                                    if(at_position_ptr == NULL){
                                        printf("Invalid Email, must contain '@'\n");
                                    }
                                    else{
                                        printf("Invalid Email, must contain '.'\n");
                                    }
                                    new_info_validation_flag=1;
                                }
                                else if((dot_position_ptr - at_position_ptr) < 2){                  // check for proper domain
                                    new_info_validation_flag=1;
                                    printf("Invalid Email, doesn't contain domain\n");
                                }   
                                else if(at_position_ptr > dot_position_ptr){                            // imporper domain 
                                    new_info_validation_flag=1;
                                    printf("Invalid Email, doesn't contain proper domain\n");
                                }
                                else if(len < 7){                                                       // invalid as it is too short
                                    new_info_validation_flag=1;
                                    printf("Invalid Email, too short.\n");
                                }
                                else if(strcmp(&eptr[i].email[len-4], ".com") != 0){                    // invalid as it dosent end with .com
                                    new_info_validation_flag=1;
                                    printf("Invalid Email, must end with .com\n");
                                }
                                

                            }while(new_info_validation_flag);
                            

                            printf("\nContact Edited Succesfully\n");
                            printf("Returning to main menu...\n");
                            sleep(1);
                            
                            edit_flag=1;
                        }
                    }
                    if(!edit_flag) printf("Couldn't find any contact with name %s\n",edit_number);
                    break;
                }
                
                case 2:{

                    do{
                        new_info_validation_flag=0;

                        printf("Enter the Email-ID: ");
                        scanf(" %[^\n]",edit_email);

                        int len = strlen(edit_email);                                         // finding length of email
                        char *at_position_ptr = strchr(edit_email, '@');                      // finding @ position
                        char *dot_position_ptr = strrchr(edit_email, '.');                    // finding . position

                        if(at_position_ptr == NULL || dot_position_ptr == NULL){                // email not having @/.
                            if(at_position_ptr == NULL){
                                printf("Invalid Email, must contain '@'\n");
                            }
                            else{
                                printf("Invalid Email, must contain '.'\n");
                            }
                            new_info_validation_flag=1;
                        }
                        else if((dot_position_ptr - at_position_ptr) < 2){                  // domain check
                            new_info_validation_flag=1;
                            printf("Invalid Email, doesn't contain domain\n");
                        }      
                        else if(at_position_ptr > dot_position_ptr){                            // imporper domain 
                            new_info_validation_flag=1;
                            printf("Invalid Email, doesn't contain proper domain\n");
                        }
                        else if(len < 7){                                                       // invalid as it is too short
                            new_info_validation_flag=1;
                            printf("Invalid Email, too short.\n");
                        }
                        else if(strcmp(&edit_email[len-4], ".com") != 0){                    // invalid as it dosent end with .com
                            new_info_validation_flag=1;
                            printf("Invalid Email, must end with .com\n");
                        }
                        

                    }while(new_info_validation_flag);
                    
                    
                    for(int i=0;i<size;i++){
                        if(strcmp(eptr[i].email,edit_email) == 0){
                            printf("\nEnter New Details Below:\n");
                            
                            do{
                                new_info_validation_flag=0;

                                printf("Enter Name: ");
                                scanf(" %[^\n]",eptr[i].name);

                                for(int j=0; j<strlen(eptr[i].name); j++){
                                    if(isalpha(eptr[i].name[j]) == 0 && eptr[i].name[j] != ' '){
                                        new_info_validation_flag=1;
                                        break;
                                    }
                                }
                                if(new_info_validation_flag){
                                    printf("Enter Valid Name, Only letters allowed.\n");
                                }

                            }while(new_info_validation_flag);

                            
                            do{
                                new_info_validation_flag=0;

                                printf("Enter Mobile Number: ");
                                scanf("%s",eptr[i].number);

                                if(strlen(eptr[i].number) != 10){                                       // M.no Length should be always 10
                                    if(strlen(eptr[i].number)>10){
                                        printf("Length must not exceed 10.\n");
                                    }
                                    else if(strlen(eptr[i].number)<10){
                                        printf("Length must not be less than 10.\n");
                                    }
                                    new_info_validation_flag=1;
                                }
                                else{                                                                  // M.no should be number only
                                    for(int j=0; j<strlen(eptr[i].number); j++){
                                        if(isdigit(eptr[i].number[j]) == 0){
                                            new_info_validation_flag=1;
                                            break;
                                        }
                                    }
                                    if(new_info_validation_flag){
                                    printf("Enter Valid Mobile Number, Only Digits.\n");
                                    }
                                }                    

                            }while(new_info_validation_flag);


                            do{
                                new_info_validation_flag=0;

                                printf("Enter Email-ID: ");
                                scanf("%s",eptr[i].email);

                                int len = strlen(eptr[i].email);                                         // finding length of email
                                char *at_position_ptr = strchr(eptr[i].email, '@');                      // finding @ position
                                char *dot_position_ptr = strrchr(eptr[i].email, '.');                    // finding . position

                                if(at_position_ptr == NULL || dot_position_ptr == NULL){                // email not having @/.
                                    if(at_position_ptr == NULL){
                                        printf("Invalid Email, must contain '@'\n");
                                    }
                                    else{
                                        printf("Invalid Email, must contain '.'\n");
                                    }
                                    new_info_validation_flag=1;
                                }   
                                else if(at_position_ptr > dot_position_ptr){                            // imporper domain 
                                    new_info_validation_flag=1;
                                    printf("Invalid Email, doesn't contain proper domain\n");
                                }
                                else if((dot_position_ptr - at_position_ptr) < 2){                  // domain check
                                    new_info_validation_flag=1;
                                    printf("Invalid Email, doesn't contain domain\n");
                                } 
                                else if(len < 7){                                                       // invalid as it is too short
                                    new_info_validation_flag=1;
                                    printf("Invalid Email, too short.\n");
                                }
                                else if(strcmp(&eptr[i].email[len-4], ".com") != 0){                    // invalid as it dosent end with .com
                                    new_info_validation_flag=1;
                                    printf("Invalid Email, must end with .com\n");
                                }
                                

                            }while(new_info_validation_flag);
                            
                            printf("\nContact Edited Succesfully\n");
                            printf("Returning to main menu...\n");
                            sleep(1);
                            
                            edit_flag=1;
                        }
                    }
                    if(!edit_flag) printf("Couldn't find any contact with name %s\n",edit_email);
                    break;
                }
            }
        }


        if(name_count==1){                                                          // normal, no multiple contacts with same name
            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].name,edit_name) == 0){
                    printf("\nEnter New Details Below:\n");
                    
                    do{
                        new_info_validation_flag=0;

                        printf("Enter Name: ");
                        scanf(" %[^\n]",eptr[i].name);

                        for(int j=0; j<strlen(eptr[i].name); j++){
                            if(isalpha(eptr[i].name[j]) == 0 && eptr[i].name[j] != ' '){
                                new_info_validation_flag=1;
                                break;
                            }
                        }
                        if(new_info_validation_flag){
                            printf("Enter Valid Name, Only letters allowed.\n");
                        }

                    }while(new_info_validation_flag);

                            
                    do{
                        new_info_validation_flag=0;

                        printf("Enter Mobile Number: ");
                        scanf("%s",eptr[i].number);

                        if(strlen(eptr[i].number) != 10){                                       // M.no Length should be always 10
                            if(strlen(eptr[i].number)>10){
                                printf("Length must not exceed 10.\n");
                            }
                            else if(strlen(eptr[i].number)<10){
                                printf("Length must not be less than 10.\n");
                            }
                            new_info_validation_flag=1;
                        }
                        else{                                                                  // M.no should be number only
                            for(int j=0; j<strlen(eptr[i].number); j++){
                                if(isdigit(eptr[i].number[j]) == 0){
                                    new_info_validation_flag=1;
                                    break;
                                }
                            }
                            if(new_info_validation_flag){
                            printf("Enter Valid Mobile Number, Only Digits.\n");
                            }
                        }                    

                    }while(new_info_validation_flag);
                    

                    do{
                        new_info_validation_flag=0;

                        printf("Enter Email-ID: ");
                        scanf("%s",eptr[i].email);

                        int len = strlen(eptr[i].email);                                         // finding length of email
                        char *at_position_ptr = strchr(eptr[i].email, '@');                      // finding @ position
                        char *dot_position_ptr = strrchr(eptr[i].email, '.');                    // finding . position

                        if(at_position_ptr == NULL || dot_position_ptr == NULL){                // email not having @/.
                            if(at_position_ptr == NULL){
                                printf("Invalid Email, must contain '@'\n");
                            }
                            else{
                                printf("Invalid Email, must contain '.'\n");
                            }
                            new_info_validation_flag=1;
                        }   
                        else if(at_position_ptr > dot_position_ptr){                            // imporper domain 
                            new_info_validation_flag=1;
                            printf("Invalid Email, doesn't contain proper domain\n");
                        }
                        else if((dot_position_ptr - at_position_ptr) < 2){                  // domain check
                            new_info_validation_flag=1;
                            printf("Invalid Email, doesn't contain domain\n");
                        } 
                        else if(len < 7){                                                       // invalid as it is too short
                            new_info_validation_flag=1;
                            printf("Invalid Email, too short.\n");
                        }
                        else if(strcmp(&eptr[i].email[len-4], ".com") != 0){                    // invalid as it dosent end with .com
                            new_info_validation_flag=1;
                            printf("Invalid Email, must end with .com\n");
                        }
                        

                    }while(new_info_validation_flag);
                    
                    printf("\nContact Edited Succesfully\n");
                    printf("Returning to main menu...\n");
                    sleep(1);
                    
                    edit_flag=1;
                }
            }
            if(!edit_flag) printf("Couldn't find any contact with name %s\n",edit_name);
            break;
        }

        if(name_count == 0){                                                        // if no matches are found, will print that no matches are there.
            printf("No Contact found with the Name '%s'\n",edit_name);
        }
        break;
    }
    
    case 2:{

        do{
            validaion_edit_flag=0;
    
            printf("Enter the Mobile Number: ");
            scanf(" %[^\n]",edit_number);
    
            if(strlen(edit_number) != 10){
                if(strlen(edit_number)>10){
                    printf("Length must not exceed 10.\n");
                }
                else if(strlen(edit_number)<10){
                    printf("Length must not be less than 10.\n");
                }
                validaion_edit_flag=1;
            }
            else{
                for(int i=0;i<strlen(edit_number);i++){
                    if(isdigit(edit_number[i]) == 0){
                        validaion_edit_flag=1;
                        break;
                    }
                }
                if(validaion_edit_flag){
                    printf("Enter Valid Mobile Number, Only Digits.\n");
                }
            }
        }while(validaion_edit_flag);
    
        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].number,edit_number) == 0){
                printf("\nEnter New Details Below:\n");
    
                do{
                    new_info_validation_flag=0;
    
                    printf("Enter Name: ");
                    scanf(" %[^\n]",eptr[i].name);
    
                    for(int j=0; j<strlen(eptr[i].name); j++){
                        if(isalpha(eptr[i].name[j]) == 0 && eptr[i].name[j] != ' '){
                            new_info_validation_flag=1;
                            break;
                        }
                    }
                    if(new_info_validation_flag){
                        printf("Enter Valid Name, Only letters allowed.\n");
                    }
                }while(new_info_validation_flag);
    
                do{
                    new_info_validation_flag=0;
    
                    printf("Enter Mobile Number: ");
                    scanf("%s",eptr[i].number);
    
                    if(strlen(eptr[i].number) != 10){
                        if(strlen(eptr[i].number)>10){
                            printf("Length must not exceed 10.\n");
                        }
                        else if(strlen(eptr[i].number)<10){
                            printf("Length must not be less than 10.\n");
                        }
                        new_info_validation_flag=1;
                    }
                    else{
                        for(int j=0; j<strlen(eptr[i].number); j++){
                            if(isdigit(eptr[i].number[j]) == 0){
                                new_info_validation_flag=1;
                                break;
                            }
                        }
                        if(new_info_validation_flag){
                            printf("Enter Valid Mobile Number, Only Digits.\n");
                        }
                    }
                }while(new_info_validation_flag);
    
                do{
                    new_info_validation_flag=0;
    
                    printf("Enter Email-ID: ");
                    scanf("%s",eptr[i].email);
    
                    int len = strlen(eptr[i].email);
                    char *at_position_ptr = strchr(eptr[i].email, '@');
                    char *dot_position_ptr = strrchr(eptr[i].email, '.');
    
                    if(at_position_ptr == NULL || dot_position_ptr == NULL){
                        if(at_position_ptr == NULL){
                            printf("Invalid Email, must contain '@'\n");
                        }
                        else{
                            printf("Invalid Email, must contain '.'\n");
                        }
                        new_info_validation_flag=1;
                    }
                    else if(at_position_ptr > dot_position_ptr){
                        new_info_validation_flag=1;
                        printf("Invalid Email, doesn't contain proper domain\n");
                    }
                    else if((dot_position_ptr - at_position_ptr) < 2){                  // domain check
                        new_info_validation_flag=1;
                        printf("Invalid Email, doesn't contain domain\n");
                    } 
                    else if(len < 7){
                        new_info_validation_flag=1;
                        printf("Invalid Email, too short.\n");
                    }
                    else if(strcmp(&eptr[i].email[len-4], ".com") != 0){
                        new_info_validation_flag=1;
                        printf("Invalid Email, must end with .com\n");
                    }
                }while(new_info_validation_flag);
    
                printf("\nContact Edited Succesfully\n");
                printf("Returning to main menu...\n");
                sleep(1);
    
                edit_flag=1;
            }
        }
        if(!edit_flag) printf("Couldn't find any contact with Mobile Number %s\n",edit_number);

        break;
    }  
    
    case 3:{
        do{
            validaion_edit_flag=0;

            printf("Enter the Email-ID: ");
            scanf(" %[^\n]",edit_email);

            int len = strlen(edit_email);
            char *at_position_ptr = strchr(edit_email, '@');
            char *dot_position_ptr = strrchr(edit_email, '.');

            if(at_position_ptr == NULL || dot_position_ptr == NULL){
                if(at_position_ptr == NULL){
                    printf("Invalid Email, must contain '@'\n");
                }
                else{
                    printf("Invalid Email, must contain '.'\n");
                }
                validaion_edit_flag=1;
            }
            else if((dot_position_ptr - at_position_ptr) < 2){                  // domain check
                validaion_edit_flag=1;
                printf("Invalid Email, doesn't contain domain\n");
            } 
            else if(at_position_ptr > dot_position_ptr){
                validaion_edit_flag=1;
                printf("Invalid Email, doesn't contain proper domain\n");
            }
            else if(len < 7){
                validaion_edit_flag=1;
                printf("Invalid Email, too short.\n");
            }
            else if(strcmp(&edit_email[len-4], ".com") != 0){
                validaion_edit_flag=1;
                printf("Invalid Email, must end with .com\n");
            }
        }while(validaion_edit_flag);

        for(int i=0;i<size;i++){
            if(strcmp(eptr[i].email,edit_email) == 0){
                printf("\nEnter New Details Below:\n");

                do{
                    new_info_validation_flag=0;

                    printf("Enter Name: ");
                    scanf(" %[^\n]",eptr[i].name);

                    for(int j=0; j<strlen(eptr[i].name); j++){
                        if(isalpha(eptr[i].name[j]) == 0 && eptr[i].name[j] != ' '){
                            new_info_validation_flag=1;
                            break;
                        }
                    }
                    if(new_info_validation_flag){
                        printf("Enter Valid Name, Only letters allowed.\n");
                    }
                }while(new_info_validation_flag);

                do{
                    new_info_validation_flag=0;

                    printf("Enter Mobile Number: ");
                    scanf("%s",eptr[i].number);

                    if(strlen(eptr[i].number) != 10){
                        if(strlen(eptr[i].number)>10){
                            printf("Length must not exceed 10.\n");
                        }
                        else if(strlen(eptr[i].number)<10){
                            printf("Length must not be less than 10.\n");
                        }
                        new_info_validation_flag=1;
                    }
                    else{
                        for(int j=0; j<strlen(eptr[i].number); j++){
                            if(isdigit(eptr[i].number[j]) == 0){
                                new_info_validation_flag=1;
                                break;
                            }
                        }
                        if(new_info_validation_flag){
                            printf("Enter Valid Mobile Number, Only Digits.\n");
                        }
                    }
                }while(new_info_validation_flag);

                do{
                    new_info_validation_flag=0;

                    printf("Enter Email-ID: ");
                    scanf("%s",eptr[i].email);

                    int len = strlen(eptr[i].email);
                    char *at_position_ptr = strchr(eptr[i].email, '@');
                    char *dot_position_ptr = strrchr(eptr[i].email, '.');

                    if(at_position_ptr == NULL || dot_position_ptr == NULL){
                        if(at_position_ptr == NULL){
                            printf("Invalid Email, must contain '@'\n");
                        }
                        else{
                            printf("Invalid Email, must contain '.'\n");
                        }
                        new_info_validation_flag=1;
                    }
                    else if((dot_position_ptr - at_position_ptr) < 2){                  // domain check
                        new_info_validation_flag=1;
                        printf("Invalid Email, doesn't contain domain\n");
                    }
                    else if(at_position_ptr > dot_position_ptr){
                        new_info_validation_flag=1;
                        printf("Invalid Email, doesn't contain proper domain\n");
                    }
                    else if(len < 7){
                        new_info_validation_flag=1;
                        printf("Invalid Email, too short.\n");
                    }
                    else if(strcmp(&eptr[i].email[len-4], ".com") != 0){
                        new_info_validation_flag=1;
                        printf("Invalid Email, must end with .com\n");
                    }
                }while(new_info_validation_flag);

                printf("\nContact Edited Succesfully\n");
                printf("Returning to main menu...\n");
                sleep(1);

                edit_flag=1;
            }
        }
        if(!edit_flag) printf("Couldn't find any contact with Email-ID %s\n",edit_email);
        break;
    }

    case 4:{
        user_edit_option=0;
        printf("Returning to Main Menu\n");
        sleep(1);       // 1 second
        break;
    }

    default:
    printf("Invalid Option! Please enter a valid option\n");
    }
}


/* Completed
Validations:
    -same input validations as in the 'add_contacts' function, except the 'input should be unique' validation,
     since we need a matching contact to print it in the terminal
*/
void search_contacts(struct Contacts *eptr){
    int search_contacts_error_flag=0;
    int search_flag=0;
    int user_search_option=0;
    char search_name[50];
    char search_number[50];
    char search_email[50];
    

    printf("\nSeach the Contact using any of the below options\n1. Name\n2. Mobile Number\n3. Email-ID\n4. Exit\nEnter Here: ");
    scanf("%d",&user_search_option);

    switch(user_search_option){
        case 1:{

            do{
                search_contacts_error_flag=0;

                printf("Enter the Name: ");
                scanf(" %[^\n]",search_name);

                for(int i=0;i<strlen(search_name);i++){                             // should be only alphabets
                    if(isalpha(search_name[i]) == 0){
                        search_contacts_error_flag=1;
                        break;
                    }
                }
                if(search_contacts_error_flag){
                    printf("Enter Valid Name, Only letters allowed.\n");
                }     

            }while(search_contacts_error_flag);
            
            for(int i=0;i<contact_count;i++){                                       // will print the contact details
                if(strcmp(eptr[i].name,search_name) == 0){
                    printf("%s %s %s",eptr[i].name,eptr[i].number,eptr[i].email);
                    search_flag=1;
                    printf("\n");
                }
            }
            if(!search_flag) printf("No contact found with Name %s\n",search_name);

            break;
        }

        case 2:{
            
            do{
                search_contacts_error_flag=0;

                printf("Enter the Number: ");
                scanf(" %[^\n]",search_number);
                
                if(strlen(search_number) != 10){                                       // M.no Length should be always 10
                    if(strlen(search_number)>10){
                        printf("Length must not exceed 10.\n");
                    }
                    else if(strlen(search_number)<10){
                        printf("Length must not be less than 10.\n");
                    }
                    search_contacts_error_flag=1;
                }
                else{                                                                  // M.no should be number only
                    for(int i=0;i<strlen(search_number);i++){
                        if(isdigit(search_number[i]) == 0){
                            search_contacts_error_flag=1;
                            break;
                        }
                    }
                    if(search_contacts_error_flag){
                    printf("Enter Valid Mobile Number, Only Digits.\n");
                    }
                }
                
            }while(search_contacts_error_flag);


            for(int i=0;i<contact_count;i++){                                          // Will print all the contact details
                if(strcmp(eptr[i].number,search_number) == 0){
                    printf("%s %s %s",eptr[i].name,eptr[i].number,eptr[i].email);
                    search_flag=1;
                    break;
                }
            }
            if(!search_flag) printf("No contact found with Mobile Number %s\n",search_number);
            break;
        }

        case 3:{

            do{
                search_contacts_error_flag=0;

                printf("Enter the Email-ID: ");
                scanf(" %[^\n]",search_email);

                int len = strlen(search_email);                                         // finding length of email
                char *at_position_ptr = strchr(search_email, '@');                      // finding @ position
                char *dot_position_ptr = strrchr(search_email, '.');                    // finding . position

                if(at_position_ptr == NULL || dot_position_ptr == NULL){                // email not having @/.
                    if(at_position_ptr == NULL){
                        printf("Invalid Email, must contain '@'\n");
                    }
                    else{   
                        printf("Invalid Email, must contain '.'\n");
                    }
                    search_contacts_error_flag=1;
                }
                else if((dot_position_ptr - at_position_ptr) < 2){                  // domain check
                    search_contacts_error_flag=1;
                    printf("Invalid Email, doesn't contain domain\n");
                }
                else if(at_position_ptr > dot_position_ptr){                            // imporper domain 
                    search_contacts_error_flag=1;
                    printf("Invalid Email, doesn't contain proper domain\n");
                }
                else if(len < 7){                                                       // invalid as it is too short
                    search_contacts_error_flag=1;
                    printf("Invalid Email, too short.\n");
                }
                else if(strcmp(&search_email[len-4], ".com") != 0){                    // invalid as it dosent end with .com
                    search_contacts_error_flag=1;
                    printf("Invalid Email, must end with .com\n");
                }

            }while(search_contacts_error_flag);

            for(int i=0;i<contact_count;i++){                                           // prints the contact details
                if(strcmp(eptr[i].email, search_email) == 0){
                    printf("%s %s %s\n",eptr[i].name,eptr[i].number,eptr[i].email);
                    search_flag=1;
                    break;
                }
            }
            if(!search_flag) printf("No contact found with Email %s\n",search_email);
            break;
        }

        case 4:{
            user_search_option=0;                                                       // going to main menu
            printf("Returning to Main Menu\n");
            sleep(1);       // 1 second
            break;
        }

        default:
            printf("Enter a Valid Input!, Try again\n");
            break;
    }
}


/* Completed
Validations: 
    - name_count if 1, greater than 1, or less than 1(0);
    - same validations as in the create_contacts
*/
void delete_contact(struct Contacts *eptr,int size){
    int delete_flag=0;
    int validation_flag=0;
    int name_count=0;
    int sub_user_delete_option=0;
    int user_delete_option=0;
    int index=0;
    char delete_confirmation;
    char delete_name[50];
    char delete_number[11];
    char delete_email[50];
    

    printf("\nSeach the Contact you want to delete using any of the below options\n1. Name\n2. Mobile Number\n3. Email-ID\n4. Exit\nEnter Here: ");
    scanf("%d",&user_delete_option);

    switch(user_delete_option){
        case 1:{

            do{
                validation_flag=0;

                printf("Enter Name: ");
                scanf(" %[^\n]",delete_name);

                for(int i=0;i<strlen(delete_name);i++){
                    if(isalpha(delete_name[i]) == 0 && delete_name[i] != ' '){
                        validation_flag=1;
                        break;
                    }
                }
                if(validation_flag){
                    printf("Enter Valid Name, Only letters allowed.\n");
                }
            }while(validation_flag);

            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].name,delete_name) == 0){
                    name_count++;
                }
            }

            if(name_count > 1){
                printf("\nThere are %d contacts with the same name as '%s'\n",name_count,delete_name);
                list_all(eptr);
                printf("\nDelete the contact by searching for Mobile Number or Email instead\n");

                printf("1. Mobile Number\n2. Email-ID\nSelect any of the above options: ");
                scanf("%d",&sub_user_delete_option);

                switch(sub_user_delete_option){
                    case 1:{

                        do{
                            validation_flag=0;

                            printf("Enter the Mobile Number: ");
                            scanf(" %[^\n]",delete_number);

                            if(strlen(delete_number) != 10){
                                if(strlen(delete_number)>10){
                                    printf("Length must not exceed 10.\n");
                                }
                                else if(strlen(delete_number)<10){
                                    printf("Length must not be less than 10.\n");
                                }
                                validation_flag=1;
                            }
                            else{
                                for(int i=0;i<strlen(delete_number);i++){
                                    if(isdigit(delete_number[i]) == 0){
                                        validation_flag=1;
                                        break;
                                    }
                                }
                                if(validation_flag){
                                    printf("Enter Valid Mobile Number, Only Digits.\n");
                                }
                            }
                        }while(validation_flag);

                        for(int i=0;i<size;i++){
                            if(strcmp(eptr[i].number,delete_number) == 0){
                                printf("Found Contact : %s %s %s\n",eptr[i].name,eptr[i].number,eptr[i].email);
                                delete_flag=1;
                                index=i;
                                break;
                            }
                        }
                        if(delete_flag){
                            printf("Are you sure you want to delete this contact?\n(Y/n):");
                            scanf(" %c",&delete_confirmation);

                            if(delete_confirmation == 'Y' || delete_confirmation == 'y'){
                                for(int i=index;i<size-1;i++){
                                    strcpy(eptr[i].name,eptr[i+1].name);
                                    strcpy(eptr[i].number,eptr[i+1].number);
                                    strcpy(eptr[i].email,eptr[i+1].email);
                                }
                                printf("\nContact Deleted\n");
                                printf("Returning to main menu...\n");
                                sleep(1);
                                contact_count--;
                            }
                            else printf("Deletion Cancelled\n");
                        }
                        else printf("No contact found with the Number '%s'\n",delete_number);
                        break;
                    }

                    case 2:{

                        do{
                            validation_flag=0;

                            printf("Enter the Email-ID: ");
                            scanf(" %[^\n]",delete_email);

                            int len = strlen(delete_email);
                            char *at_position_ptr = strchr(delete_email, '@');
                            char *dot_position_ptr = strrchr(delete_email, '.');

                            if(at_position_ptr == NULL || dot_position_ptr == NULL){
                                if(at_position_ptr == NULL){
                                    printf("Invalid Email, must contain '@'\n");
                                }
                                else{
                                    printf("Invalid Email, must contain '.'\n");
                                }
                                validation_flag=1;
                            }
                            else if((dot_position_ptr - at_position_ptr) < 2){                  // domain check
                                validation_flag=1;
                                printf("Invalid Email, doesn't contain domain\n");
                            }
                            else if(at_position_ptr > dot_position_ptr){
                                validation_flag=1;
                                printf("Invalid Email, doesn't contain proper domain\n");
                            }
                            else if(len < 7){
                                validation_flag=1;
                                printf("Invalid Email, too short.\n");
                            }
                            else if(strcmp(&delete_email[len-4], ".com") != 0){
                                validation_flag=1;
                                printf("Invalid Email, must end with .com\n");
                            }
                        }while(validation_flag);

                        for(int i=0;i<size;i++){
                            if(strcmp(eptr[i].email,delete_email) == 0){
                                printf("Found Contact : %s %s %s\n",eptr[i].name,eptr[i].number,eptr[i].email);
                                delete_flag=1;
                                index=i;
                                break;
                            }
                        }
                        if(delete_flag){
                            printf("Are you sure you want to delete this contact?\n(Y/n):");
                            scanf(" %c",&delete_confirmation);

                            if(delete_confirmation == 'Y' || delete_confirmation == 'y'){
                                for(int i=index;i<size-1;i++){
                                    strcpy(eptr[i].name,eptr[i+1].name);
                                    strcpy(eptr[i].number,eptr[i+1].number);
                                    strcpy(eptr[i].email,eptr[i+1].email);
                                }
                                printf("\nContact Deleted\n");
                                printf("Returning to main menu...\n");
                                sleep(1);
                                contact_count--;
                            }
                            else printf("Deletion Cancelled\n");
                        }
                        else printf("No contact found with the Mail-ID '%s'\n",delete_email);
                        break;
                    }
                }
            }
            else if(name_count == 1){
                for(int i=0;i<size;i++){
                    if(strcmp(eptr[i].name,delete_name) == 0){
                        printf("Found Contact : %s %s %s\n",eptr[i].name,eptr[i].number,eptr[i].email);
                        delete_flag=1;
                        index=i;
                        break;
                    }
                }
                if(delete_flag){
                    printf("Are you sure you want to delete this contact?\n(Y/n):");
                    scanf(" %c",&delete_confirmation);

                    if(delete_confirmation == 'Y' || delete_confirmation == 'y'){
                        for(int i=index;i<size-1;i++){
                            strcpy(eptr[i].name,eptr[i+1].name);
                            strcpy(eptr[i].number,eptr[i+1].number);
                            strcpy(eptr[i].email,eptr[i+1].email);
                        }
                        printf("\nContact Deleted\n");
                        printf("Returning to main menu...\n");
                        sleep(1);
                        contact_count--;
                    }
                    else printf("Deletion Cancelled\n");
                }
            }
            else{
                printf("No contact found with the name '%s'\n",delete_name);
            }

            break;
        }

        case 2:{

            do{
                validation_flag=0;

                printf("Enter the Mobile Number: ");
                scanf(" %[^\n]",delete_number);

                if(strlen(delete_number) != 10){
                    if(strlen(delete_number)>10){
                        printf("Length must not exceed 10.\n");
                    }
                    else if(strlen(delete_number)<10){
                        printf("Length must not be less than 10.\n");
                    }
                    validation_flag=1;
                }
                else{
                    for(int i=0;i<strlen(delete_number);i++){
                        if(isdigit(delete_number[i]) == 0){
                            validation_flag=1;
                            break;
                        }
                    }
                    if(validation_flag){
                        printf("Enter Valid Mobile Number, Only Digits.\n");
                    }
                }
            }while(validation_flag);

            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].number,delete_number) == 0){
                    printf("Found Contact : %s %s %s\n",eptr[i].name,eptr[i].number,eptr[i].email);
                    delete_flag=1;
                    index=i;
                    break;
                }
            }
            if(delete_flag){
                printf("Are you sure you want to delete this contact?\n(Y/n):");
                scanf(" %c",&delete_confirmation);

                if(delete_confirmation == 'Y' || delete_confirmation == 'y'){
                    for(int i=index;i<size-1;i++){
                        strcpy(eptr[i].name,eptr[i+1].name);
                        strcpy(eptr[i].number,eptr[i+1].number);
                        strcpy(eptr[i].email,eptr[i+1].email);
                    }
                    printf("\nContact Deleted\n");
                    printf("Returning to main menu...\n");
                    sleep(1);
                    contact_count--;
                }
                else printf("Deletion Cancelled\n");
            }
            else printf("No contact found with the Number '%s'\n",delete_number);

            break;
        }
        
        case 3:{

            do{
                validation_flag=0;

                printf("Enter the Mail-ID: ");
                scanf(" %[^\n]",delete_email);

                int len = strlen(delete_email);
                char *at_position_ptr = strchr(delete_email, '@');
                char *dot_position_ptr = strrchr(delete_email, '.');

                if(at_position_ptr == NULL || dot_position_ptr == NULL){
                    if(at_position_ptr == NULL){
                        printf("Invalid Email, must contain '@'\n");
                    }
                    else{
                        printf("Invalid Email, must contain '.'\n");
                    }
                    validation_flag=1;
                }
                else if(at_position_ptr > dot_position_ptr){
                    validation_flag=1;
                    printf("Invalid Email, doesn't contain proper domain\n");
                }
                else if((dot_position_ptr - at_position_ptr) < 2){                  // domain check
                    validation_flag=1;
                    printf("Invalid Email, doesn't contain domain\n");
                }
                else if(len < 7){
                    validation_flag=1;
                    printf("Invalid Email, too short.\n");
                }
                else if(strcmp(&delete_email[len-4], ".com") != 0){
                    validation_flag=1;
                    printf("Invalid Email, must end with .com\n");
                }
            }while(validation_flag);

            for(int i=0;i<size;i++){
                if(strcmp(eptr[i].email,delete_email) == 0){
                    printf("Found Contact : %s %s %s\n",eptr[i].name,eptr[i].number,eptr[i].email);
                    delete_flag=1;
                    index=i;
                    break;
                }
            }
            if(delete_flag){
                printf("Are you sure you want to delete this contact?\n(Y/n):");
                scanf(" %c",&delete_confirmation);
    
                if(delete_confirmation == 'Y' || delete_confirmation == 'y'){
                    for(int i=index;i<size-1;i++){
                        strcpy(eptr[i].name,eptr[i+1].name);
                        strcpy(eptr[i].number,eptr[i+1].number);
                        strcpy(eptr[i].email,eptr[i+1].email);
                    }
                    printf("\nContact Deleted\n");
                    printf("Returning to main menu...\n");
                    sleep(1);
                    contact_count--;
                }
                else printf("Deletion Cancelled\n");
            }
            else printf("No contact found with the Mail-ID '%s'\n",delete_email);

            break;     
        }

        case 4:{
            user_delete_option=0;
            printf("Returning to Main Menu\n");
            sleep(1);
            break;
        }
        
        default:
        printf("Enter a Valid Input!, Try again\n");
    }
}


/* Completed
Working:
    - Opens contacts.txt in write mode (wipes it)
    - Writes the entire array from index 0 to contact_count back to the file
    - Closes the file
*/
void save_contacts(struct Contacts *eptr){
    FILE *fptr = fopen("contacts.txt","w");

    if(fptr == NULL){                       // can get NULL if -No write permission in that directory -Disk is full -Invalid path
        printf("Error saving contacts!\n");
        return;
    }

    for(int i=0;i<contact_count;i++){
        fprintf(fptr,"%s\n%s\n%s\n",eptr[i].name,eptr[i].number,eptr[i].email);
    }
    fclose(fptr);
    printf("Contacts Saved Successfully\n");
}


/* Completed
Working:
    - Opens contacts.txt in read mode
    - Reads name, number, email
    - Increments contact_count for each contact read
    - If file doesn't exist, just returns
*/
void load_contacts(struct Contacts *eptr){
    FILE *fptr = fopen("contacts.txt","r");     // fopen will return any valid address if the fopen is succesful

    if(fptr == NULL){       // fopen returns NULL in case of -file not opening  -file not existing
        return;  
    }

    while(fscanf(fptr," %[^\n] %[^\n] %[^\n]",eptr[contact_count].name,eptr[contact_count].number,eptr[contact_count].email) == 3){
        contact_count++;
    }
    fclose(fptr);
}