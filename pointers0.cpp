#include <stdio.h>
#include <stdint.h>

void print(char *string);
int stringLength(char *string, void (*func)(char*));
void changeValue(int *value);
void foo1(int xval);
void foo2(int dummy);
void changeString(char **string);
void readFile(char *filename);
void readFile_(char *filename);


#define BUFFER_SIZE 256


struct data
{
    int dataInt;
    int *dataIntp;

    char dataChar;
    char *dataCharp;

};
void changeData(data data);
void changeDataP(data *data);


main (int argc, char **argv)
{
    int a = 1;
    int *b;
    int *c;
    b = &a;
    c = &a;


    changeValue(&a);
    printf("changeValue(&a): %d\n", a);

    int array[10] = {};
    *(array + 1) = 5;
    *(array + 12) = 5;
    *(array + 11) = 5;  
    *(array + 100) = 5;

    char *string = "";
    char *stringHi = "Hi!";

    //print(stringHi);
    //print("Selam!");
    void (*func)(char*) = &print;

    stringLength(stringHi, *func);

    //func(stringHi);

    printf("*(array - 1): %d | *(array): %d | *(array + 2): %d | *(array + 9): %d | *(array + 10): %d\n", *(array - 1), *(array), *(array + 2), *(array + 9), *(array + 10));

    printf("string: %s | &string: %s | *string: %s | \n", string, &string, *string);
    printf("stringHi: %s | &stringHi: %s | *stringHi: %s | \n", stringHi, &stringHi, *(stringHi + 3));

    

    int *pointerArray;
    //*(pointerArray + 1) = 5;
    *(b + 1) = 5;

    printf("pointerArray: %d \n", pointerArray);

    printf("(array + 1): 0x%x | (array + 10): 0x%x | (array + 11): 0x%x | (array + 100): 0x%x \n", (array + 1), (array + 10), (array + 11), (array + 100));

    printf("array: %d | array + 1: %d | *array: %d | *(array + 1): %d | *(array + 10): %d \n", array, array + 1, *array, *(array + 1), *(array + 10));

    *c = 2;
    printf("a: %d | &a: %d | *b: %d | b: %d | *c: %d | c: %d \n", a, &a, *b, b, *c, c);
//------------------------------------------------------------------------------------------------------
    foo1(7);
    foo2(11);

    char *ch;
    char cha[] = "test";
    ch = cha;

    printf("before ch: %s | before cha: %s\n", ch, cha); 
    //changeStringA(cha,  5);
    changeString(&ch);
    printf("after ch: %s | after cha: %s\n", ch, cha); 


    printf("ch: %s | cha: %s \n", ch, cha); 
    printf("&ch: %s | &cha: %s\n", &ch, &cha); 

    char test[] = "a";
    char *temp = test;
    *(cha) = *temp;
    printf("cha: %s \n", cha);


    ch = "a";
    printf("ch: %s \n", ch);

    data data = {};
    changeData(data);
    printf("data.dataInt: %d \n", data.dataInt);

    changeDataP(&data);
    printf("data.dataInt: %d \n", data.dataInt);

    char l = 'A';
    printf("l: %d\n", l);


    char *filename = "test.txt";
    readFile(filename);

    printf("LAST LINE\n");

    

    getchar();
    return 0;

}


int orderFileText(char *buffer)
{
    int length = 0;    

    while (*buffer != '\n')
    {
        length++;
        buffer++;
    } 

    return length;
}

void readFile(char *filename)
{
    FILE *file;
    char buffer[BUFFER_SIZE]; 
    file = fopen(filename, "r");
    int len;
 
    while(fgets(buffer, BUFFER_SIZE, file)) {
        len = orderFileText(buffer);
        printf("%d: %s\n", len, buffer);
    }
    fclose(file);
}

void readFile_(char *filename)
{
    FILE *file;
    char *buffer; 
    file = fopen(filename, "r");

    while(buffer != NULL) {
        printf("%s", buffer);
        buffer++;
    }
    fclose(file);
}

void changeData(data data)
{
    int *p;
    int a;
    p = &a;
    data.dataChar = 1;
    data.dataCharp = "char";
    data.dataInt = 2;
    data.dataIntp = p;
}

void changeDataP(data *data)
{
    int *p;
    int a;
    p = &a;
    data->dataChar = 1;
    data->dataCharp = "char";
    data->dataInt = 2;
    data->dataIntp = p;
}

void print(char *string)
{
    printf("%s\n", string);
}

int stringLength(char *string, void (*func)(char*))
{
    int result = 0;

    func(string);

    while (*string != NULL)
    {
        printf("%s\n", string);
        string++;
        if (*string == NULL)
        {
            printf("%s\n", *string);
            break;
        }
        result++;
    }

    return result - 1;
}

void changeString(char **string)
{
    char *newChar = "succeded!";

    *string = newChar;
}



void changeValue(int *value)
{
    int newValue = 10;

    *value = -(*value);
}


void foo1(int xval)
{
    int x;
    x = xval;
    /* print the address and value of x here */
    printf("x: 0x%x \n", &x);

}
void foo2(int dummy)
{
    int y;
    /* print the address and value of y here */
    printf("y: 0x%x \n", &y);
}


