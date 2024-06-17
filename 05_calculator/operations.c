#include <stdio.h>

#include "operations.h"
#include "interface.h"

void addition ()
{
    double num1, num2, ret;

    print_get_number();
    scanf("%lf %lf", &num1, &num2);

    ret = num1 + num2;
    print_result(ret);
}

void subtraction ()
{
    double num1, num2, ret;

    print_get_number();
    scanf("%lf %lf", &num1, &num2);

    ret = num1 - num2;
    print_result(ret);
}

void multiplication ()
{
    double num1, num2, ret;

    print_get_number();
    scanf("%lf %lf", &num1, &num2);

    ret = num1 * num2;
    print_result(ret);
}

void division ()
{
    double num1, num2, ret;

    print_get_number();
    scanf("%lf %lf", &num1, &num2);

    ret = num1 / num2;
    print_result(ret);
}
