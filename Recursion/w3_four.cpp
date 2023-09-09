#include <stdlib.h>
#include <stdio.h>

int* printArrray(int* array, int index, int size);

int main (int argc, char **argv)
{
    int my_array[] = {2, 4, 6, 8, 10, 12};
    int size = sizeof(my_array) / sizeof(int);

    printArrray(my_array, 0, size);

    getchar();
    return 0;
}


int* printArrray(int* array, int index, int size)
{
    
    if (index < size)
    {
        printf("%d ", array[index]);
        printArrray(array, ++index, size);
    }


}
