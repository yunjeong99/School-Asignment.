#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

int main(void) {
	FILE* input = fopen("jollo.inp", "rt");
	FILE* output = fopen("jollo.out", "wt");
	int a[3], b[2]; //a:°øÁÖ, b:¿ÕÀÚ
	int max;

	while (true) {
		for (int i = 0; i < 3; i++) {
			fscanf(input, "%d", &a[i]);
		}
		if (a[0] == 0) break;
		for (int i = 0; i < 2; i++) {
			if (a[i] < a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				if (i == 1) {
					if (a[i] > a[i - 1]) {
						temp = a[i];
						a[i] = a[i - 1];
						a[i - 1] = temp;
					}
				}
			}
		}

		for (int i = 0; i < 2; i++)
			fscanf(input, "%d", &b[i]);
		if (b[0] < b[1]) {
			int temp = b[0];
			b[0] = b[1];
			b[1] = temp;
		}

		if (b[0] < a[0]) { //1ÆÐ
			if (b[1] < a[1]) { //2ÆÐ
				fprintf(output, "%d\n", -1);
				continue;
			}
			else { //1ÆÐ 1½Â
				if ((a[1] + 1) == b[1]) {
					fprintf(output, "%d\n", b[1] + 1);
					continue;
				}
				else {
					fprintf(output, "%d\n", a[1] + 1);
					continue;
				}
			}
		}

		else if (b[0] > a[0]) { //1½Â
			if (b[1] < a[0]) { //1½Â+¾Ö¸ÅÇÑ 1½Â
				fprintf(output, "%d\n", a[0] + 1);
				continue;
			}
			else if ((b[1] > a[1]) && (b[1] > a[2])) { //¹«Á¶°Ç 2½Â
				if (a[2] > 1)
					fprintf(output, "%d\n", 1); //1Ãâ·Â
				else if (a[2] == 1) {
					if (a[1] == 2) {
						if (a[0] == 3) {
							fprintf(output, "%d\n", a[0] + 1); //4Ãâ·Â
							continue;
						}
						fprintf(output, "%d\n", a[1] + 1); //3Ãâ·Â
						continue;
					}
					else {
						fprintf(output, "%d\n", a[2] + 1); //2Ãâ·Â
						continue;
					}
				}
			}
			
			else { //1½Â1ÆÐ
				if ((a[0] + 1) == b[1]) {
					if ((a[0] + 2) == b[0]) {
						fprintf(output, "%d\n", a[0] + 3);
						continue;
					}
					fprintf(output, "%d\n", a[0] + 2);
					continue;
				}
				fprintf(output, "%d\n", a[0] + 1);
				continue;
			}
		}
	}

	fclose(input);
	fclose(output);
	return 0;
}


/*
include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

int main(void) {
	FILE* input = fopen("bridge.inp", "rt");
	FILE* output = fopen("bridge.out", "wt");



	fclose(input);
	fclose(output);
	return 0;
}*/