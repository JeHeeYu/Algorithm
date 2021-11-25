#include <stdio.h>
#include <string.h>

int main() 
{
	char S[16];
	int num[15], sum = 0;
	scanf("%s", S);

	for (int j = 0; j < strlen(S); j++) 
	{
		if (S[j] == 'A' || S[j] == 'B' || S[j] == 'C')
			sum += 3;
		if (S[j] == 'D' || S[j] == 'E' || S[j] == 'F')
			sum += 4;
		if (S[j] == 'G' || S[j] == 'H' || S[j] == 'I')
			sum += 5;
		if (S[j] == 'J' || S[j] == 'K' || S[j] == 'L')
			sum += 6;
		if (S[j] == 'M' || S[j] == 'N' || S[j] == 'O')
			sum += 7;
		if (S[j] == 'P' || S[j] == 'Q' || S[j] == 'R' || S[j] == 'S')
			sum += 8;
		if (S[j] == 'T' || S[j] == 'U' || S[j] == 'V')
			sum += 9;
		if (S[j] == 'W' || S[j] == 'X' || S[j] == 'Y' || S[j] == 'Z')
			sum += 10;
	}
	printf("%d", sum);
}
