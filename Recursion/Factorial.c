#include <stdio.h>

int Factorial(int n);

int main()
{
    int n;
    printf("정수를 입력하세요 : ");
    scanf("%d", &n);
    
    printf("%d의 Factorial 값은 %d 입니다.\n", n, Factorial(n));
    
    return 0;
}

int Factorial(int n)
{
    if(n > 0) {
        return n * Factorial(n - 1);
    }
    else {
        return 1;
    }
}
