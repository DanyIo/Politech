#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#define MAXLENGTH 100
int str_length(char str[])
{
    int count;
    for (count = 0; str[count] != '\0'; count++)
        ;
    return count;
}
void changeUrString(char str[], int q)
{
    int length = str_length(str);

    for (int i = 0; i < length; i++)
    {
        int s = q;
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (str[i] + s > 90)
            {
                s = ((str[i] + s) % 90) + 64;
                str[i] = s;
            }
            else
            {
                str[i] = str[i] + q;
            }
        }
        else
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                if (str[i] + s > 122)
                {
                    s = ((str[i] + s) % 122) + 96;
                    str[i] = s;
                }
                else
                {
                    str[i] = str[i] + q;
                }
            }
        }
    }

    printf("%s\n", str);
}

int main()
{
    char str[MAXLENGTH][MAXLENGTH] = {};
    int rows = 0;
    printf("Кількість рядків?\n");
    if (scanf("%i", &rows) == 0)
    {
        printf("Введіть число.\n");
        return 0;
    }
    printf("Наповніть матрицю рядками\n");
    int g = -1;
    while (g != rows)
    {
        fgets(*(str + g), MAXLENGTH - 1, stdin);
        g++;
    }
    int i = 0;
    printf("Зашифрований текст:\n");
    while (i != rows)
    {
        changeUrString((*(str + i)), i + 1);
        i++;
    }
    printf("Розшифрований текст\n");
    for (int i = 0; i != rows; i++)
    {
        int length = str_length((*(str + i)));
        for (int g = 0; g != length; g++)
        {
            int s = i + 1;
            if (*(*(str + i) + g) >= 'A' && *(*(str + i) + g) <= 'Z')
            {
                if (*(*(str + i) + g) - s < 65)
                {
                    s = (*(*(str + i) + g)) - s + 26;
                    *(*(str + i) + g) = s;
                }
                else
                {
                    *(*(str + i) + g) = *(*(str + i) + g) - s;
                }
            }
            if (*(*(str + i) + g) >= 'a' && *(*(str + i) + g) <= 'z')
            {
                if (*(*(str + i) + g) - s < 97)
                {
                    s = (*(*(str + i) + g)) - s + 26;
                    *(*(str + i) + g) = s;
                }
                else
                {
                    *(*(str + i) + g) = *(*(str + i) + g) - s;
                }
            }
            printf("%c", *(*(str + i) + g));
        }
        printf("\n");
    }
    return 0;
}