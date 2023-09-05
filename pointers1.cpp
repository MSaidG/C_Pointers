#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>















int next_permutation(int n, char **s)
{
	int numberOfCompare = (n*(n-1))/2;
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int k = i+1; k < n; k++)
		{
			for(int j = 0; j < strlen(*s); j++)
			{
				if (s[i][j] < s[k][j])
				{
					break;
				}

				if (s[i][j] > s[k][j])
				{
					char *temp;
					temp = s[i];
					s[i] = s[k];
					s[k] = temp;
					break;
				}

				if (s[i][strlen(*s)] == s[k][strlen(*s)])
				{
					
				}

			}
		}
		printf("[%d]: %s   ", i, s[i]);
	}

	printf("\n");

 	return 0;
}

int main(int argc, char ** argv)
{

	char **s;
	int n;
	scanf("%d", &n);
	s = (char **) calloc(n, sizeof(char*));
	FILE *file = fopen("test.txt", "r");
	if (file == NULL)
	{
		printf("Wrong!!\n");
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		s[i] = (char *) calloc(11, sizeof(char));
		fscanf(file, "%s", s[i]);			
	}

	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));

	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);

	getchar();
	getchar();
	return 0;

}