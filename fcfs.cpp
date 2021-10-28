#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int main() {
	FILE* input = fopen("fcfs.inp", "rt");
	FILE* output = fopen("fcfs.out", "wt");

	vector<int> num, arri, used;
	int n, a, b, c, i, k, temp_u, temp_n, min = 999999, sum = 0, result = 0;

	fscanf(input, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(input, "%d %d %d", &a, &b, &c);
		num.push_back(a);
		arri.push_back(b);
		used.push_back(c);
	}

	for (i = 0; i < arri.size(); i++) { //도착시간 가장 짧은 프로세스 찾기
		if (arri[i] < min) {
			min = arri[i];
			k = i;
		}
	}
	if (min != 0)	sum += min;
	sum += used[k];
	num.erase(num.begin() + k);
	arri.erase(arri.begin() + k);
	used.erase(used.begin() + k);

	while (true) {
		if (num.empty())	break;
		min = 999999;
		for (i = 0; i < arri.size(); i++) {
			if (arri[i] < min) {
				min = arri[i];
				temp_n = num[i];
				temp_u = used[i];
				k = i;
			}
			else if (arri[i] == min) {
				if (num[i] < temp_n) {
					min = arri[i];
					temp_n = num[i];
					temp_u = used[i];
					k = i;
				}
			}
		}
		if (min < sum) {
			result += (sum - min);
			sum += temp_u;
		}
		else	sum += (min - sum + temp_u);
		num.erase(num.begin() + k);
		arri.erase(arri.begin() + k);
		used.erase(used.begin() + k);
	}
	fprintf(output, "%d", result);
	fclose(input);
	fclose(output);
	return 0;
}