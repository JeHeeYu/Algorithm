#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(s) * strlen(answer));
    
    int i, j;
    int min = 0;
    char temp;
    
    strcpy(answer, s);
    
    for(i = 0; i < strlen(s); i++)
    {
       for(j = i + 1; j < strlen(s); j++)
       {
           if(answer[i] < answer[j])
           {
               temp = answer[i];
               answer[i] = answer[j];
               answer[j] = temp;
           }
       }
    }
    
    return answer;
}