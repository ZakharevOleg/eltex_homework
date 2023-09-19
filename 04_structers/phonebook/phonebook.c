#include <stdio.h>
#include <string.h>

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
   
    struct contact contacts[100];
    int number_of_menu = 1;
    int count = 0;

    while(number_of_menu != 4) {

        choise_menu();
        scanf("%d", &number_of_menu);
        getchar();

        if (number_of_menu == 1) {
            printf("Please enter name of contacts:\n");
            fgets(contacts[count].name, 40, stdin);

            printf("Please enter phonenumber:\n");
            fgets(contacts[count].phone, 12, stdin);
            count++;
        }
        else if (number_of_menu == 2) {
            int i;
            for (i = 1; i < count + 1; i++) {
                printf("Name of contact %d:%s", i, contacts[i-1].name);
                printf("Number of contact %d:%s\n", i, contacts[i-1].phone);
            }

        }
        else if (number_of_menu == 3) {
            int i = 0;
            char search[12];
            printf("Please enter phonenumber for search:\n");
            fgets(search, 12, stdin);
            while (i < count) {
                if (strcmp (search, contacts[i].phone) == 0) {
                    printf("Name of this contact:%s\n", contacts[i].name);
                    printf("Number of this contact:%s\n", contacts[i].phone);
                    break;
                }
                i++;
            }
            
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
