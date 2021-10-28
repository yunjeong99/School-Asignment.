#include <iostream>
#include <vector>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

vector<int> bollon, arr;
vector<int> ::iterator it, iter, it_temp;
vector<vector<int>> result;
int cnt, temp, flag, max_sum;

void funcA(vector<int> ::iterator iter, vector<int> ::iterator it_temp) {
	for (it_temp = iter + 1; it_temp <= bollon.end() - 1; it_temp++) {
		if (*it_temp > * iter) {
			arr.push_back(*it_temp);
			cnt++;
			funcA(it_temp, it_temp);
		}
	}
	if (max_sum <= cnt) {
		max_sum = cnt;
		arr.push_back(cnt);
		result.push_back(arr);
		arr.erase(arr.end() - 1);
	}
	cnt--;	flag = 0;
	arr.erase(arr.end() - 1);
	return;
}

int main() {
	ifstream input("balloon.inp");
	ofstream output("balloon.out");

	int n, num, res;
	vector<vector<int>>::iterator k;

	while (true) {
		input >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			input >> num;
			bollon.push_back(num);
		}
		max_sum = 0; res = 0;
		for (it = bollon.begin(); it <= bollon.end() - 1; it++) {
			iter = it;
			arr.push_back(*it);
			cnt = 1;
			funcA(iter, iter);
		}
		for (int i = 0; i < result.size(); i++) {
			if (result[i].size() == max_sum + 1) res++;
		}
		output << max_sum << " " << res << endl;
		bollon.clear();		result.clear();	arr.clear();
	}
	input.close();
	output.close();
	return 0;
}