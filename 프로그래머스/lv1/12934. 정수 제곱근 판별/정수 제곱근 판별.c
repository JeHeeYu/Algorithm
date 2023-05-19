#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n)
{
    long long answer = 0;
    double num = sqrt(n);
    if (num == (int)num)
    {
        return (num + 1) * (num + 1);
    }
    else return -1;
}