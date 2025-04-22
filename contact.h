#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
void create_name(AddressBook *addressBook);
void create_num(AddressBook *addressBook);
void create_email(AddressBook *addressBook);
int valid_name(AddressBook *addressBook,char temp_name[]);
int valid_num(AddressBook *addressBook,char temp_num[]);
int valid_email(AddressBook *addressBook,char temp_email[]);
int isunique_num(AddressBook *addressBook,char temp_num[]);
int isunique_email(AddressBook *addressBook,char temp_email[]);
void searchName(AddressBook *addressBook);
void searchNumber(AddressBook *addressBook);
void searchEmail(AddressBook *addressBook);
void editName(AddressBook *addressBook, int i);
void editMobilenum(AddressBook *addressBook, int i);
void editEmail(AddressBook *addressBook, int i);
void deletebyName(AddressBook *addressBook);
void deletebyNumber(AddressBook *addressBook);
void deletebyEmail(AddressBook *addressBook);
void sortbyName(AddressBook *addressBook);
void sortbyNumber(AddressBook *addressBook);
void sortbyEmail(AddressBook *addressBook);

#endif
