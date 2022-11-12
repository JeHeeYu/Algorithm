// Online C compiler to run C program online
#include <stdio.h>

int GCD(int x, int y);

int main() 
{
    int x, y;
    printf("정수를 입력하세요 : ");
    scanf("%d", &x);
    printf("정수를 입력하세요 : ");
    scanf("%d", &y);
    printf("최대 공약수는 %d 입니다.\n", GCD(x, y));

    return 0;
}

int GCD(int x, int y)
{
    if(y == 0) {
        return x;
    }
    else {
        return GCD(y, x % y);
    }
}
