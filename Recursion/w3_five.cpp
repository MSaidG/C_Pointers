#include <stdlib.h>
#include <stdio.h>

int numberOfDigits(int num, int count);

int main (int argc, char **argv)
{
    //printf("%d", 5/10);
    // int num;
    // scanf("Enter a number: %d", &num);
    int result = numberOfDigits(8, 0);

    printf("Result: %d", result);
    getchar();
    return 0;
}

int numberOfDigits (int num, int count)
{
    if (num/10 == 0)
    {
        return ++count;
    }
    
    return numberOfDigits(num/10, ++count);
}