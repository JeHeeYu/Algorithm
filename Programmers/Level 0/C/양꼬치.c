#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int k) {
    int answer = (n * 12000) + (k * 2000);
    
    while(n >= 10) {
        n -= 10;
        answer -= 2000;
    }
    
    return answer;
}
