/*
    Name : Raghu G S
    Date : 08-04-2025
    Aim  : The aim of this project is to implement an address book as per all the requirements of Phase I in the SRS document 
    Address_Book_HLD.odt
    Descripton : 
        Address Book is an application written in C. It can work on all platforms which have a C compiler or cross-compiler.
    The application keeps track of contact names and telephone/mobile numbers and e-mail addresses. It is a console application
    which uses standard C I/O for adding names, phone numbers and e-mail addresses, searching names and associated numbers and
    email addresses, updating numbers and email addresses, and deleting contacts.
*/
#include<stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                printf("\nSelect sort criteria:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("Enter your choice: ");
                int sortChoice;
                scanf(" %d", &sortChoice);
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                printf("\nSaving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("\n***Invalid choice. Please try again.***\n");
        }
    } while (choice != 6);
    
       return 0;
}
