#include <stdio.h>
#include <string.h>

#include "contacts.h"

void added_contact (struct contact *new_contact, int num_of_contact)
{
    printf("Please enter name of contacts:\n");
    fgets(new_contact[num_of_contact].name, 40, stdin);

    printf("Please enter phonenumber:\n");
    fgets(new_contact[num_of_contact].phone, 12, stdin);
}

void show_contacts(struct contact *contact, int num_of_contacts)
{
    int i;
    for (i = 0; i < num_of_contacts; i++) {
        printf("Name of contact %d:%s", i + 1, contact[i].name);
        printf("Number of contact %d:%s\n", i + 1, contact[i].phone);
    }
}

void search_contact(struct contact *contact, int num_of_contacts)
{
    int i = 0;
    char search[12];
    printf("Please enter phonenumber for search:\n");
    fgets(search, 12, stdin);
    while (i < num_of_contacts) {
        if (strcmp (search, contact[i].phone) == 0) {
            printf("Name of this contact:%s\n", contact[i].name);
            printf("Number of this contact:%s\n", contact[i].phone);
            return;
        }
        i++;
    }
    printf("Incorrect input\n");
}
