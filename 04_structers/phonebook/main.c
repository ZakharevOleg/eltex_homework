#include <stdio.h>

#include "menu.h"
#include "contacts.h"

int main()
{
    struct contact contacts[100];

    int number_of_menu = 1;
    int contact_count = 0;

    while(number_of_menu != 4) {

        number_of_menu = choise_menu();

        switch (number_of_menu) {
            case 1:
                added_contact(contacts, contact_count);
                contact_count++;
                break;
            case 2:
                show_contacts(contacts, contact_count);
                break;
            case 3:
                search_contact(contacts, contact_count);
                break;
            case 4:
                printf("Goodbye\n");
                return 0;
            default:
                printf("Incorrect input\n");
        }
    }

    return 0;
}
