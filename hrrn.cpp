#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable:4996)

int main() {
	FILE* input = fopen("hrrn.inp", "rt");
	FILE* output = fopen("hrrn.out", "wt");
	int n, a, b, c, i, k, min = 999999, sum = 0, result = 0;
	int temp_n, temp_u, temp_a;
	double temp, max;
	vector<int> num, arri, used, rank;
	
	fscanf(input, "%d", &n);
	for (i = 0; i < n; i++) { //입력파일에서 데이터 읽어옴
		fscanf(input, "%d %d %d", &a, &b, &c);
		num.push_back(a);
		arri.push_back(b);
		used.push_back(c);
	}

	for (i = 0; i < arri.size(); i++) { //도착시간 제일 작은 것 찾기
		if (arri[i] < min) {
			min = arri[i];
			k = i;
		}
	}
	if (min != 0)	sum += min; //min이 0이 아닐때 
	sum += used[k];
	num.erase(num.begin() + k);
	arri.erase(arri.begin() + k);
	used.erase(used.begin() + k);
	
	while (true) {
		if (num.empty())	break;
		max = 0;
		for (i = 0; i < num.size(); i++) {
			if (arri[i] < sum) { //총합시간 sum보다 먼저 도착해있는 경우
				temp = (((double)sum - (double)arri[i]) + (double)used[i]) / (double)used[i];
				if (temp > max) {
					max = temp;
					k = i;
				}
			}			
		}
		if (max == 0) { //sum보다 도착해있는게 없을 경우
			min = 99999;
			for (i = 0; i < num.size(); i++) {
				if (arri[i] < min) {
					min = arri[i];
					k = i;
				}
				else if (arri[i] == min) {
					if (num[i] < num[k]) {
						min = arri[i];
						k = i;
					}
				}
				sum += (min - sum); 
			}
		}
		result += sum - arri[k];
		sum += used[k];
		num.erase(num.begin() + k);
		arri.erase(arri.begin() + k);
		used.erase(used.begin() + k);

	}


	fprintf(output, "%d", result);
	fclose(input);
	fclose(output);
	return 0;
}