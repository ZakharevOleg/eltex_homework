#ifndef _CONTACTS_
#define _CONTACTS_

struct contact {
    char name[40];
    char phone[12];
};

void added_contact(struct contact *new_contact);

void show_contacts(struct contact *contact, int num_of_contacts);

void search_contact(struct contact*, int num_of_contacts);

#endif
