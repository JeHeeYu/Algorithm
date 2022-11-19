#include <stdio.h>

int KMP(const char *text, const char *partition);

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
    
    index = KMP(s1, s2);
    
    if(index == -1) {
        printf("문자열 검색 실패!\n");
    }
    else {
        printf("%d 번째 문자부터 동일합니다.\n", index + 1);
    }

    return 0;
}

int KMP(const char *text, const char *partition)
{
    // text 커서
    int textCursor = 1;
    
    // partition 커서
    int partitionCursor = 0;
    
    // 건너뛸 표
    int skip[1024];
    
    skip[textCursor] = 0;
    
    while(partition[textCursor] != '\0') {
        if(partition[textCursor] == partition[partitionCursor]) {
            skip[++textCursor] = ++partitionCursor;
        }
        else if(partitionCursor == 0) {
            skip[++textCursor] = partitionCursor;
        }
        else {
            partitionCursor = skip[partitionCursor];
        }
    }
    
    textCursor = 0;
    partitionCursor = 0;
    
    while(text[textCursor] != '\0' && partition[partitionCursor] != '\0') {
        if(text[textCursor] == partition[partitionCursor]) {
            textCursor++;
            partitionCursor++;
        }
        else if(partitionCursor == 0) {
            textCursor++;
        }
        else {
            partitionCursor = skip[partitionCursor];
        }
    }
    
    if(partition[partitionCursor] == '\0') {
        return textCursor - partitionCursor;
    }
    
    return -1;
}
