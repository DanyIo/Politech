#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define N 15;
double f(double x)
{
  double f;
  f = 1 / M_PI * atan((2 * x - 1) / 2 + M_PI);
  return f;
}
void getIntegral(double beginningOfInterval, double endOfInteral)
{
  // Simpson Method

  double S = 0, h, x;
  h = (endOfInteral - beginningOfInterval) / 1000;
  x = beginningOfInterval + h;
  while (x < endOfInteral)
  {
    S = S + 4 * f(x);
    x = x + h;
    if (x >= endOfInteral)
    {
      break;
    }
    S = S + 2 * f(x);
    x = x + h;
  }
  S = (h / 3) * (S + f(beginningOfInterval) + f(endOfInteral));
  printf("Integral: %f\n", S);
}
int main(void)
{
  int beginningOfInterval = 0, counter = 0;
  double endOfInteral = M_PI;
  double x = beginningOfInterval, y = 0;
  double step = (endOfInteral - beginningOfInterval) / N;
  printf("|----------------------------+----------------------------+-------|\n");

  // while (x <= endOfInteral)
  // {
  //     y = 1 / M_PI * atan((2 * x - 1) / 2 + M_PI);
  //     printf("Значення аргумента = %f; Значення функції = %f; № = %i \n", x, y, counter);
  //     printf("|----------------------------+----------------------------+-------|\n");
  //     x += step;
  //     counter++;
  // }

  // do
  // {
  //     y = 1 / M_PI * atan((2 * x - 1) / 2 + M_PI);
  //     printf("Значення аргумента = %f; Значення функції = %f; № = %i \n", x, y, counter);
  //     printf("|----------------------------+----------------------------+-------|\n");
  //     x += step;
  //     counter++;
  // } while (x <= endOfInteral);

  for (int counter = 0; x <= endOfInteral; counter++)
  {
    y = 1 / M_PI * atan((2 * x - 1) / 2 + M_PI);
    printf("Значення аргумента = %f; Значення функції = %f; № = %i \n", x, y, counter);
    printf("|----------------------------+----------------------------+-------|\n");
    x += step;
  }
  printf("\n");
  getIntegral(beginningOfInterval, endOfInteral);
  return 0;
}