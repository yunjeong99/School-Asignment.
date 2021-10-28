#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)

int divisor(int x, int y) {
	int a = x;
	int b = y;
	int j, result = 0;

	for (int i = a; i <= b; i++) {
		int cnt = 0;
		for (j = 1; j * j < i; j++) {
			if (i % j == 0)
				cnt += 2;
		}
		if (j * j == i)
			cnt++;
		if (i % cnt == 0)
			result++;
	}
	return result;
}

int main(void) {
	FILE* input;
	FILE* output;
	int T;

	if ((input = fopen("divisor.inp", "rt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "divisor.inp");
	}
	if ((output = fopen("divisor.out", "wt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "divisor.out");
	}

	fscanf(input, "%d", &T);

	for (int i = 1; i <= T; i++) {
		int a, b;
		fscanf(input, "%d %d", &a, &b);
		fprintf(output, "%d\n", divisor(a, b));
	}
	
}
