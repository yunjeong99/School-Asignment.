#include <iostream>
#include <vector>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

vector<vector<int>> map;
vector<vector<int>> search_map;
vector<pair<int, int>> point;
vector<int> push_num;
int n, m, num, i, j, sum = 0, sum1, sum2, flag = 0;

void start(vector<vector<int>> &search_map) { //초기설정
	sum = 0;
	for (i = 0; i < n; i++) { //왼쪽 가
		if (map[i][0] == -1) { //밑으로 -1
			for (j = i; j < n; j++) 
				search_map[j][0] = -1;
			break;
		}
		sum += map[i][0];
		search_map[i][0] = sum;
	}
	sum = 0;
	for (j = 0; j < m; j++) { //위
		if (map[0][j] == -1) {
			for (i = j; i < m; i++)
				search_map[0][i] = -1;
			break;
		}
		sum += map[0][j];
		search_map[0][j] = sum;
	}
	for (i = 0; i < n; i++) { //오른쪽 가
		if (map[i][m - 1] == -1) {
			for (j = 0; j <= i; j++) 
				search_map[j][m - 1] = -1;
			break;
		}
	}
	for (j = 0; j < m; j++) { //밑
		if (map[n - 1][j] == -1) {
			for (i = 0; i < j; i++)
				search_map[n - 1][i] = -1;
			break;
		}
	}
}

void start_grid(vector<vector<int>>& search_map) {
	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {
			if (map[i][j] == -1 || search_map[i][j] == -1) {
				search_map[i][j] = -1;

				continue;
			}
			if (search_map[i][j - 1] == -1 && search_map[i - 1][j] != -1) { //왼쪽 -1일때
				search_map[i][j] = search_map[i - 1][j] + map[i][j];
			}
			else if (search_map[i - 1][j] == -1 && search_map[i][j - 1] != -1) { //위가 -1일때
				search_map[i][j] = search_map[i][j - 1] + map[i][j];
			}
			else if (search_map[i][j - 1] == -1 && search_map[i - 1][j] == -1) { //둘다 -1일때
				search_map[i][j] = -1;
			}
			else {
				sum1 = search_map[i - 1][j] + map[i][j];
				sum2 = search_map[i][j - 1] + map[i][j];
				if (sum1 <= sum2) {
					search_map[i][j] = sum1;
				}				
				else {
					search_map[i][j] = sum2;
				}
			}
			if (i == n - 1 && j == m - 1) return;
		}
	}
}

void search_point(vector<vector<int>>& search_map) {
	while (true) {
		point.push_back(make_pair(i, j));
		if (i == 0 && j == 0) {
			break;
		}
		if (i == 0 && j != 0) { //맨 위
			j--;
		}
		else if (i != 0 && j == 0) { //맨 왼쪽
			i--;
		}
		else {
			if (search_map[i][j - 1] == -1 && search_map[i - 1][j] != -1) {
				i--; //좌 막혔을때
			}
			else if (search_map[i - 1][j] == -1 && search_map[i][j - 1] != -1) j--; //위 막혔을 때
			else {
				if (search_map[i - 1][j] <= search_map[i][j - 1]) { //위로 이동
					i--;
				}
				else { //좌측으로 이동
					j--;
				}
			}
		}
	}
}

int main() {
	ifstream input("gridpath.inp");
	ofstream output("gridpath.out");

	input >> n;		input >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			input >> num;
			push_num.push_back(num);
		}
		map.push_back(push_num);
		push_num.clear();
	}
	vector<vector<int>> search_map(n, vector<int>(m, 0));
	start(search_map);
	start_grid(search_map);

	if (search_map[n - 1][m - 1] == -1) {
		output << "No path." << endl;
	}
	else {
		i = n - 1;	j = m - 1;
		search_point(search_map);

		output << search_map[n - 1][m - 1] << endl;
		for (i = point.size()-1; i >= 0; i--) {
			output << "(" << point[i].first << " " << point[i].second << ")" << endl;
		}

	}

	input.close();
	output.close();
	return 0;
}