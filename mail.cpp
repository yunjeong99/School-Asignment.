#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
//#include <vector>
#pragma warning (disable:4996)
//using namespace std;

int m[8][6] = { { 0,0,0,0,0,0 }, { 0,0,1,1,1,1 } ,{ 0,1,0,0,1,1 },{ 0,1,1,1,0,0 },
					{ 1,0,0,1,1,0 } , { 1,0,1,0,0,1 } , { 1,1,0,1,0,1 } , { 1,1,1,0,1,0 } };

int arr[6];

int checking() {
	for (int i = 0; i < 8; i++) {
		int cnt = 0; //cnt 초기화
		for (int j = 0; j < 6; j++) {
			if (arr[j] == m[i][j])	cnt++;
			if (cnt >= 5) {
				switch (i) {
				case 0:
					return 'A';
				case 1:
					return 'B';
				case 2:
					return 'C';
				case 3:
					return 'D';
				case 4:
					return 'E';
				case 5:
					return 'F';
				case 6:
					return 'G';
				case 7:
					return  'H';
				}
			}
		}
	}
	return 'X';
}

int main() {
	FILE* input = fopen("mail.inp", "rt");
	FILE* output = fopen("mail.out", "wt");
	int T, n, num;
	char result, ch;

	fscanf(input, "%d\n", &T);
	for (int i = 0; i < T; i++) {
		fscanf(input, "%d\n", &n);
		for (int j = 0; j < n; j++) { //n개만큼
			for (int k = 0; k < 6; k++) {
				fscanf(input, "%c", &ch);
				arr[k] = (int)ch - 48;
			}
			result = checking();
			fprintf(output, "%c", result);
			arr[6] = { 0, };
		}
		fprintf(output, "\n");
	}
	fclose(input);
	fclose(output);
	return 0;
}