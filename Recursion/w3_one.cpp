#include <stdlib.h>
#include <stdio.h>

int print(int number);

int main (int argc, char **argv)
{
    print(1);

    getchar();
    return 0;
}

// Print 1 to 50 using recursion
int print(int number)
{
    if (number <= 50)
    {
        printf("%d\n", number);
        print(number + 1);
    }

    return number;
}