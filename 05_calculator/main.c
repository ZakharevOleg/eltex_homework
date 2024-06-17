#include "interface.h"
#include "operations.h"

int main()
{
    int num_operation;

    while(num_operation != 5) {

        num_operation = choise_operation();

        switch (num_operation) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                print_end();
                return 0;
            default:
                print_incorect();
        }
    }
    return 0;
}
