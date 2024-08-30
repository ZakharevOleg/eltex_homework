#ifndef _CONTACTS_
#define _CONTACTS_

struct contact {
    char name[40];
    char phone[12];
};

void added_contact(struct contact*);

void show_contacts(struct contact*, int);

void search_contact(struct contact*, int);

#endif
