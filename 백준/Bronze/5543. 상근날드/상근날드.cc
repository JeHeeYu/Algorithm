#include <stdio.h>
 
int main() {
 
    int a, b, i, j, min = 2000, min1 = 2000;
 
 
    for (i = 0; i < 3; i++) 
    {
        scanf("%d", &a);
        if (min > a)
            min = a;
    }
    for (j = 0; j < 2; j++) 
    {
        scanf("%d", &b);
        if (min1 > b)
            min1 = b;
    }
    printf("%d", min + min1 - 50);
}
