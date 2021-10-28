#include <iostream>
#include <stdio.h>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

bool check_prime(int num) {
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0)
			return false; //소수 아님
	}
	return true; //소수
}

int getSum(int num) {
	int sum = 0, i = 2;
	for (i = 2; i <= num; i++) {
		while (num % i == 0) {
			num /= i;
			sum += i;
		}
	}
	return sum;
}

int main() {
	FILE* input = fopen("primefactor.inp", "rt");
	FILE* output = fopen("primefactor.out", "wt");
	vector<int> vec;
	vector<int>::iterator it;

	int n, num, result = 0;
	fscanf(input, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(input, "%d", &num);
		vec.push_back(num);
	}

	while (true) {
		if (vec.empty())	break;
		it = vec.begin();
		num = vec.front();
		if (check_prime(num) == true) { //소수일 경우
			fprintf(output, "Prime Number\n");
		}
		else {
			it = vec.begin();
			result = getSum(num);
			fprintf(output, "%d\n", result);
			//printf("%d\n", result);
		}
		vec.erase(it);

	}


	fclose(input);
	fclose(output);
	return 0;
}