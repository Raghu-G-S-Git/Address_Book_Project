#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr;
    fptr = fopen("contacts.csv","w");
    if(fptr == NULL)
    {
        printf("\n***Failed to open the file***\n");
        return;
    }
    int i=0;
    while(i < addressBook->contactCount)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        i++;
    }
    fclose(fptr);
  
}

void loadContactsFromFile(AddressBook *addressBook) {
    
    FILE *fptr;
    fptr = fopen("contacts.csv","r");
    if(fptr == NULL)
    {
        printf("\n***Failed to open the file***\n");
        return;
    }
    int count = 0;
    while(1)
    {
        count = fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[addressBook->contactCount].email);
        if(count != 3)
            break;
        addressBook->contactCount++;
    }
    fclose(fptr);
}
