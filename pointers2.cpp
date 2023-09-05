#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{
    char *temp = "hello!";

    for (int i = 0; i < strlen(temp); i++)
    {
        printf("%c\n", temp[i]);
    }

    printf("\n");

    while (*temp != NULL)
    {
        printf("%c\n", *temp);
        temp++;
    }


    getchar();
    return 0;
}