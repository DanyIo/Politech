#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define maxLength 40
int someArray[maxLength], counter;
int *pointer;
unsigned long int number;

void convertIntoFiveDigitSystem(int num)
{
    while (num >= 5)
    {
        int res = 0;
        res = num % 5;
        someArray[counter] = res;
        num /= 5;
        counter++;
    }
    someArray[counter] = num;
    counter++;
}
void reverseAndPrintArray(int arr[], int n)
{
    pointer = someArray;
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = *pointer;
        *pointer = arr[n - i - 1];
        arr[n - i - 1] = temp;
        pointer++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
}
int main()
{
    printf("Введіть число: ");
    scanf("%li", &number);
    convertIntoFiveDigitSystem(number);
    printf("\n");
    reverseAndPrintArray(someArray, counter);
    printf("\n");
    return 0;
}