#include <stdio.h>
#include <string.h>

// #include <limits.h> 함수에도 정의되어 있음
#define UCHAR_MAX 255

int BoyerMoore(const char *text, const char *partition);

int main() 
{
    int index;
    
    // 검색할 문자열
    char s1[256];
    
    // 찾을 패턴
    char s2[256];
    
    printf("텍스트 : ");
    scanf("%s", s1);
    
    printf("패턴 : ");
    scanf("%s", s2);
    
    index = BoyerMoore(s1, s2);
    
    if(index == -1) {
        printf("텍스트에 패턴이 없습니다.\n");
    }
    else {
        printf("%d 번째 문자부터 동일합니다.\n", index + 1);
    }

    return 0;
}

int BoyerMoore(const char *text, const char *partition)
{
    // 검색할 텍스트 커서
    int textCursor;
    
    // 검색할 텍스트 문자열 길이
    int textLength = strlen(text);
    
    // 찾을 패턴 커서
    int partitionCursor;
    
    // 찾을 패턴 문자열 길이
    int partitionLength = strlen(partition);
    
    // Skip 표
    int skip[UCHAR_MAX + 1];
    
    // Skip 표 만들기
    for(textCursor = 0; textCursor <= UCHAR_MAX; textCursor++) {
        // Skip 표에 검색할 패턴 문자열 길이 할당
        skip[textCursor] = partitionLength;
    }
    
    for(textCursor = 0; textCursor < partitionLength - 1; textCursor++) {
        // 패턴 중 맨 마지막 패턴 제외 표 만듬
        skip[partition[textCursor]] = partitionLength - textCursor - 1;
    }

    // 마지막 문자열까지 검사
    while(textCursor < textLength) {
        // 검색할 패턴의 마지막 문자부터 검사하기 위해 마지막 인덱스 값 할당 (n - 1)
        partitionCursor = partitionLength - 1;
        
        // 비교하고 있는 문자열과 패턴이 동일할 때
        while(text[textCursor] == partition[partitionCursor]) {
            
            // 패턴의 맨 뒤에서 맨 앞까지 모두 검색을 끝났을 때
            if(partitionCursor == 0) {
                return textCursor;
            }
            
            // 앞 문자 비교
            partitionCursor--;
            textCursor--;
        }
        
        // 문자열 커서를 패턴의 일치 여부에 따라 뒤로 옮김
        textCursor += (skip[text[textCursor]] > partitionLength - partitionCursor) ? skip[text[textCursor]] : partitionLength - partitionCursor;
    }
    
    return -1;
}
