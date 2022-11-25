#include <stdio.h>
#include <math.h>
int main(void)
{
    double x, eps;
    printf("Please input 0<|x|<1 and eps<=0.0001: \n");
    scanf("%lf%lf", &x, &eps);
    if (fabs(x) > 0 && fabs(x) < 1 && eps <= 0.0001)
    {
        double Y = -0.5 * (log(1 - 2 * x * cos(M_PI / 3) + pow(x, 2)));
        double S = 0;
        for (int k = 1;; k++)
        {
            double A = (pow(x, k) * cos((k * M_PI) / 3)) / k;
            S += A;
            if (fabs(A) < eps)
            {
                break;
            }
        }
        printf("Y(x)=%f; S(x)=%f; |Y(x)-S(x)|=%10.8f.\n", Y, S, fabs(Y - S));
    }
    else
    {
        printf("Incorrect input!\n");
    }
    return 0;
}
