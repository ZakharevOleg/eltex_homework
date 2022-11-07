#include <stdio.h>
#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"
#include <dlfcn.h>

int main()
{
    double num1, num2;
    int num_menu = 0;
    void *operators;
    double (*ret)(double, double);

    operators = dlopen("/home/oleg/homework/eltex_homework/12_calculator_dlopen/liboperations.so", RTLD_LAZY);
    if (!operators) {
        fprintf(stderr, "dlopen() error: %s\n", dlerror());
        return 1;
    }

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
            ret = dlsym(operators,"addition");
            printf("result is: %.5f\n", (*ret)(num1, num2));
            break;
        case 2:
            ret = dlsym(operators, "subtraction");
            printf("result is: %.5f\n", (*ret)(num1, num2));
            break;
        case 3:
            ret = dlsym(operators, "multiplication");
            printf("result is: %.5f\n", (*ret)(num1, num2));
            break;
        case 4:
            ret = dlsym(operators, "division");
            printf("result is: %.5f\n", (*ret)(num1, num2));
            break;
        case 5:
            printf("Goodbye\n");
            return 0;
        default:
            printf("Incorrect input\n");
    }
    dlclose(operators);
    return 0;
}
