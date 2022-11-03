#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2);
    
    int a = 0, b = 0;
    
    for(int i = 1; i <= num_list_len; i++) { 
        if(num_list[i - 1] % 2 == 0) {
            a++;
        }
        else {
            b++;
        }
    }
    
    answer[0] = a, answer[1] = b;
    
    return answer;
}
