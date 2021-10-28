#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

int main() {
	FILE* input = fopen("cross.inp", "rt");
	FILE* output = fopen("cross.out", "wt");
	int T, count, result = 0, cnt = 0, num = 0;
	int a[100000];
	int b[100000];

	fscanf(input, "%d", &T);

	for (int i = 0; i < T; i++) {
		result = 0;
		fprintf(output, "Case %d: ", i + 1);
		fscanf(input, "%d", &count);
		for (int j = 0; j < count; j++)
			fscanf(input, "%d ", &a[j]);
		for (int j = 0; j < count; j++)
			fscanf(input, "%d ", &b[j]);

		for (int j = 0; j < count; j++) {
			cnt = 0;
			for (int k = 0; k < count; k++) {
				if (a[j] == b[k]) {
					for (int u = 0; u < j; u++) {
						for (int m = cnt + 1; m < count; m++) {
							if (a[u] == b[m])
								result++;
						}
					}
					break;
				}
				else cnt++;
			}
		}
		fprintf(output, "%d\n", result);
	}
	fclose(input);
	fclose(output);
	return 0;
}