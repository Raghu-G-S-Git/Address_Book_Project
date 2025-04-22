#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    //Calling sorting function by given sort criteria
    switch(sortCriteria)
    {
        case 1:
            sortbyName(addressBook);
            break;
        case 2:
            sortbyNumber(addressBook);
            break;
        case 3:
            sortbyEmail(addressBook);
            break;
        default:
            printf("\n***Ivalid option!***\n\n");    
    }
    
}

// Function: sortbyName
void sortbyName(AddressBook *addressBook)
{
    // Sort contacts using bubble sort algorithm based on name
    // Swap name, phone, and email if they are out of order
    // Ask user for display order and print accordingly
    int option,i=0,j=0,k=addressBook->contactCount;

    for (i = 0; i < k - 1; i++)
     {
        for (j = 0; j < k - i - 1; j++) 
        {           
            if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) 
            {
                char temp[50];
                strcpy(temp, addressBook->contacts[j].name);
                strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
                strcpy(addressBook->contacts[j+1].name, temp);

                strcpy(temp, addressBook->contacts[j].phone);
                strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
                strcpy(addressBook->contacts[j+1].phone, temp);

                strcpy(temp, addressBook->contacts[j].email);
                strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
                strcpy(addressBook->contacts[j+1].email, temp);
            }
        }
    }

    printf("\nSort by:\n1. Ascending order\n2. Descending order\nEnter the option : ");
    scanf(" %d",&option);

    if(option ==  1)
    {
        printf("\t---------------------------------------------------------------------------------\n");
        printf("\t|\tNAME\t\t|\tMOBILE NUMBER\t|\tEMAIL ID\t\t|\n");
        printf("\t---------------------------------------------------------------------------------\n");
        for (int i = 0; i < addressBook->contactCount; i++) 
        {
            printf("\t|\t%s\t|\t%s\t|\t%s  \t|\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf("\t---------------------------------------------------------------------------------\n");
    }
    else if(option == 2)
    {
        printf("\t---------------------------------------------------------------------------------\n");
        printf("\t|\tNAME\t\t|\tMOBILE NUMBER\t|\tEMAIL ID\t\t|\n");
        printf("\t---------------------------------------------------------------------------------\n");
        for (int i = addressBook->contactCount - 1; i >= 0; i--) 
        {
            printf("\t|\t%s\t|\t%s\t|\t%s  \t|\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf("\t---------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n***Invalid Option!***\n\n");
    }
}

// Function: sortbyNumber
void sortbyNumber(AddressBook *addressBook)
{
    // Sort contacts using bubble sort algorithm based on phone number
    // Swap all fields of contact structure if phone numbers are out of order
    // Ask user for display order and print accordingly
    int option,i=0,j=0,k=addressBook->contactCount;

    for (i = 0; i < k - 1; i++)
     {
        for (j = 0; j < k - i - 1; j++) 
        {
            if (strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0) 
            {
                char temp[50];
                strcpy(temp, addressBook->contacts[j].name);
                strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
                strcpy(addressBook->contacts[j+1].name, temp);

                strcpy(temp, addressBook->contacts[j].phone);
                strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
                strcpy(addressBook->contacts[j+1].phone, temp);

                strcpy(temp, addressBook->contacts[j].email);
                strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
                strcpy(addressBook->contacts[j+1].email, temp);
            }
        }
    }

    printf("\nSort by:\n1. Ascending order\n2. Descending order\nEnter the option : ");
    scanf(" %d",&option);
    
    if(option ==  1)
    {
        printf("\t---------------------------------------------------------------------------------\n");
        printf("\t|\tNAME\t\t|\tMOBILE NUMBER\t|\tEMAIL ID\t\t|\n");
        printf("\t---------------------------------------------------------------------------------\n");
        for (int i = 0; i < addressBook->contactCount; i++) 
        {
            printf("\t|\t%s\t|\t%s\t|\t%s  \t|\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf("\t---------------------------------------------------------------------------------\n");
    }
    else if(option == 2)
    {
        printf("\t---------------------------------------------------------------------------------\n");
        printf("\t|\tNAME\t\t|\tMOBILE NUMBER\t|\tEMAIL ID\t\t|\n");
        printf("\t---------------------------------------------------------------------------------\n");
        for (int i = addressBook->contactCount - 1; i >= 0; i--) 
        {
            printf("\t|\t%s\t|\t%s\t|\t%s  \t|\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf("\t---------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n***Invalid Option!***\n\n");
    }
}

// Function: sortbyEmail
void sortbyEmail(AddressBook *addressBook)
{
    // Sort contacts using bubble sort algorithm based on email ID
    // Swap all fields if emails are out of order
    // Ask user for display order and print accordingl
    int option,i=0,j=0,k=addressBook->contactCount;

    for (i = 0; i < k - 1; i++)
     {
        for (j = 0; j < k - i - 1; j++) 
        {
            if (strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0) 
            {
                char temp[50];
                strcpy(temp, addressBook->contacts[j].name);
                strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
                strcpy(addressBook->contacts[j+1].name, temp);

                strcpy(temp, addressBook->contacts[j].phone);
                strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
                strcpy(addressBook->contacts[j+1].phone, temp);

                strcpy(temp, addressBook->contacts[j].email);
                strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
                strcpy(addressBook->contacts[j+1].email, temp);
            }
        }
    }

    printf("\nSort by:\n1. Ascending order\n2. Descending order\nEnter the option : ");
    scanf(" %d",&option);

    if(option ==  1)
    {
        printf("\t---------------------------------------------------------------------------------\n");
        printf("\t|\tNAME\t\t|\tMOBILE NUMBER\t|\tEMAIL ID\t\t|\n");
        printf("\t---------------------------------------------------------------------------------\n");
        for (int i = 0; i < addressBook->contactCount; i++) 
        {
            printf("\t|\t%s\t|\t%s\t|\t%s  \t|\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf("\t---------------------------------------------------------------------------------\n");
    }
    else if(option == 2)
    {
        printf("\t---------------------------------------------------------------------------------\n");
        printf("\t|\tNAME\t\t|\tMOBILE NUMBER\t|\tEMAIL ID\t\t|\n");
        printf("\t---------------------------------------------------------------------------------\n");
        for (int i = addressBook->contactCount - 1; i >= 0; i--) 
        {
            printf("\t|\t%s\t|\t%s\t|\t%s  \t|\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        printf("\t---------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n***Invalid Option!***\n\n");
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    create_name(addressBook);

    create_num(addressBook);

    create_email(addressBook); 
    
    printf("\n---Successfully Saved the Contact---\n");
}

void create_name(AddressBook *addressBook)
{
    char temp_name[50];
    //Run loop to scan name untill it is valid
    do
    {
        printf("Enter the Name : ");
        scanf(" %[^\n]",temp_name);
    }while(!valid_name(addressBook,temp_name));
    
    strcpy(addressBook->contacts[addressBook->contactCount].name,temp_name);
}

void create_num(AddressBook *addressBook)
{
    int i=0;
    char temp_num[20];
    //Run loop to scan phone number untill it is valid and unique
    do
    {
        printf("Enter the Mobile Number : ");
        scanf(" %s",temp_num);
    }while(!valid_num(addressBook,temp_num) || !isunique_num(addressBook,temp_num));

    strcpy(addressBook->contacts[addressBook->contactCount].phone,temp_num);
    
} 

void create_email(AddressBook *addressBook)
{
    int i=0;
    char temp_email[50];
    char a[]={".com"},b[]={"@"};
    //Run loop to scan email id untill it is valid and unique 
    do
    {
        printf("Enter the Email ID : ");
        scanf(" %s",temp_email);
    }while(!valid_email(addressBook,temp_email) || !isunique_email(addressBook,temp_email));

    strcpy(addressBook->contacts[addressBook->contactCount].email,temp_email);
    //After saving entire 1 contact info increment contact count
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    int option;
    printf("\nSearch by:\n1. Name.\n2. Mobile Number.\n3. Email ID.\nEnter the option : ");
    scanf(" %d",&option);
    switch(option)
    {
        case 1:
            searchName(addressBook);
            break;
        case 2:
            searchNumber(addressBook);
            break;
        case 3:
            searchEmail(addressBook);
            break;
        default:
            printf("\n***Invalid option!, Enter valid option(1/2/3).***\n\n");
            return;
    }
}

// Function: searchName
void searchName(AddressBook *addressBook)
{
    // Prompt user for name to search
    // Perform case-insensitive search for substring in contact names
    // Display all matching contacts
    int i=0,j=0;
    char name[50];
    
    do
    {
        printf("Enter the Name : ");
        scanf(" %[^\n]",name);
    }while(!valid_name(addressBook,name));
    
    i=0;
    printf("\t---------------------------------------------------------------------------------\n");
    printf("\t|\tNAME\t\t|\tMOBILE NUMBER\t|\tEMAIL ID\t\t|\n");
    printf("\t---------------------------------------------------------------------------------\n");
    while( i < addressBook->contactCount )
    {
        if ((strcasestr(addressBook->contacts[i].name,name) != NULL))
        {
            printf("\t|\t%s\t|\t%s\t|\t%s  \t|\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            j++;
        }
        i++;
    }
    printf("\t---------------------------------------------------------------------------------\n");
    printf("\n---%d Match Found---\n",j);
    
}

// Function: searchNumber
void searchNumber(AddressBook *addressBook)
{
    // Prompt user for number to search
    // Perform substring search in contact numbers
    // Display all matching contacts
    int i=0,j=0;
    char temp_num[20];

    do
    {
        printf("Enter the number : ");
        scanf(" %s",temp_num);
    }while(!valid_num(addressBook,temp_num));

    i=0;
    printf("\t---------------------------------------------------------------------------------\n");
    printf("\t|\tNAME\t\t|\tMOBILE NUMBER\t|\tEMAIL ID\t\t|\n");
    printf("\t---------------------------------------------------------------------------------\n");
    while( i < addressBook->contactCount )
    {
        if ((strcasestr(addressBook->contacts[i].phone,temp_num) != NULL))
        {
            printf("\t|\t%s\t|\t%s\t|\t%s  \t|\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            j++;
        }
        i++;
    }
    printf("\t---------------------------------------------------------------------------------\n");
    printf("\n---%d Match Found---\n",j);

}

// Function: searchEmail
void searchEmail(AddressBook *addressBook)
{
    // Prompt user for email to search
    // Perform substring search in email IDs
    // Display all matching contacts
    int i=0,j=0;
    char temp_email[50];

    do
    {
        printf("Enter the Email Id : ");
        scanf(" %s",temp_email);
    }while(!valid_email(addressBook,temp_email));

    i=0;
    printf("\t---------------------------------------------------------------------------------\n");
    printf("\t|\tNAME\t\t|\tMOBILE NUMBER\t|\tEMAIL ID\t\t|\n");
    printf("\t---------------------------------------------------------------------------------\n");
    while( i < addressBook->contactCount )
    {
        if ((strcasestr(addressBook->contacts[i].email,temp_email) != NULL))
        {
            printf("\t|\t%s\t|\t%s\t|\t%s  \t|\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            j++;
        }
        i++;
    }
    printf("\t---------------------------------------------------------------------------------\n");
    printf("\n---%d Match Found---\n",j);
}

// Function: editContact
void editContact(AddressBook *addressBook)
{
    // Allow user to search contact by name/number/email
    // If multiple matches, prompt user to choose one
    // Ask user which field to edit and call appropriate function
    int option,i=0,j=0,k=0;
    char temp_name[50],new_name[50];
    
    printf("\nSearch by:\n1. Name.\n2. Mobile Number.\n3. Email ID.\nEnter the option : ");
    scanf(" %d",&option);
    switch(option)
    {
        case 1:
            printf("Enter the name : ");
            scanf(" %[^\n]",temp_name);
            if(valid_name(addressBook,temp_name))
            {
                while( i < addressBook->contactCount )
                {
                    if ((strcasestr(addressBook->contacts[i].name,temp_name) != NULL))
                    {
                        printf("%d.\t%s\t%s\t%s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        k=i;
                        j++; 
                    }
                    i++;
                }
        
                if(j>1)
                {
                    printf("Enter the option number of contact want to be edited : ");
                    scanf(" %d",&i);
                }
                else if(j==0)
                {
                    printf("\n***Contact Not Found!***\n");
                    return;
                }
                else
                    i=k;
            }
            break;
        case 2:
            printf("Enter the number : ");
            scanf(" %s",temp_name);
            if(valid_num(addressBook,temp_name))
            {
                while( i < addressBook->contactCount )
                {
                    if ((strcasestr(addressBook->contacts[i].phone,temp_name) != NULL))
                    {
                        printf("%d.\t%s\t%s\t%s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        k=i;
                        j++; 
                    }
                    i++;
                }
        
                if(j>1)
                {
                    printf("Enter the option number of contact want to be edited : ");
                    scanf(" %d",&i);
                }
                else if(j==0)
                {
                    printf("\n***Contact Not Found!***\n");
                    return;
                }
                else
                    i=k;
            }
            break;
        case 3:
            printf("Enter the email : ");
            scanf(" %s",temp_name);
            if(valid_email(addressBook,temp_name))
            {
                while( i < addressBook->contactCount )
                {
                    if ((strcasestr(addressBook->contacts[i].email,temp_name) != NULL))
                    {
                        printf("%d.\t%s\t%s\t%s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        k=i;
                        j++; 
                    }
                    i++;
                }
        
                if(j>1)
                {
                    printf("Enter the option number of contact want to be edited : ");
                    scanf(" %d",&i);
                }
                else if(j==0)
                {
                    printf("\n***Contact Not Found!***\n");
                    return;
                }
                else
                    i=k;
            }
            break;
        default:
            printf("\n***Invalid option!, Enter valid option(1/2/3).***\n\n");
            return;
    }

	printf("\nWhich detial you want to edit : \n1. Name.\n2. Mobile Number.\n3. Email ID.\nSelect option : ");
    scanf(" %d",&option);

    switch(option)
    {
        case 1:
            editName(addressBook,i);
            break;
        case 2:
            editMobilenum(addressBook,i);
            break;
        case 3:
            editEmail(addressBook,i);
            break;
        default:
            printf("\n***Invalid Option!***\n\n");    
    }
    
}

void editName(AddressBook *addressBook, int i)
{
    char new_name[50];
        
    printf("Enter New Name : ");
    scanf(" %[^\n]",new_name);

    if(valid_name(addressBook,new_name))
    {
        strcpy(addressBook->contacts[i].name,new_name);
        printf("\n---Successfully Contact saved!---\n");
    }
    else
    {
        printf("\n---Contact Not saved!---\n");
    }
}

void editMobilenum(AddressBook *addressBook, int i)
{
    char new_num[20];
        
    printf("Enter New Number : ");
    scanf(" %s",new_num);

    if(valid_num(addressBook,new_num) && isunique_num(addressBook,new_num))
    {
        strcpy(addressBook->contacts[i].phone,new_num);
        printf("\n---Successfully Contact saved!---\n");
    }
    else
    {
        printf("\n---Contact Not saved!---\n");
    }    
}

void editEmail(AddressBook *addressBook, int i)
{
    char new_email[50];
        
    printf("Enter New Email : ");
    scanf(" %s",new_email);

    if(valid_email(addressBook,new_email) && isunique_email(addressBook,new_email))
    {
        strcpy(addressBook->contacts[i].email,new_email);
        printf("\n---Successfully Contact saved!---\n");
    }
    else
    {
        printf("\n---Contact Not saved!---\n");
    } 
}

// Function: deleteContact
void deleteContact(AddressBook *addressBook)
{
    // Allow user to search contact by name/number/email
    // Call respective deletion function
	int option;
    printf("Search by:\n1. Name.\n2. Mobile Number.\n3. Email ID.\nEnter the option : ");
    scanf(" %d",&option);
    switch(option)
    {
        case 1:
            deletebyName(addressBook);
            break;
        case 2:
            deletebyNumber(addressBook);
            break;
        case 3:
            deletebyEmail(addressBook);
            break;
        default:
            printf("\n***Invalid option!, Enter valid option(1/2/3).***\n\n");
            return;
    }
   
}

// Function: deletebyName
void deletebyName(AddressBook *addressBook)
{
    // Search for contacts by name
    // Confirm deletion and delete selected contact
    int i=0,j=0,k=0;
    char name[50],option;
    do
    {
        printf("Enter the Name : ");
        scanf(" %[^\n]",name);
    }while(!valid_name(addressBook,name));
    
    i=0;
    while( i < addressBook->contactCount )
    {
        if ((strcasestr(addressBook->contacts[i].name,name) != NULL))
        {
            printf("%d.\t%s\t%s\t%s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            k=i;
            j++;
        }
        i++;
    }

    if(j>1)
    {
        printf("\n---%d Match Found---\n\n",j);
        printf("Enter the option number of contact to be delete : ");
        scanf(" %d",&k);

    }
    else if(j==0)
    {
        printf("\n---No Match Found!---\n\n");
        return;
    }
    else if(j==1)
    {
        printf("\n---%d Match Found!---\n\n",j);
    }

    printf("Do you want to delete ?\nY -> Delete\nN -> Go back\n(Y/N) : ");
    scanf(" %c",&option);

    if(option == 'Y' || option == 'y')
    {
        while(k+1 < addressBook->contactCount)
        {
            addressBook->contacts[k] = addressBook->contacts[k+1];
            k++;
        }
        addressBook->contactCount--;
        printf("\n---Successfully deleted the contact---\n");
    }
    
}

// Function: deletebyNumber
void deletebyNumber(AddressBook *addressBook)
{
    // Search for contacts by number
    // Confirm deletion and delete selected contact
    int i=0,j=0,k=0;
    char num[20],option;   
    do
    {
        printf("Enter the Number : ");
        scanf(" %s",num);
    }while(!valid_num(addressBook,num));
    
    i=0;
    while( i < addressBook->contactCount )
    {
        if ((strcasestr(addressBook->contacts[i].phone,num) != NULL))
        {
            printf("%d.\t%s\t%s\t%s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            k=i;
            j++;
        }
        i++;
    }

    if(j>1)
    {
        printf("\n---%d Match Found---\n\n",j);
        printf("Enter the option number of contact to be delete : ");
        scanf(" %d",&k);

    }
    else if(j==0)
    {
        printf("\n---No Match Found!---\n\n");
        return;
    }
    else if(j==1)
    {
        printf("\n---%d Match Found!---\n\n",j);
    }

    printf("Do you want to delete ?\nY -> Delete\nN -> Go back\n(Y/N) : ");
    scanf(" %c",&option);

    if(option == 'Y' || option == 'y')
    {
        while(k+1 < addressBook->contactCount)
        {
            addressBook->contacts[k] = addressBook->contacts[k+1];
            k++;
        }
        addressBook->contactCount--;
        printf("\n---Successfully deleted the contact---\n");
    }
}

// Function: deletebyEmail
void deletebyEmail(AddressBook *addressBook)
{
    // Search for contacts by email
    // Confirm deletion and delete selected contact
    int i=0,j=0,k=0;
    char email[50],option;    
    do
    {
        printf("Enter the Email : ");
        scanf(" %s",email);
    }while(!valid_email(addressBook,email));
    
    i=0;
    while( i < addressBook->contactCount )
    {
        if ((strcasestr(addressBook->contacts[i].email,email) != NULL))
        {
            printf("%d.\t%s\t%s\t%s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            k=i;
            j++;
        }
        i++;
    }

    if(j>1)
    {
        printf("\n---%d Match Found---\n\n",j);
        printf("Enter the option number of contact to be delete : ");
        scanf(" %d",&k);

    }
    else if(j==0)
    {
        printf("\n---No Match Found!---\n\n");
        return;
    }
    else if(j==1)
    {
        printf("\n---%d Match Found!---\n\n",j);
    }

    printf("Do you want to delete ?\nY -> Delete\nN -> Go back\n(Y/N) : ");
    scanf(" %c",&option);

    if(option == 'Y' || option == 'y')
    {
        while(k+1 < addressBook->contactCount)
        {
            addressBook->contacts[k] = addressBook->contacts[k+1];
            k++;
        }
        addressBook->contactCount--;
        printf("\n---Successfully deleted the contact---\n\n");
    }
}

// Function: valid_name
int valid_name(AddressBook *addressBook,char temp_name[])
{
    // Check if name contains only alphabets and spaces
    int i=0;
    while(temp_name[i])
    {
        if(!(isalpha(temp_name[i]) || temp_name[i] == ' '))
        {
            printf("\n***Invalid Name!, Enter only Alphabets.***\n\n");
            return 0;
            break;
        }
        i++;
    }
    return 1;
}   
    
// Function: valid_num    
int valid_num(AddressBook *addressBook,char temp_num[])
{
    // Check if number is 10 digits and contains only numeric characters
    int i=0;
    if(strlen(temp_num) != 10)
    {
        printf("\n***Invalid number!, Enter only 10 digits numbers.***\n\n");
        return 0;
    }
    while(temp_num[i])
    {
        if( !(isdigit(temp_num[i])) )
        {
            printf("\n***Invalid number!, Enter only 10 digits numbers.***\n\n");
            return 0;
            break;
        }
        i++;
    }
    return 1;
}

// Function: valid_email
int valid_email(AddressBook *addressBook,char temp_email[])
{
    // Check if email contains both '@' and '.com'
    char a[]={".com"},b[]={"@"};
    if(!(strcasestr(temp_email,a) != NULL && strcasestr(temp_email,b) != NULL))
    {
        printf("\n***Invalid Email!, Enter in 'abc@xyz.com' format.***\n\n");
        return 0;
    }
}

// Function: isunique_num
int isunique_num(AddressBook *addressBook,char temp_num[])
{
        // Check if phone number is unique in the address book
    int i=0;
    while( i < addressBook->contactCount )
    {
        if (!(strcmp(addressBook->contacts[i].phone,temp_num)))
        {
            printf("\n***Number already exists!, enter new Number.***\n\n");
            return 0;
        }
        i++;
    }
    return 1;
}

// Function: isunique_email
int isunique_email(AddressBook *addressBook,char temp_email[])
{
    // Check if email ID is unique in the address book
    int i=0;
    while(i < addressBook->contactCount)
    {
        if (!(strcmp(addressBook->contacts[i].email,temp_email)))
        {
            printf("\n***Email already exists!, enter new Email.***\n\n");
            return 0;
        }
        i++;
    }
    return 1;
}