#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 20);

    srand(time(0));

    int sum = 0;
    int sample = 1000;

    for (int i = 0; i < sample; i++)
    {
        //printf("%d \n", dist(gen));
        sum += dist(gen); 
    }

    printf("%d", sum / sample);

}
