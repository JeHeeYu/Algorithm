#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[5001];
    int alpha[26] = { 0 };
    int cnt = 0;

    while (gets(input)) {
        for (int i = 0; input[i]; i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                alpha[input[i] - 'a']++;
                if (alpha[input[i] - 'a'] > cnt) cnt = alpha[input[i] - 'a'];
            }
        }
    }
    
    for(int i = 0; i < 26; i++) {
        if (alpha[i] == cnt)
            printf("%c", i + 'a');
    }
    return 0;
}