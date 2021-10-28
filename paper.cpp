#include <stdio.h>
#pragma warning (disable:4996)

int narr[50][50];
int marr[50][50];

int main() {
	FILE* input = fopen("paper.inp", "rt");
	FILE* output = fopen("paper.out", "wt");
	int T, n, m, sum, r;
	fscanf(input, "%d", &T);

	for (int k = 0; k < T; k++) {
		sum = 0, r = 0;//초기화
		fscanf(input, "%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m-1; j++) {
				fscanf(input, "%d", &narr[i][j]);
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				fscanf(input, "%d", &marr[i][j]);
			}
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m-1; j++) {
				sum = 0;
				sum = narr[i][j] + narr[i + 1][j] + marr[i][j] + marr[i][j + 1];
				if (sum == 1 || sum == 3)
					continue;
				else {
					r += 1;
					goto EXIT;
				}
			}
		}
	EXIT:
		if (r == 1) //인위적
			fprintf(output, "%d ", 0);
		else //자연스러움
			fprintf(output, "%d ", 1);
	}
	fclose(input);
	fclose(output);
	return 0;
}