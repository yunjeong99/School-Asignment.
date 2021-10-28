#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning(disable:4996)


int start, end, k; 
int point_x, point_y, a, b;
int b_arr[10][10] = {};
int b_save[100] = {};
int res[10][10] = {}; 
long long result = 0; 

int bSearch(int x, int b_save[]) {
	int flag = 0;
	for (int i = 0; b_save[i] != NULL; i++) {
		if (x == b_save[i]) {
			flag = 0;
			break;
		}
		else
			flag = 1;
	}
	return flag;
}

long long fac(int num) {
	long long sum = 1;
	for (int i = num; i > 1; i--) {
		sum = sum * i;
	}
	return sum;
}

void makeBlock() {
	if (point_x <= 0 && point_y <= 0) {
		int tmp = start;
		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= b; j++) {
				b_arr[i][j] = tmp + j;
			}
			tmp += 10;
		}
	}
	else if (point_x <= 0 && point_y >= 0) {
		int tmp = start;
		for (int i = 0; i <= a; i++) {
			for (int j = b; j >= 0; j--) {
				b_arr[i][j] = tmp - (b - j);
			}
			tmp += 10;
		}
	}
	else if (point_x >= 0 && point_y >= 0) {
		int tmp = start;
		for (int i = a; i >= 0; i--) {
			for (int j = b; j >= 0; j--) {
				b_arr[i][j] = tmp - (b - j);
			}
			tmp -= 10;
		}
	}
	else if (point_x >= 0 && point_y <= 0) {
		int tmp = start;
		for (int i = a; i >= 0; i--) {
			for (int j = 0; j <= b; j++) {
				b_arr[i][j] = tmp + j;
			}
			tmp -= 10;
		}
	}
}

void makeResult() {
	if (point_x <= 0 && point_y <= 0) {
		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= b; j++) {
				res[i][j] = bSearch(b_arr[i][j], b_save);
				if (j > 0 && res[0][j - 1] == 0)
					res[0][j] = 0;
				if (i > 0 && res[i - 1][0] == 0)
					res[i][0] = 0;
			}
		}

		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				if (res[i][j] != 0)
					res[i][j] = res[i][j - 1] + res[i - 1][j];
			}
		}
		result = res[a][b];
	}
	else if (point_x <= 0 && point_y >= 0) {
		for (int i = 0; i <= a; i++) {
			for (int j = b; j >= 0; j--) {
				res[i][j] = bSearch(b_arr[i][j], b_save);

				if (j < b && res[0][j + 1] == 0)
					res[0][j] = 0;
				if (i > 0 && res[i - 1][b] == 0)
					res[i][b] = 0;
			}
		}

		for (int i = 1; i <= a; i++) {
			for (int j = b - 1; j >= 0; j--) {
				if (res[i][j] != 0)
					res[i][j] = res[i][j + 1] + res[i - 1][j];
			}
		}

		result = res[a][0];
	}
	else if (point_x >= 0 && point_y >= 0) {
		for (int i = a; i >= 0; i--) {
			for (int j = b; j >= 0; j--) {
				res[i][j] = bSearch(b_arr[i][j], b_save);

				if (j < b && res[a][j + 1] == 0)
					res[a][j] = 0;
				if (i < a && res[i + 1][b] == 0)
					res[i][b] = 0;
			}
		}

		for (int i = a - 1; i >= 0; i--) {
			for (int j = b - 1; j >= 0; j--) {
				if (res[i][j] != 0)
					res[i][j] = res[i + 1][j] + res[i][j + 1];
			}
		}

		result = res[0][0];
	}
	else if (point_x >= 0 && point_y <= 0) {
		for (int i = a; i >= 0; i--) {
			for (int j = 0; j <= b; j++) {
				res[i][j] = bSearch(b_arr[i][j], b_save);

				if (j > 0 && res[a][j - 1] == 0)
					res[a][j] = 0;
				if (i < a && res[i + 1][0] == 0)
					res[i][0] = 0;
			}
		}

		for (int i = a - 1; i >= 0; i--) {
			for (int j = 1; j <= b; j++) {
				if (res[i][j] != 0)
					res[i][j] = res[i + 1][j] + res[i][j - 1];
			}
		}

		result = res[0][b];
	}
}

int main() {

	FILE* input = fopen("path.inp", "rt");
	FILE* output = fopen("path.out", "wt");

	fscanf(input, "%d %d %d", &start, &end, &k);

	if (k != 0) {
		for (int i = 0; i < k; i++) {
			fscanf(input, "%d ", &b_save[i]);
		}
	}

	point_x = start / 10 - end / 10;
	point_y = start % 10 - end % 10;
	a = point_x;
	b = point_y;

	if (a < 0)		a = -a;
	if (b < 0)		b = -b;

	if (k != 0)  makeBlock(); 

	if (k != 0) 	makeResult();
	else  result = fac(a + b) / fac(a) / fac(b);	

	if (start == end)	result = 0;

	fprintf(output, "%lld", result);

	fclose(input);
	fclose(output);
	return 0;
}