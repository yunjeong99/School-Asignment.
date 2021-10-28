#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int main() {
	FILE* input = fopen("sjf.inp", "rt");
	FILE* output = fopen("sjf.out", "wt");

	vector<int> num, arri, used, def;
	int n, a, b, c, i, k, sum = 0, res = 0, temp1, temp2, del, result = 0;
	int min = 999999;
	fscanf(input, "%d", &n);

	for (i = 0; i < n; i++) {
		fscanf(input, "%d %d %d", &a, &b, &c);
		num.push_back(a);
		arri.push_back(b);
		used.push_back(c);
	}

	for (i = 0; i < arri.size(); i++) {
		if (arri[i] < min) {
			min = arri[i];
			temp1 = i;
		}
	}
	if (min != 0) 		sum += min;
	else		sum += used[temp1];

	num.erase(num.begin() + temp1);
	arri.erase(arri.begin() + temp1);
	used.erase(used.begin() + temp1);

	while (true) {
		if (num.empty())		break;
		min = 999999;
		for (i = 0; i < used.size(); i++) {
			if (arri[i] < sum) {
				def.push_back(i);
			}
		}
		for (i = 0; i < def.size(); i++) {
			k = def[i];
			if (used[k] <= min) {
				if (used[k] == min) { //사용 시간 같을때
					if (arri[k] < temp2) { //도착시간 우선순위
						min = used[k];
						temp1 = num[k];
						temp2 = arri[k];
					}
					else if (arri[k] == temp2) { //프로세스 번호 우선순위
						if (num[k] < temp1) {
							min = used[k];
							temp1 = num[k];
							temp2 = arri[k];
							del = def[i];
							continue;
						}
					}
				}
				min = used[k];
				temp1 = num[k];
				temp2 = arri[k];
				del = def[i];
			}


		}
		if (def.empty()) { //도착한 게 없을 때
			int min2 = 999999;
			for (i = 0; i < used.size(); i++) {
				if (arri[i] < min2) {
					min2 = arri[i];
					temp1 = num[i];
					temp2 = used[i];
					k = i;
				}
				else if (arri[i] == min) { //똑같이 도착했을 때
					if (used[i] == temp2) { //작업량 같을 경우
						if (num[i] < temp1) {
							min2 = arri[i];
							temp1 = num[i];
							temp2 = used[i];
							k = i;
						}
					}
					else if (used[i] < temp2) {
						min2 = arri[i];
						temp1 = num[i];
						temp2 = used[i];
						k = i;
					}
				}
			}
			sum += (arri[k] - sum + used[k]);
			num.erase(num.begin() + k);
			arri.erase(arri.begin() + k);
			used.erase(used.begin() + k);
		}
		else {
			res = sum - temp2;
			result += res;
			sum += min;
			num.erase(num.begin() + del);
			arri.erase(arri.begin() + del);
			used.erase(used.begin() + del);
			def.clear();
		}
	}
	fprintf(output, "%d", result);
	fclose(input);
	fclose(output);
}




