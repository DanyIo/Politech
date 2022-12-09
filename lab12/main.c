#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#define MAXLENGTH 1000
char string[MAXLENGTH];
char newString[MAXLENGTH];
char *rest = string;
char *pointer = newString;
int counter = 0;
int aps = 0;
int firstElement = 0;
char *ch, *cz;
int str_length(char str[])
{
    int count;
    for (count = 0; str[count] != '\0'; count++)
        ;
    return count;
}

int main()
{   
    // Речення вводити без пробілів після коми. Дівчатка повинні закінчуватись на англійську A. Речення повинно закінчуватись комою.
    // Приклад вводу: МЕЛЬНИК ВАСИЛЬ ВАСИЛЬОВИЧ,ШЕВЧЕНКО ОЛЕКСАНДР МИКОЛАЙОВИЧ,ОЛІЙНИК ГАННА ІВАНІВНA,
    printf("Print sentence: ");
    fgets(string, MAXLENGTH-1, stdin);
    fflush(stdin);
    while ((ch = strtok_r(rest, ",", &rest)))
    {
        int length = str_length(ch);
        if (ch[length - 1] == 'A')
        {
            aps = 1;
            int word = 1;
            cz = strtok(ch, " ");
            while (cz != NULL)
            {
                int lengthOf = str_length(cz);
                if (word == 1)
                {
                    for (int i = 0; i < lengthOf; i++)
                    {
                        newString[counter++] = cz[i];
                    }
                    newString[counter++] = ' ';
                    word++;
                }
                else
                {
                    for (int i = 0; i < 2; i++)
                    {
                        newString[counter++] = cz[i];
                    }
                    newString[counter++] = '.';
                }
                cz = strtok(NULL, " ");
            }
            newString[counter++] = ',';
        }
    }
    newString[counter] = '\0';
    if (aps == 1)
    {
        printf("%s", newString);
    }
    else
    {
        printf("There is No a single girl.");
    }

    printf("\n");
}