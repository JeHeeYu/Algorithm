#include <stdio.h>

int BruteForce(const char *text, const char *partition);

int main() 
{
    int index;
    
    // 검색할 문자열 "ABABCDEFGHA"
    char s1[256];
    
    // 찾을 문자열 "ABC"
    char s2[256];
    
    printf("검색할 문자열 : ");
    scanf("%s", s1);
    
    printf("찾을 문자열 : ");
    scanf("%s", s2);
    
    index = BruteForce(s1, s2);
    
    if(index == -1) {
        printf("문자열 검색 실패!\n");
    }
    else {
        printf("%d 번째 문자부터 동일합니다.\n", index + 1);
    }

    return 0;
}
int BruteForce(const char *text, const char *partition)
{
    // 검색할 문자열 커서
    int textCursor = 0;
    
    // 찾을 문자열 커서
    int partitionCursor = 0;
    
    while(text[textCursor] != '\0' && partition[partitionCursor] != '\0') {
        // 바라보고 있는 문자가 겹치는지 검사
        if(text[textCursor] == partition[partitionCursor]) {
            // 겹칠 경우 다음 문자 검색
            textCursor++;
            partitionCursor++;
        }
        else {
            // 검색할 문자열에서 다음 문자부터 검사할 커서 이동
            textCursor = textCursor - partitionCursor + 1;
            
            // 찾을 문자열 커서 0으로 업데이트
            partitionCursor = 0;
        }
    }
    
    // 찾을 문자열 커서가 끝에 도달했을 경우 문자열 검색 성공
    if(partition[partitionCursor] == '\0') {
            return textCursor - partitionCursor;
    }
    
    // 문자열 검색 실패
    return -1;
}
