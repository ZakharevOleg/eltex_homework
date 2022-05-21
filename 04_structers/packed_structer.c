#include <stdio.h>

int main()
{
        struct test {
                char a;
                int b;
        }__attribute__((packed));

        char str[10] = {'A', 0, 0, 0, 0, 'B', 0, 0, 0, 0};

        struct test*ptr;
        ptr = &str;

        printf ("char is %c, number is %d\n", ptr->a, ptr->b);

        ptr = ptr +1;
        printf ("char is %c, number is %d\n", ptr->a, ptr->b);

        return 0;
}

