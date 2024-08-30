#include <stdio.h>

#include "menu.h"
#include "contacts.h"
#include "saving.h"

int main()
{
    struct contact contacts[100];

    int number_of_menu = 0;
    int contact_count = 0;

    reading_contacts(contacts, &contact_count);

    while(number_of_menu != 4) {

        number_of_menu = choise_menu();

        switch (number_of_menu) {
            case 1:
                added_contact(contacts + contact_count);
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
                break;
            default:
                printf("Incorrect input\n");
        }
    }
    writing_to_file(contacts, contact_count);

    return 0;
}
