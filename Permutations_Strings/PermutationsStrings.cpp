#include <stdio.h>
#include <stdlib.h>

void swap(char* x, char* y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/

    char *temp;

    *temp = s[i];
    if (i+1 == n)
    {
        s[0] = *temp 
    }
        
    s[i+1] = *temp 


    return 0;

}

int main (int argc, char **argv)
{
    FILE *input_file = fopen("input", "r");

    if (input_file == NULL)
    {
        printf("Error! Couldn't open file\n");
        exit(-1);
    }

    char **s;
	int n;
    fscanf(input_file, "%d", &n);
	//scanf("%d", &n);
	s = (char**) calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = (char*) calloc(11, sizeof(char));
        fscanf(input_file, "%s", s[i]);
		//scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;

    
}