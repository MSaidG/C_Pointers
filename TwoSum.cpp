#include <stdlib.h>
#include <stdio.h>


int* twoSum(int* nums, int numsSize, int target){

    int *result;      
    result = (int *) calloc(2, sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < target)
        {
            for (int j = i+1; j < numsSize; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }        
        }
    }
    
    return result;
}

int main (int argc, char **argv)
{
    int numsSize = 4;
    int nums[numsSize] = {2,7,11,15};

    int *result;      
    result = (int *) calloc(2, sizeof(int));

    result = twoSum(nums, numsSize, 9);


    printf("[%d,", result[0]);
    printf("%d]", result[1]);

    scanf("%d", &numsSize);
    return 0;
}