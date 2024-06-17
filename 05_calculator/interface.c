#include <stdio.h>

#include "interface.h"

int choise_operation()
{
    int number_of_menu;

    printf("Choise number of operation:\n"
            "1: Addition\n"
            "2: Subtraction\n"
            "3: Multiplication\n"
            "4: Division\n"
            "5: Exit from calculator\n");

    scanf("%d", &number_of_menu);
    getchar();

    return number_of_menu;
}

void print_get_number()
{
    printf("Enter num1 and num2:\n");
}

void print_result(double result)
{
    printf("Result is: %.5f\n\n", result);
}

void print_end()
{
    printf("Goodbye\n");
}

void print_incorect()
{
    printf("Incorrect input\n");
}
