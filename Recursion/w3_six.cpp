#include <stdlib.h>
#include <stdio.h>


int sumOfDigits (int num)
{
    if (num == 0)
    {
        return 0;
    }

    return sumOfDigits(num/10) + num%10;
}


int main (int argc, char **argv)
{

    int result = sumOfDigits(90);

    printf("%d", result);
    getchar();
    return 0;
}