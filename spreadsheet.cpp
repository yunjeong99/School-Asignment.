#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#pragma warning (disable:4996)
using namespace std;

int main() {
	FILE* input = fopen("spreadsheet.inp", "rt");
	FILE* output = fopen("spreadsheet.out", "wt");
	int T, len = 0, k = 1, count = 0, sum = 0, cnt;
	char arr[20];
	vector<char>arr_nr; //row 배열
	vector<int>arr_nc;
	vector<int>m;
	vector<char>result;
	char A[27] = { '0' };
	char c;
	char a = 'A';

	fscanf(input, "%d%c", &T,&c);
	for (int i = 0; i < T; i++) {
		arr[len] = '\0';
		len = 0;
		sum = 0;
		fscanf(input, "%s", &arr);
		for (int j = 0; j < sizeof(arr); j++) { // arr에 들어있는 원소까지의 배열 크기 
			if (arr[j] == NULL)
				break;
			len++;
		}

		if (isdigit(arr[1])) { // R~C~
			cnt = 0;
			for (int j = 1; j < len; j++) {
				if (arr[j] == 'C')	break;
				cnt++;
			}
			if (cnt == (len-1)) { //A~
				int f = (int)arr[0] - 64;
				fprintf(output, "R");
				for (int j = 1; j < len; j++) 
					fprintf(output, "%c", arr[j]);
				fprintf(output, "C%d\n", f);
			}
			else {
				count = 0;
				for (k = 1; k < len; k++) {
					if (isdigit(arr[k])) // row배열
						arr_nr.push_back(arr[k]);
					else break;
				}
				k++;
				for (int j = k; j < len; j++) {
					arr_nc.push_back(arr[j] - '0');
					count++;
				}
				int tens = 1;
				for (int j = count - 1; j >= 0; j--) {
					sum = sum + arr_nc[j] * tens;
					tens *= 10;
				}
				while (true) {
					if (sum < 26)
						break;
					m.push_back(sum % 26);
					sum /= 26;
				}

				if (m.size() > 0) {
					if (m.back() == 0) { // m 맨 뒤 원소가 0일 경우
						sum -= 1;
						m.back() += 26;
					}
					if (m[0] == 0) {
						result.push_back((char)m[0] + 90); //첫번째 원소 0일때
						if (m[1] == 0) { // 00인 경우
							if (2 < m.size()) {
								m[2] -= 1;
								m[1] += 25;
							}
							else
								m[1] += 25;
						}
						else {
							m[1] -= 1;
							if (m[1] < 0)
								m[1] += 26;
						}
					}
					else		result.push_back((char)m[0] + 64); //0 아닐때

					for (int j = 1; j < m.size(); j++) { //두번째 원소부터 push_back
						if (m[j] == 0) {
							result.push_back((char)m[j] + 90);
							if (j + 1 < m.size()) {
								m[j + 1] -= 1;
								if (m[j + 1] < 0)
									m[j + 1] += 26;
							}
							else
								sum -= 1;
						}
						else		result.push_back((char)m[j] + 64);
						if ((j + 1) == m.size())		break;
					}
					if (sum != 0)	result.push_back((char)sum + 64);

				}
				else  // m이 공백일 경우
					result.push_back((char)sum + 64);

				for (int j = result.size() - 1; j >= 0; j--)
					fprintf(output, "%c", result[j]);
				;			for (int j = 0; j < arr_nr.size(); j++)
					fprintf(output, "%c", arr_nr[j]);
				fprintf(output, "\n");
			}
			
		}

		else { //ABC~
			int f = (int)arr[0];
			sum = f - 64;
			k = 1;
			while (!isdigit(arr[k])) {
				f = arr[k];
				sum = sum * 26 + (f - 64);
				k++;
			}
			fprintf(output, "R");
			for (int j = k; j < len; j++)
				fprintf(output, "%c", arr[j]);
			fprintf(output, "C%d\n", sum);
		}
		arr_nr.clear();
		arr_nr.resize(0);
		arr_nc.clear();
		arr_nc.resize(0);
		m.clear();
		m.resize(0);
		result.clear();
		result.resize(0);
	}
	fclose(input);
	fclose(output);
	return 0;
}