#include <stdio.h>

#include "menu.h"
#include "contacts.h"
#include "open_close.h"

int main()
{
    struct contact contacts[100];
    FILE *file_to_save = NULL;

    int number_of_menu = 1;
    int contact_count = 0;

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
            default:
                printf("Incorrect input\n");
        }
    }

    open_to_write(file_to_save);

    fwrite (&contacts, sizeof(struct contact), contact_count, file_to_save);

    close_file(file_to_save);

    return 0;
}
