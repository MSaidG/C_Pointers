#include <stdlib.h>
#include <stdio.h>

int sum (int num);

int main (int argc, char **argv)
{
    
    int result = sum(1000);

    printf("%d\n", result);

    getchar();
    return 0;
}

int sum (int num)
{
    if (num == 1)
    {
        return 1;
    }

    return num + sum(num-1);
}


