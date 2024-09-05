#include <stdio.h>
#include <errno.h>

#include "contacts.h"
#include "saving.h"

void reading_contacts(struct contact *contact, int *num_of_contacts)
{
    FILE *file_for_saving = NULL;

    file_for_saving = fopen("contacts", "r");
    if(!file_for_saving) {
        perror("fopen");
        return;
    }

    *num_of_contacts = fread(contact, sizeof(struct contact), 100, file_for_saving);

    if(fclose(file_for_saving)) {
        perror("fclose");
        return;
    }
}

int writing_to_file(struct contact *contact, int contact_count)
{
    FILE *file_for_saving = NULL;

    file_for_saving = fopen("contacts", "w");
    if(!file_for_saving) {
        perror("fopen");
        return 1;
    }

    if(!fwrite(contact, sizeof(struct contact), contact_count, file_for_saving)) {
        perror("fwrite");
        return 1;
    }

    if(fclose(file_for_saving)) {
        perror("fclose");
        return 1;
    }
    return 0;
}
