#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

int main() {
	FILE* input = fopen("sequence.inp", "rt");
	FILE* output = fopen("sequence.out", "wt");
	int count, num, limit, i = 1;
	long long A;

	while (true) {
		fscanf(input, "%d %d", &num, &limit);
		A = num;
		count = 0;
		if ((num == -1) && (limit == -1))
			break;
		while (A != 1) {
			if (A > limit)
				break;
			if (A % 2 == 0) {
				A /= 2;
				count++;
			}
			else {
				A = 3 * A + 1;
				count++;
			}
		}
		if (A == 1)
			count++;
		fprintf(output, "Case %d: A = %d, limit = %d, number of terms = %d\n", i, num, limit, count);
		i++;
	}

	fclose(input);
	fclose(output);
	return 0;
}