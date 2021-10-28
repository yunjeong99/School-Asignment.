#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int main() {
	FILE* input = fopen("srtf.inp", "rt");
	FILE* output = fopen("srtf.out", "wt");
	vector<int> num, arri, used, used2;
	int n, a, b, c, i, j, k, key, sum = 0, result = 0, min = 999999, min2;

	fscanf(input, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(input, "%d %d %d", &a, &b, &c);
		num.push_back(a);
		arri.push_back(b);
		used.push_back(c);
		used2.push_back(c);
	}

	for (i = 1; i < arri.size(); i++) { //도착시간 순서대로 정렬
		key = arri[i];
		k = i;
		j = i - 1;
		while (j >= 0) {
			if (key < arri[j]) {
				swap(arri[j], arri[j + 1]);
				swap(num[j], num[j + 1]);
				swap(used[j], used[j + 1]);
				swap(used2[j], used2[j + 1]);
				k--;
			}
			else if (key == arri[j]) { //도착시간 같을때
				if (used[k] < used[j]) { //CPU사용시간 비교 정렬
					swap(arri[j], arri[j + 1]);
					swap(num[j], num[j + 1]);
					swap(used[j], used[j + 1]);
					swap(used2[j], used2[j + 1]);
				}
				else if (used[k] == used[j]) { //CPU사용시간 같을때
					if (num[k] < num[j]) { //프로세스 번호 비교 정렬
						swap(arri[j], arri[j + 1]);
						swap(num[j], num[j + 1]);
						swap(used[j], used[j + 1]);
						swap(used2[j], used2[j + 1]);
					}
				}
			}
			j--;
		}

	}
	if (arri[0] != 0)	sum += used[0];
	key = 0;

	while (true) {
		if (num.empty())	break;
		for (i = 1; i < num.size(); i++) {
			if ((sum + used[key]) - arri[i] < 0) { //음수인 경우
				sum += used[key];
				result += (sum - arri[key] - used2[key]);
				used[key] = 0;
				k = 0;
				while (k < i) {
					if (used[k] != 0) {
						num.erase(num.begin() + key);
						arri.erase(arri.begin() + key);
						used.erase(used.begin() + key);
						used2.erase(used2.begin() + key);
						key = k;
						i = key;
						break;
					}
					if (k == i - 1) {
						sum += (arri[i] - sum);
						key = i;
					}
					k++;
				}
			}
			else if ((sum + used[key]) - arri[i] >= 0) { //양수인 경우
				if (arri[key] == arri[i]) { //도착시간 같은 경우
					k = key + 1;
					while (k < num.size()) {
						if ((arri[k] != arri[key]) && ((sum + used[key]) - arri[k] > 0)) { //19 19 20 경우
							if (used[k] < used[key]) {
								used[key] -= (arri[k] - sum);
								sum += (arri[k] - sum);
								key = k;
								break;
							}
						}
						k++;
					}
					if (k != key) {
						sum += used[key];
						used[key] = 0;
						key = i;
					}
				}
				else {
					used[key] -= (arri[i] - sum);
					sum += (arri[i] - sum);
					if (used[key] == 0) {
						result += (sum - arri[key] - used2[key]);
						key = i;
					}
					if (used[i] < used[key]) {
						key = i;
					}
				}
			}
		}
		key = num.size();
		k = 0, i = 0;
		while (k < key) {
			if (used[i] == 0) {
				num.erase(num.begin() + i);
				arri.erase(arri.begin() + i);
				used.erase(used.begin() + i);
				used2.erase(used2.begin() + i);
			}
			else i++;
			k++;
		}

		while (1) {
			if (num.empty())	break;
			min = 999999;
			for (i = 0; i < num.size(); i++) {
				if (used[i] < min) {
					min = used[i];
					key = i;
				}
			}
			sum += used[key];
			result += (sum - arri[key] - used2[key]);
			num.erase(num.begin() + key);
			arri.erase(arri.begin() + key);
			used.erase(used.begin() + key);
			used2.erase(used2.begin() + key);
		}
	}

	

	fprintf(output, "%d", result);
	fclose(input);
	fclose(output);
}