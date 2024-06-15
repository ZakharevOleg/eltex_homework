#include <stdio.h>

#include "menu.h"

int choise_menu()
{
    int number_of_menu;

    printf("Please enter number of menu:\n"
           "1: Add contact\n"
           "2: Show all contacts\n"
           "3: Search by number\n"
           "4: Exit from phonebook\n");

    scanf("%d", &number_of_menu);
    getchar();

    return number_of_menu;
}
