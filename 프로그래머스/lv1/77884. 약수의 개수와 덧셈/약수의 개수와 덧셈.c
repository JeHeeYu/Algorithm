#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    int answer = 0;
    
    int i, j, cnt;
    
    for(i = left; i <= right; i++)
    {
        cnt = 0;
        for(j = 1; j <= right; j++)
        {
          if(i % j == 0)
              cnt++;
        }
        if(cnt % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    
    return answer;
}