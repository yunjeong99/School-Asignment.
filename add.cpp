#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int main() {
	FILE* input = fopen("add.inp", "rt");
	FILE* output = fopen("add.out", "wt");
	int cnt, num, sum, result, k;
	vector<int> arr;
	vector<int> add;
	vector<int>::iterator iter;

	while (true) {
		fscanf(input, "%d", &cnt);
		if (cnt == 0)
			break;
		sum = 0, result = 0, k = 0;
		for (int i = 0; i < cnt; i++) { //숫자 받기
			fscanf(input, "%d", &num);
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());
		while (true) {
			if (k == cnt-1) //
				break;
			sum = 0;
			sum = arr[0] + arr[1];
			add.push_back(sum);
			if (sum <= arr[0]) { //정렬x
				iter = arr.begin(); //arr[0] 제거
				arr.erase(iter);
				arr[0] = sum;
			}
			else { //정렬 
				iter = arr.begin(); //arr[0] 제거
				arr.erase(iter);
				iter = arr.begin(); //arr[1] 제거
				arr.erase(iter);
				arr.push_back(sum);
				sort(arr.begin(), arr.end());
			}
			
			k++;
		}
		for (int j = 0; j < add.size(); j++)
			result += add[j];
		fprintf(output, "%d\n", result);
		arr.clear();
		arr.resize(0);
		add.clear();
		add.resize(0);
	}
	fclose(input);
	fclose(output);
	return 0;
}