#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define N 15
int array[N];
int validation = 0;
int counter = 0;
int dublicateArray[N];
int geRandomNumber(int min, int max)
{
    int randomNumber = min + rand() % (max - min + 1);
    return randomNumber;
}
int validateDuplicat(num)
{
    for (int i = 0; i < N; i++)
    {
        if (num == dublicateArray[i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    srand(time(NULL));

    while (counter < N)
    {
        array[counter] = geRandomNumber(1, 10);
        counter++;
    }
    printf("Random array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");
    counter = 0;
    while (counter < N)
    {
        int number = array[counter];
        int dublicateTimes = 0;
        if (counter == N)
        {
            return 0;
        }
        if (validateDuplicat(number) == 0)
        {
            dublicateArray[validation] = number;
            validation++;
            for (int i = 0; i < N; i++)
            {
                if (number == array[i + 1])
                {
                    dublicateTimes++;
                }
            }
            printf(" Число %i повторюється %i кл. разів\n", number, dublicateTimes);
        }
        counter++;
    }
    return 0;
}