# Address Book (C)

A simple command line Address Book application written in C, built as a multi file project to practice modular programming, struct-based data modeling, file I/O, and CRUD operations.

## Features

- Add a new contact with field validation (name, phone number, email, etc.)
- View all saved contacts
- Search for a contact
- Update an existing contact's details
- Delete a contact
- Save contacts to a file and load them back on startup (persistent storage)

## Project Structure

```
ADDRESS-BOOK/
├── main.c           # Program entry point, menu-driven interface
├── Makefile          # Build automation
├── functions.c        # Function definitions for CRUD operations and file I/O
├── contacts.txt        # Data file where contacts are stored (created at runtime)
├── project_header.h     # Struct definition and function prototypes
└── README.md
```

## Getting Started

### Prerequisites

- A C compiler (GCC recommended)
- `make` (optional, needed only if using the Makefile)

### Build

Using the Makefile:

```bash
make
```

Or manually:

```bash
gcc main.c functions.c -o addressbook
```

### Run

```bash
./addressbook
```

## Usage

On launch, you'll see a menu like:

```
==== ADDRESS BOOK ====
1. Add contacts             
2. Search contacts         
3. Edit contacts           
4. Delete contacts         
5. Display contacts        
6. Save and Exit           
7. Exit
```

Contacts entered during a session are saved to `contacts.txt` and automatically reloaded the next time you run the program.

## project_header.h Overview

```c
typedef struct{
    char name[50];
    char phone[15];
    char email[50];
}Contact;

void list_all(struct Contacts *eptr);                       
void save_contacts(struct Contacts *eptr);
void load_contacts(struct Contacts *eptr);
void search_contacts(struct Contacts *eptr);                
void edit_contacts(struct Contacts *eptr,int size);
void create_contacts(struct Contacts *eptr,int size);     
void delete_contact(struct Contacts *eptr,int size);
```
