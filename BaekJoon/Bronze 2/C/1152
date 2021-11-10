#include <stdio.h> 
#include <string.h>

int main() {
	int cnt = 1;
	char S[1000000];
	scanf("%[^\n]s", S);

	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == ' ')
			cnt++;
	}

	if (S[0] == ' ' && S[strlen(S) - 1] == ' ')
		cnt -= 2;
	else if (S[0] == ' ')
		cnt -= 1;
	else if (S[strlen(S) - 1] == ' ')
		cnt -= 1;

	printf("%d", cnt);
}
