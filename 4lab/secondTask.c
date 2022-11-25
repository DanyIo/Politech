#include <stdio.h>
#include <math.h>
#define N 5
int sum = 0;
int main()
{
    int squareMatrix[N][N];
    FILE *fp = fopen("F1.txt", "r");
    FILE *fp2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fscanf(fp, "%i", &squareMatrix[i][j]);
        }
    }
    printf("The matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%i ", squareMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int j = 1; j < N; j++)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            sum += squareMatrix[i][j];
        }
    }
    fclose(fp);
    printf("%i\n", sum);
    fp2 = fopen("F2.txt", "w");
    fprintf(fp2, "The sum of elements above diagonal is %i.", sum);
    fclose(fp2);
    return 0;
}