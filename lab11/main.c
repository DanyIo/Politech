#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#define MLEN 100

char string[MLEN];
char newString[MLEN];
char symbol;
char *pointer = string;
const char *limits = " ,.;():-";
char *ch;

int str_length(char str[])
{
    int count;
    for (count = 0; str[count] != '\0'; ++count)
        ;
    return count;
}

int main()
{
    printf("Print sentence: \n");
    fgets(string, MLEN - 1, stdin);
    fflush(stdin);
    printf("Enter symbol: ");
    scanf("%c", &symbol);
    int count = 0;
    ch = strtok(string, limits);
    while (ch != NULL)
    {
        int length = str_length(ch);
        int haveSymbol = 0;
        // Варіант через індексацію:
        //     for (int i = 0; i < length; i++)
        //     {
        //         if (ch[i] == toupper(symbol) || ch[i] == tolower(symbol))
        //         {
        //             haveSymbol = 1;
        //         }
        //     }
        //     if (haveSymbol == 0)
        //     {
        //         for (int i = 0; i < length; i++)
        //         {
        //             newString[count++] = ch[i];
        //         }
        //         newString[count++] = ' ';
        //     }
        //     ch = strtok(NULL, limits);
        // Варіант через вказівники:
        for (int i = 0; i < length; i++)
        {
            if (*pointer == toupper(symbol) || *pointer == tolower(symbol))
            {
                haveSymbol = 1;
            }
            pointer++;
        }
        if (haveSymbol == 0)
        {
            for (int i = 0; i < length; i++)
            {
                newString[count++] = ch[i];
            }
            newString[count++] = ' ';
        }
        ch = strtok(NULL, limits);
    }
    newString[count] = '\0';
    printf("%s", newString);
    printf("\n");
}
