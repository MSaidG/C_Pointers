#include <stdlib.h>
#include <stdio.h>
#include "test.h"

#include <time.h>
#include <iostream>

int main (int argc, char **argv)
{

    int start = clock();

//    int arr[2] = {0, 2};

    int size = sizeof(arr) / sizeof(arr[0]);
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = arr[i] * arr[i];
//    }

    int min = arr[0];
    int max = arr[0];
    int temp_min_index = 0;
    int temp_max_index = 0;
    for (int j = 0; j < size / 2; j++)
    {
        int new_size = size - j;
        for (int i = j; i < new_size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                temp_min_index = i;
            }

            if (arr[i] > max)
            {
                max = arr[i];
                temp_max_index = i;
            }
        }
        
        
        if (min == arr[j] && max == arr[size-j-1])
        {
            int isOrdered = 1;
            for (int i = j; i < new_size-1; i++)
            {
                if (arr[i] > arr[i+1])
                {
                    isOrdered = 0;
                    break;
                }
            }

            if (isOrdered)
            {
                goto end;
            }
        }

        arr[temp_min_index] = arr[j];

        arr[j] = min;

        if (temp_max_index == j)
        {
            arr[temp_min_index] = arr[size-j-1];
        } 
        else
        {
            arr[temp_max_index] = arr[size-j-1];
        }
        arr[size-j-1] = max;

        min = arr[j+1];
        max = arr[j+1];
        temp_min_index = j+1;
        temp_max_index = j+1;
    }
    

    end:

    int end = clock();//Now check what amount of ticks we have now. 
    //To get the time, just subtract start from end, and divide by CLOCKS_PER_SEC.
    printf( "%f: seconds.\n",  ((float)end - start)/CLOCKS_PER_SEC);


    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    getchar();
    return 0;
}