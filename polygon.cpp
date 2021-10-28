#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<pair<int, int>> poly1, poly11, poly2, poly22;
vector<pair<int, int>> comp;
vector<pair<int, int>> ::iterator it11;
vector<pair<int, int>> ::iterator it;
int num, x, y, tag, sum;
int n, cnt, i, j, k;
int flag; // 1µ¿ 2¼­ 3³² 4ºÏ

void check_point() {
	if (flag == 1) { //µ¿
		if (num < 0) {
			num *= (-1);
			flag = 3;
		}
		else flag = 4;
		x += num;
		if (tag == 1) poly1.push_back(make_pair(x, y));
		else poly2.push_back(make_pair(x, y));
	}
	else if (flag == 2) { //¼­
		if (num < 0) {
			num *= (-1);
			flag = 4;
		}
		else flag = 3;
		x -= num;
		if(tag==1) poly1.push_back(make_pair(x, y));
		else poly2.push_back(make_pair(x, y));
	}
	else if (flag == 3) { //³²
		if (num < 0) {
			num *= (-1);
			flag = 2;
		}
		else flag = 1;
		y -= num;
		if(tag==1) poly1.push_back(make_pair(x, y));
		else poly2.push_back(make_pair(x, y));
	}
	else if (flag == 4) { //ºÏ
		if (num < 0) {
			num *= (-1);
			flag = 1;
		}
		else flag = 2;
		y += num;
		if(tag==1) poly1.push_back(make_pair(x, y));
		else poly2.push_back(make_pair(x, y));
	}
}

void check_poly1() {
	sort(poly1.begin(), poly1.end());
	int calc_x, calc_y;
	int move_x = poly1[0].first;
	int move_y = poly1[0].second;
	if (move_x < 0)		calc_x = move_x * (-1);
	else calc_x = move_x;
	if (move_y < 0)		calc_y = move_y * (-1);
	else calc_y = move_y;

	if (move_x < 0 && move_y < 0) {
		for (j = 0; j < cnt; j++)
			poly11.push_back(make_pair(poly1[j].first +calc_x, poly1[j].second + calc_y));
	}
	else if (move_x < 0 && move_y >= 0) {
		for (j = 0; j < cnt; j++)
			poly11.push_back(make_pair(poly1[j].first + calc_x, poly1[j].second - calc_y));
	}
	else if (move_x >= 0 && move_y < 0) {
		for (j = 0; j < cnt; j++) {
			poly11.push_back(make_pair(poly1[j].first - calc_x, poly1[j].second + calc_y));
		}
	}
	else if (move_x >= 0 && move_y >= 0) {
		for (j = 0; j < cnt; j++) {
			poly11.push_back(make_pair(poly1[j].first - calc_x, poly1[j].second - calc_y));
		}
	}
}

void check_poly2() {
	sort(comp.begin(), comp.end());
	int calc_x, calc_y;
	int move_x = comp[0].first;
	int move_y = comp[0].second;
	if (move_x < 0)		calc_x = move_x * (-1);
	else calc_x = move_x;
	if (move_y < 0)		calc_y = move_y * (-1);
	else calc_y = move_y;

	if (move_x < 0 && move_y < 0) {
		for (j = 0; j < cnt; j++)
			poly22.push_back(make_pair(comp[j].first + calc_x, comp[j].second + calc_y));
	}
	else if (move_x < 0 && move_y >= 0) {
		for (j = 0; j < cnt; j++)
			poly22.push_back(make_pair(comp[j].first + calc_x, comp[j].second - calc_y));
	}
	else if (move_x >= 0 && move_y < 0) {
		for (j = 0; j < cnt; j++) {
			poly22.push_back(make_pair(comp[j].first - calc_x, comp[j].second + calc_y));
		}
	}
	else if (move_x >= 0 && move_y >= 0) {
		for (j = 0; j < cnt; j++) {
			poly22.push_back(make_pair(comp[j].first - calc_x, comp[j].second - calc_y));
		}
	}
}

bool compare_poly() {
	vector<pair<int, int>> comp11(poly11);
	while (!comp11.empty()) {
		it11 = comp11.begin();
		for (it = poly22.begin(); it != poly22.end(); it++) {
			if (it11->first == it->first && it11->second == it->second) {
				poly22.erase(it);
				comp11.erase(it11);
				break;
			}
			else {
				comp.clear();	comp.resize(0); poly22.clear(); poly22.resize(0);
				return false;
			}
		}
	}
	if (comp11.empty()) return true;
}

bool check_0() {
	for (j = 0; j < cnt; j++) {
		comp.push_back(make_pair(poly2[j].first, poly2[j].second));
	}
	check_poly2();
	if (compare_poly() == true) return true;
	else 
		return false;	
}

bool check_90() {
	for (j = 0; j < cnt; j++) {
		comp.push_back(make_pair(poly2[j].second, (-1) * poly2[j].first));
	}
	check_poly2();
	if (compare_poly() == true) return true;
	else return false;
}

bool check_180() {
	for (j = 0; j < cnt; j++) {
		comp.push_back(make_pair((-1) * poly2[j].first, (-1) * poly2[j].second));
	}
	check_poly2();
	if (compare_poly() == true) return true;
	else return false;
}

bool check_270() {
	for (j = 0; j < cnt; j++) {
		comp.push_back(make_pair((-1) * poly2[j].second, poly2[j].first));
	}
	check_poly2();
	if (compare_poly() == true) return true;
	else return false;
}

int main() {
	ifstream input("polygon.inp");
	ofstream output("polygon.out");

	input >> n;
	for (i = 0; i < n; i++) {
		poly1.clear(); poly1.resize(0);	poly2.clear(); poly2.resize(0);	comp.clear(); comp.resize(0);
		poly11.clear(); poly11.resize(0);	poly22.clear(); poly22.resize(0);
		input >> cnt;
		flag = 1, x = 0, y = 0, tag = 1;
		for (j = 0; j < cnt; j++) {
			input >> num;
			check_point();
		}
		flag = 1, x = 0, y = 0, tag = 2;
		for (j = 0; j < cnt; j++) {
			input >> num;
			check_point();
		}
		check_poly1();
		if (check_0() == true) {
			output << "1" << endl;
			continue;
		}
		if (check_90() == true) {
			output << "1" << endl;
			continue;
		}
		if (check_180() == true) {
			output << "1" << endl;
			continue;
		}
		if (check_270() == true) {
			output << "1" << endl;
			continue;
		}
		output << "0" << endl;
	}

	input.close();
	output.close();
	return 0;
}