#include <stdio.h>
#pragma warning (disable:4996)


int main() {
	FILE* input = fopen("block.inp", "rt");
	FILE* output = fopen("block.out", "wt");
	int T, n;
	int arr[1000][1000];

	fscanf(input, "%d", &T);
	for (int k = 0; k < T; k++) {
		arr[1000][1000] = { 0, };
		fscanf(input, "%d", &n);
		for (int i = 0; i < n; i++) { //arr 배열 받기
			for (int j = 0; j <= i; j++) {
				fscanf(input, "%d", &arr[i][j]);
			}
		}

		for (int u = 0; u < n; u++) {
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j <= i; j++) {
					if ((arr[i][j] == -1) && (arr[i + 1][j] != -1) && (arr[i + 1][j + 1] != -1)) {
						arr[i][j] = (arr[i + 1][j] + arr[i + 1][j + 1]) % 100;
					}
					if ((arr[i][j] != -1) && (arr[i + 1][j] == -1) && (arr[i + 1][j + 1] != -1)) {
						arr[i + 1][j] = (arr[i][j] + 100 - arr[i + 1][j + 1]) % 100;
					}
					if ((arr[i][j] != -1) && (arr[i + 1][j] != -1) && (arr[i + 1][j + 1] == -1)) {
						arr[i + 1][j + 1] = (arr[i][j] + 100 - arr[i + 1][j]) % 100;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				fprintf(output, "%d ", arr[i][j]);
			}
			fprintf(output, "\n");
		}
	}
	fclose(input);
	fclose(output);
	return 0;
}