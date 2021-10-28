#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

long long Mat[2][2] = { {1,1},{1,0} };
long long Res[2][2] = { {0,0},{0,0} };
long long Flag[2][2] = { {1,1},{1,0} };
long long  a, b, c, d, m, result, com, res1, res2;
long long resa, resb, resc, resd;
int n, cnt;

void clearArr() {
	Mat[0][0] = 1;	Mat[0][1] = 1;	Mat[1][0] = 1;	Mat[1][1] = 0;
	Res[0][0] = 0;	Res[0][1] = 0;	Res[1][0] = 0;	Res[1][1] = 0;
	//sw = 0;
}

void clear() {
	a = 0, b = 0, c = 0, d = 0, m = 0, result = 0, com = 0, res1 = 0, res2 = 0;
	resa = 0, resb = 0, resc = 0, resd = 0, result = 0;
}

void calc( long long num, int flag) {
	Res[0][0] = ((((Mat[0][0] % m) * (Mat[0][0] % m)) % m) + (((Mat[0][1] % m) * (Mat[1][0] % m)) % m)) % m;
	Res[0][1] = ((((Mat[0][0] % m) * (Mat[0][1] % m)) % m) + (((Mat[0][1] % m) * (Mat[1][1] % m)) % m)) % m; //0001 0111
	Res[1][0] = ((((Mat[1][0] % m) * (Mat[0][0] % m)) % m) + (((Mat[1][1] % m) * (Mat[1][0] % m)) % m)) % m; //1000 1110
	Res[1][1] = ((((Mat[1][0] % m) * (Mat[0][1] % m)) % m) + (((Mat[1][1] % m) * (Mat[1][1] % m)) % m)) % m; //1001 1111
	memcpy(Mat, Res, sizeof(Res)); //Mat에 Res값 복사	
	if (flag == 1) {
		Res[0][0] = ((((Mat[0][0] % m) * (Flag[0][0] % m)) % m) + (((Mat[0][1] % m) * (Flag[1][0] % m)) % m)) % m;
		Res[0][1] = ((((Mat[0][0] % m) * (Flag[0][1] % m)) % m) + (((Mat[0][1] % m) * (Flag[1][1] % m)) % m)) % m; //0001 0111
		Res[1][0] = ((((Mat[1][0] % m) * (Flag[0][0] % m)) % m) + (((Mat[1][1] % m) * (Flag[1][0] % m)) % m)) % m; //1000 1110
		Res[1][1] = ((((Mat[1][0] % m) * (Flag[0][1] % m)) % m) + (((Mat[1][1] % m) * (Flag[1][1] % m)) % m)) % m; //1001 1111
		memcpy(Mat, Res, sizeof(Res));
	}
}

void fib( long long num, int flag) {
	if (num == 1) {
		calc(num, flag);
	}
	else if (num % 2 == 0) {
		fib((num / 2), 0);
		//if ((num == com) && (sw == 0)) return;
		if (num == com)	return;
		calc(num, flag);
	}
	else if (num % 2 != 0) {
		fib((num / 2), 1);
		if (com == num) return;
		//sw++;
		calc(num, flag);
	}

}

int main() {
	FILE* input = fopen("fibonacci.inp", "rt");
	FILE* output = fopen("fibonacci.out", "wt");

	fscanf(input, "%d", &n);
	for (cnt = 0; cnt < n; cnt++) {
		clear();//행초
		clearArr();//변초
		fscanf(input, "%lld %lld %lld %lld %lld", &a, &b, &c, &d, &m);
		
		com = a; fib(a, 0);
		resa = Res[0][1] % m;
		clearArr();
		
		com = b;  fib(b, 0);
		resb = Res[0][1] % m;
		clearArr();
		com = c;  fib(c, 0);
		resc = Res[0][1] % m;
		clearArr();
		com = d; fib(d, 0);
		resd = Res[0][1] % m;
		//fprintf(output, "%d %d %d %d\n", resa, resb, resc, resd);
		res1 = ((resa * resb) % m);
		res2 = ((resc * resd) % m);
		//result = (((resa * resb)%m) + ((resc * resd)%m)) % m;
		result = (res1 + res2) % m;
		fprintf(output, "%lld\n", result);
	}
	fclose(input);
	fclose(output);
	return 0;
}
