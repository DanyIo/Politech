#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max 50
struct tovar
{
    int cod;
    int price;
};

struct new_tovar
{
    char name[20];
    int cod;
    int value;
    float date;
};

struct result_array
{
    char name[20];
    int cod;
    int all_value;
    int all_price;
    float date;
};
int isDuplicate(char product[], int array_new_tovars_length, char duplicateProducts[][1000], int queue)
{
    int duplicate = 0;

    for (int i = 0; i < array_new_tovars_length; i++)
    {
        if (strcmp(*(duplicateProducts + i), product) == 0)
        {
            duplicate = 1;
        }
    }
    if (duplicate == 0)
    {
        strcpy(duplicateProducts[queue], product);
    }
    return duplicate;
}

int main(void)
{
    int amount_new_tovars = 0, queue = 0, isAvailable = 0;
    struct tovar storage[] = {{1, 25}, {2, 30}, {3, 15}, {4, 10}};
    struct new_tovar array_new_tovars[max];
    struct result_array result_arr[max];
    struct result_array consumption, *pst, *pst1, *pst2;
    int n = sizeof(storage) / sizeof(storage[0]);
    printf("total %i\n", n);
    printf("\t MAGAZINE \n");
    for (int i = 0; i < n; i++)
    {
        printf("Code:%d \t Price: %d \n", storage[i].cod, storage[i].price);
    }
    printf("How many new tovars do you want add? ");
    scanf("%d", &amount_new_tovars);

    for (int i = 0; i < amount_new_tovars; i++)
    {
        printf("\nEnter name of new tovar ");
        scanf("%s", &array_new_tovars[i].name);
        printf("\nEnter code of new tovar ");
        while (isAvailable != 1)
        {
            scanf("%d", &array_new_tovars[i].cod);
            for (int b = 0; b < n; b++)
            {
                if (array_new_tovars[i].cod == storage[b].cod)
                {
                    isAvailable = 1;
                }
            }
            printf("No such code. Enter another: ");
        }
        isAvailable = 0;
        printf("\nEnter value of new tovar ");
        scanf("%d", &array_new_tovars[i].value);
        printf("\nEnter date of add new tovar ");
        scanf("%f", &array_new_tovars[i].date);
    }
    printf("===============================\n");

    char duplicateProducts[1000][1000];
    int array_new_tovars_length = amount_new_tovars;
    int resultArrayLength = 0;
    printf("\tResult array\n");
    for (int i = 0; i < amount_new_tovars; i++)
    {
        int productPrice = 0;
        int productQuantity = 0;
        int totalAmount = 0;

        if (isDuplicate(array_new_tovars[i].name, array_new_tovars_length, duplicateProducts, queue) == 0)
        {
            queue++;
            for (int k = 0; k < n; k++)
            {
                if (array_new_tovars[i].cod == storage[k].cod)
                {
                    productPrice = storage[k].price;
                }
            }

            for (int g = i; g < array_new_tovars_length; g++)
            {
                if (strcmp((array_new_tovars + i)->name, (array_new_tovars + g)->name) == 0)
                {
                    productQuantity += array_new_tovars[g].value;
                }
            }
            strcpy(result_arr[i].name, array_new_tovars[i].name);
            result_arr[i].cod = array_new_tovars[i].cod;
            result_arr[i].all_value = productQuantity;
            int totalPrice = productPrice * productQuantity;
            result_arr[i].all_price = totalPrice;
            result_arr[i].date = array_new_tovars[i].date;

            resultArrayLength++;
        }
    }
    for (int i = 0; i < resultArrayLength; i++)
    {
        printf("\nName:%s \t Code: %d  \t Total Value: %d \t Total Price: %d \t Date %.2f \n", result_arr[i].name, result_arr[i].cod, result_arr[i].all_value, result_arr[i].all_price, result_arr[i].date);
    }
    printf("===============================\n");
    for (int k = 0; k < resultArrayLength - 1; k++)
    {
        pst1 = result_arr;
        pst2 = result_arr + 1;
        for (; pst2 < result_arr + resultArrayLength - k; pst1++, pst2++)
            if (pst1->all_price < pst2->all_price)
            {
                consumption = *pst1;
                *pst1 = *pst2;
                *pst2 = consumption;
            }
    }
    printf("\tSorted result array\n");
    for (int i = 0; i < resultArrayLength; i++)
    {
        printf("\nName:%s \t Code: %d  \t Total Value: %d \t Total Price: %d \t Date %.2f \n", result_arr[i].name, result_arr[i].cod, result_arr[i].all_value, result_arr[i].all_price, result_arr[i].date);
    }
    printf("===============================\n");
    return 0;
}