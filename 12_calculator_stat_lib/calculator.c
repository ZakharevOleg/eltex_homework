#include <stdio.h>
#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"

int main()
{
    double num1, num2, ret;
    int num_menu = 0;
    printf("Enter number1:\n");
    scanf("%lf", &num1);

    printf("Enter number2:\n");
    scanf("%lf", &num2);

    printf("Choise number of operation:\n"
           "1: Addition\n"
           "2: Subtraction\n"
           "3: Multiplication\n"
           "4: Division\n"
           "5: Exit from calculator\n");
    
    scanf("%d", &num_menu);
    getchar();
    switch (num_menu) {
        case 1:
            ret = addition(num1, num2);
            printf("result is: %.5f\n", ret);
            break;
        case 2:
            ret = subtraction(num1, num2);
            printf("result is: %.5f\n", ret);
            break;
        case 3:
            ret = multiplication(num1, num2);
            printf("result is: %.5f\n", ret);
            break;
        case 4:
            ret = division(num1, num2);
            printf("result is: %.5f\n", ret);
            break;
        case 5:
            printf("Goodbye\n");
            return 0;
        default:
            printf("Incorrect input\n");
    }

    return 0;
}
