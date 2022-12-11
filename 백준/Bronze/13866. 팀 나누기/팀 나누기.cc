#include <stdio.h>

int main() 
{
    int A, B, C, D, i, sum = 0, min = 10000, max = 0, result = 0;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    sum += A + B + C + D;

    if (A < min) min = A;
    if (B < min) min = B;
    if (C < min) min = C;
    if (D < min) min = D;

    if (A > max) max = A;
    if (B > max) max = B;
    if (C > max) max = C;
    if (D > max) max = D;


    result = sum - (max + min);

    if (result > (max + min))
    {
        result -= (max + min);
        printf("%d", result);
    }
    
    else
    {
        printf("%d", (max + min) - result);
    }
}