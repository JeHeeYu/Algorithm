#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ULONG;

ULONG Fibonacci(int n);

int main()
{
    int n;
    
    scanf("%d", &n);
    
    printf("Fibonacci(%d) = %lu\n", n, Fibonacci(n));

    return 0;
}

ULONG Fibonacci(int n)
{
    int i;
    
    ULONG result;
    ULONG* fibonacciTable;
    
    if(n == 0 || n == 1) {
        return n;
    }
    
    fibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (n + 1));
    
    fibonacciTable[0] = 0;
    fibonacciTable[1] = 1;
    
    for(i = 2; i <= n; i++) {
        fibonacciTable[i] = fibonacciTable[i - 1] + fibonacciTable[i - 2];
    }
    
    result = fibonacciTable[n];
    
    free(fibonacciTable);
    
    return result;
}
