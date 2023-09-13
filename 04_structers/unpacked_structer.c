#include <stdio.h>

int main()
{
    struct test {
        char a;
	int b;
    };

    char str[10] = {'A', 0, 0, 0, 0, 'B', 0, 0, 0, 0};

    struct test*ptr;
    
    ptr = (struct test*)&str;
    
    printf ("first char is %c, first number is %d\n", ptr->a, ptr->b);

    ptr = ptr +1;
    printf ("second char is %c, second number is %d\n", ptr->a, ptr->b);
    
    return 0;
}
