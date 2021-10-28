#include <iostream>
#include <math.h>
#include <algorithm>
#include<stdlib.h>     
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

struct  Temp{
	int w, h;
	int w_h;
	long long int sum;
}ha;
Temp temp[100000];

int funcA(int m, int n) {
	int tmp;
	if (m < n)
	{
		tmp = m;
		m = n;
		n = tmp;
	}
	if (n == 0)
		return m;
	else
		return funcA(n, m % n);
}


int compare(const void* v1, const void* v2)//회원 번호로 비교 함수
{
	const Temp* temp1 = (const Temp*)v1;
	const Temp* temp2 = (const Temp*)v2;
	return temp1->w_h - temp2->w_h;
}

int binary(int begin, int finish, int tmp, int num) {
	if (temp[tmp].sum == num) {
		return tmp;
	}
	else if (temp[tmp].sum > num) {
		if (begin == finish) return tmp;
		else {
			return binary(begin, tmp, (begin + finish) / 2, num);
		}
	}
	else if (temp[tmp].sum < num) {
		if (begin == finish || finish - begin == 1) return tmp;
		else {
			return binary(tmp, finish, (tmp + finish) / 2, num);
		}
	}
	
}
int main() {
	ifstream input("rectangles.inp");
	ofstream output("rectangles.out");
	int n, length, i, j, result;

	input >> n;

	int k = 0, x, y, idx = 0;
	double a, b, c;

	for (x = 1; idx < 100000; x++) {
		for (y = x - 1; y > 0; y--) {
			int result = 0;
			if ((2 * x * y) > ((x * x) - (y * y)))	temp[idx].w = (2 * x * y);
			else temp[idx].w = (x * x) - (y * y);
			if ((2 * x * y) < ((x * x) - (y * y))) 	temp[idx].h = (2 * x * y);
			else temp[idx].h = (x * x) - (y * y);
			temp[idx].w_h = 2 * (temp[idx].w + temp[idx].h);

			if (funcA(temp[idx].w, temp[idx].h) != 1 && temp[idx].w_h < 1000000)	result = 1;
			if (result != 1) {
				idx++;
			}
		}
	}
	qsort(temp, 100000, sizeof(temp[0]), compare);
	temp[0].sum = temp[0].w_h;
	for (i = 1; i < 100000; i++) {
		temp[i].sum = temp[i - 1].sum + temp[i].w_h;
	}
	for (i = 0; i < n; i++) {
		input >> length;
		result = binary(0, 99999, 99999, length) + 1;
		output << result << endl;
	}

	input.close();
	output.close();
	return 0;
}