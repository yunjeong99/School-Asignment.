#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

int fraction(int k) {
	int x, y, a, b, count = 0;
	for (y = k + 1; y <= k * 2; y++) {
		a = k * y;
		b = y - k;
		if (a % b == 0)
			count++;
	}
	return count;
}

int main() {
	FILE* input = fopen("fraction.inp", "rt");
	FILE* output = fopen("fraction.out", "wt");

	int num;
	while (true) {
		fscanf(input, "%d", &num);
		if (num == 0)
			break;
		fprintf(output,"%d\n",fraction(num));
	}

	fclose(input);
	fclose(output);
	return 0;
}