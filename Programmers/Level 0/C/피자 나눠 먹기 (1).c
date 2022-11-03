#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    while(n > 0) {
        n -= 7;
        answer++;
    }
    
    return answer;    
}
