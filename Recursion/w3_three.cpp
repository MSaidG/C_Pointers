#include <stdlib.h>
#include <stdio.h>

// RECURSIVE BUT NOT PERFECT
int fibonacci(int pre, int after);
// REAL RECURSIVE
int fibonacci_better(int n);

static int i = 1;

int main(int argc, char **argv)
{

    fibonacci(0, 1);
    fibonacci_better(10);

    printf("-----\n------\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", fibonacci_better(i));
    }

    getchar();
    getchar();
    return 0;
}


int fibonacci (int pre, int after)
{

    if (i > 10)
    {
        return 0;
    }
    
    int temp = after;
    after += pre;
    pre = temp;

    printf("%d\n", temp);

    i++;
    return fibonacci(pre, after);
}


int fibonacci_better(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci_better(n-1) + fibonacci_better(n-2);
    }

}