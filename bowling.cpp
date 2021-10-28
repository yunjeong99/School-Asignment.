#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996

struct Frame {
	int score1;
	int score2;
	int flag; //0이면 none, 1이면 spare, 2이면 strike
};

struct Frame frame[11];
int n, i, j, sum;

int calc() {
	if (frame[i].flag == 2) {
		sum += frame[i].score1 + frame[i].score2 + frame[i + 1].score1 + frame[i + 1].score2;
		if (i != 9 && frame[i + 1].score1 == 10 && frame[i + 1].score2 == 0) {
			sum += frame[i + 2].score1;
		}
	}
	else if (frame[i].flag == 1)
		sum += frame[i].score1 + frame[i].score2 + frame[i + 1].score1;
	else
		sum += frame[i].score1 + frame[i].score2;
	return sum;
}
int main() {
	FILE* input = fopen("bowling.inp", "rt");
	FILE* output = fopen("bowling.out", "wt");

	int result = 0;
	fscanf(input, "%d", &n);

	for (j = 0; j < n; j++) {
		for (i = 0; i < 10; i++) {
			fscanf(input, "%d", &frame[i].score1);
			if (frame[i].score1 == 10 && i < 9) {
				frame[i].score2 = 0;
			}
			else {
				fscanf(input, "%d", &frame[i].score2);
			}

			if (i == 9 && (frame[i].score1 + frame[i].score2) >= 10) {
				fscanf(input, "%d", &frame[10].score1);
				frame[10].score2 = 0;
			}

			if (frame[i].score1 == 10)	frame[i].flag = 2; //strike
			else if ((frame[i].score1 + frame[i].score2) == 10)	frame[i].flag = 1; //spare
			else frame[i].flag = 0;

		}
		sum = 0;
		for (i = 0; i < 10; i++) 
			result = calc();
		
		fprintf(output, "%d\n", result);
	}
	fclose(input);
	fclose(output);
	return 0;
}