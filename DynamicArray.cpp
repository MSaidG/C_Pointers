// Dynamic Array In C solution for Hacker Rank

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *total_number_of_books;
int **total_number_of_pages;

#define MAX_NUMBER_PAGES 1100

int main (int argc, char **argv)
{
    FILE *input_file = fopen("dynamic_array_input_1", "r");

    if (input_file == NULL)
    {
        printf("Error! Couldn't open file\n");
        exit(-1);
    }

    int total_number_of_shelves;
    fscanf(input_file, "%d", &total_number_of_shelves);
    //printf("%d\n", total_number_of_shelves);

    int total_number_of_queries;
    fscanf(input_file, "%d", &total_number_of_queries);
    //printf("%d\n", total_number_of_queries);
    
    //*total_number_of_books = (int*) calloc(MAX_NUMBER_SHELVES, sizeof(int));

    //**total_number_of_pages = (int**)calloc(MAX_NUMBER_SHELVES, sizeof(int*));
    //for (int i = 0; i < MAX_NUMBER_SHELVES; i++)
    //    total_number_of_pages[i] = (int*)calloc(MAX_NUMBER_PAGES, sizeof(int));

    total_number_of_books = (int*) calloc(total_number_of_shelves, sizeof(int));

    total_number_of_pages = (int**)calloc(total_number_of_shelves, sizeof(int*));
    for (int i = 0; i < total_number_of_shelves; i++)
        total_number_of_pages[i] = (int*) calloc(MAX_NUMBER_PAGES, sizeof(int));
    
    int size = 0;
    while (total_number_of_queries--) {
        int type_of_query;
        fscanf(input_file, "%d", &type_of_query);
        //printf("%d\n", type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            //scanf("%d %d", &x, &y);
            fscanf(input_file, "%d", &x);
            fscanf(input_file, "%d", &y);
            //printf("%d %d\n", x, y);

            total_number_of_pages[x][total_number_of_books[x]] = y;
            total_number_of_books[x]++;


        } else if (type_of_query == 2) {
            int x, y;
            //scanf("%d %d", &x, &y);
            fscanf(input_file, "%d", &x);
            fscanf(input_file, "%d", &y);
            //printf("%d %d\n", x, y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            fscanf(input_file, "%d", &x);
            //printf("%d\n", x);
            printf("%d\n",  *(total_number_of_books + x));
        }
    }

    int test;
    scanf("%d", &test);

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }

    printf("It's working!");
    
    return 0;

}