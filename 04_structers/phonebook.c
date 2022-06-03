#include <stdio.h>

void choise_menu()
{
    printf("Please enter number of menu:\n"
           "1: Add contact\n"
           "2: Show all contacts\n"
           "3: Search by number\n"
           "4: Exit from phonebook\n");
}

int main()
{

    struct contact {
        char name[40];
        char phone[12];
    };
   
    struct contact list_of_contacts[100];
    int  number_of_menu = 1;
    int cont_count = 0;
    /* int* count = &cont_count; */

    while(number_of_menu != 4)
    {
        choise_menu();
        scanf("%d", &number_of_menu);
        getchar();
        if (number_of_menu == 1) {
            printf("Please enter name of contacts:\n");
            fgets(list_of_contacts[cont_count].name, 40, stdin);

            printf("Please enter phonenumber:\n");
            fgets(list_of_contacts[cont_count].phone, 12, stdin);
            cont_count++;
        }
        else if (number_of_menu == 2) {
            int i;
            for (i = 1; i < cont_count + 1; i++)
            {
                printf("Name of contact %d:%s\n", i, list_of_contacts[i-1].name);
                printf("Number of contact %d:%s\n", i, list_of_contacts[i-1].phone);
            }

        }
        else if (number_of_menu == 3) {
            printf("3\n");

        }
        else if (number_of_menu == 4) {
            printf("Goodbye\n");
            return 0;
        }
        else {
            printf("Incorrect input \n");
        }

    }
    return 0;

}
