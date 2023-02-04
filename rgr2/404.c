#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

struct Point
{
    int x;
    int y;
};
typedef struct Rectangle
{
    struct Point topLeft;
    struct Point botRight;
    int area;

} RECTANGLE;

int Area(const struct Rectangle *r)
{

    int rectangleArea = abs(r->botRight.x - r->topLeft.x) * abs(r->topLeft.y - r->botRight.y);

    return rectangleArea;
}

void genPair(int arr[])
{
    int coordinate1, coordinate2;

    while (1)
    {
        coordinate1 = -50 + rand() % 101;
        coordinate2 = -50 + rand() % 101;

        if (coordinate1 < coordinate2)
        {
            arr[0] = coordinate1;
            arr[1] = coordinate2;
            break;
        }
    }
}

void genRec(RECTANGLE *rec)
{
    int arr[2];

    for (int i = 0; i < 3; i++, rec++)
    {
        genPair(arr);
        rec->topLeft.x = arr[0];
        rec->botRight.x = arr[1];
        genPair(arr);
        rec->botRight.y = arr[0];
        rec->topLeft.y = arr[1];
        rec->area = Area(rec);
    }
}

int main(void)
{

    srand(time(NULL));
    struct Rectangle arrayOfRectangles[N];
    int maxarea = 0;
    int maxidx = 0;
    struct Rectangle rec[N];

    genRec(arrayOfRectangles);

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        printf("\t----------RECTANGLE %d----------\n", i + 1);
        printf("\tTop left point is x = %d y = %d\n", arrayOfRectangles[i].topLeft.x, arrayOfRectangles[i].topLeft.y);
        printf("\tBottom right point is x = %d y = %d\n", arrayOfRectangles[i].botRight.x, arrayOfRectangles[i].botRight.y);
        printf("\tArea is %d\n", arrayOfRectangles[i].area);

        if (arrayOfRectangles[i].area > maxarea)
        {
            maxarea = arrayOfRectangles[i].area;
            maxidx = i;
        }
    }

    printf("\n");
    printf("\tMaximum area is %d in Rectangle %d\n", maxarea, maxidx + 1);

    int includeSomeRectangle = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != maxidx)
        {
            if (arrayOfRectangles[maxidx].topLeft.x <= arrayOfRectangles[i].topLeft.x && arrayOfRectangles[maxidx].topLeft.y <= arrayOfRectangles[i].topLeft.y && arrayOfRectangles[maxidx].botRight.x >= arrayOfRectangles[i].botRight.x && arrayOfRectangles[maxidx].botRight.y >= arrayOfRectangles[i].botRight.y)
            {
                printf("\n\tRectangle %i is inside rectangle %i\n", i + 1, maxidx + 1);
                includeSomeRectangle = 1;
            }
        }
    }
    if (!includeSomeRectangle)
    {
        printf("\n\tNo such rectangles that are inside rectangle %i\n", maxidx + 1);
    }
    return 0;
}
