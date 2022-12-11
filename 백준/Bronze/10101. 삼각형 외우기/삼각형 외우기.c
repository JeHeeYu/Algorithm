#include <stdio.h>

int main() {
	int ang[3] = { 0, };
	int sum = 0, cnt = 0;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &ang[i]);
		sum += ang[i];
		if (ang[i] == 60)
			cnt++;
	}

	if (cnt == 3)
		printf("Equilateral");
	else if (sum == 180) {
		if (ang[0] == ang[1] || ang[1] == ang[2] || ang[0] == ang[2])
			printf("Isosceles");
		else
			printf("Scalene");
	}
	else
		printf("Error");
}