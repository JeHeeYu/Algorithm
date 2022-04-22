#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s) {

    int length = strlen(s);
    
    if(length % 2 == 0)
    {
        char* answer = (char*)malloc(sizeof(char) * 3);
        answer[0] = s[length / 2 - 1];
        answer[1] = s[length / 2];
        answer[2] = '\0';
            return answer;
    }
    
    else
    {
        char* answer = (char*)malloc(sizeof(char) * 2);     
        answer[0] = s[length / 2];
        answer[1] = '\0';
            return answer;
    }
}
