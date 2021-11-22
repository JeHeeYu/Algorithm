#include <stdio.h>

int main() 
{
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    if ((A + D) > (B + C))
        printf("%d", B + C);
    else if ((A + D) < (B + C))
        printf("%d", A + D);
    else if ((A + D) == (B + C))
        printf("%d", A + D);

}
