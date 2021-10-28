#include <stdio.h>
#include <fstream>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int flag; // 0상 1우 2좌
int x_max, x_min, x_sum, y_max, y_min, y_sum;
int n, i, x, y, result, j;
char c;
char front = 'F', back = 'B', right = 'R', left = 'L';

void point() {
	if (c == 'F') {
		if (flag == 0) { //위로 이동 
			y++;
			y_sum++;
			if (y_sum >= y_max)	y_max = y_sum;
		}
		else if (flag == 1) { // 오른쪽으로 이동
			x++;
			x_sum++;
			if (x_sum >= x_max)	x_max = x_sum;
		}
		else if (flag == 2) { //아래로 이동
			y--;
			y_sum--;
			if (y_sum <= y_min)	y_min = y_sum;
		}
		else if (flag == 3) { //좌로 이동
			x--;
			x_sum--;
			if (x_sum <= x_min)	x_min = x_sum;
		}
	}
	else if (c == 'B') {
		if (flag == 0) { //위를 보고 아래로 이동
			y--;
			y_sum--;
			if (y_sum <= y_min)	y_min = y_sum;
		}
		else if (flag == 1) { //오른쪽 보고 좌로 이동
			x--;
			x_sum--;
			if (x_sum <= x_min)	x_min = x_sum;
		}
		else if (flag == 2) { //아래 보고 위로 이동
			y++;
			y_sum++;
			if (y_sum >= y_max)	y_max = y_sum;
		}
		else if (flag == 3) {// 좌를 보고 우로 이동
			x++;
			x_sum++;
			if (x_sum >= x_max)	x_max = x_sum;
		}
	}
	else if (c == 'R') {
		if (flag == 0) 	flag = 1;
		else if (flag == 1)  	flag = 2;
		else if (flag == 2)  	flag = 3;
		else if (flag == 3)  	flag = 0;
	}
	else if (c == 'L'){
		if (flag == 0)		flag = 3;
		else if (flag == 1)		flag = 0;
		else if (flag == 2)		flag = 1;
		else if (flag == 3)		flag = 2;
	}
}


int main() {
	ifstream input("turtle.inp");
	ofstream output("turtle.out");

	input >> n;

	for (i = 0; i < n; i++) {
		x = 0, y = 0, flag = 0;
		x_max = 0, x_min = 0, y_max = 0, y_min = 0;
		x_sum = 0, y_sum = 0;
		string s;
		input >> s;
		
		for (j = 0; j < s.length(); j++) {
			c = s[j];
			point();
		}

		x_min *= (-1);
		y_min *= (-1);
		result = (x_min + x_max) * (y_min + y_max);
		output << result << endl;
	}
	input.close();
	output.close();
	return 0;
}