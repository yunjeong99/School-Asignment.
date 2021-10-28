#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#pragma warning(disable:4996);
using namespace std;

string s1, s2, str, str2;
string s1_1, s1_2, s1_3, s1_4, s1_5, s1_6;
string s2_1, s2_2, s2_3, s2_4, s2_5, s2_6;

vector<int> list;
vector<int> ::iterator it;

void s_clear() {
	s1.clear();	s2.clear();	
	s1_1.clear();	s1_2.clear();	s1_3.clear();	s1_4.clear();	s1_5.clear();	s1_6.clear();
	s2_1.clear();	s2_2.clear();	s2_3.clear();	s2_4.clear();	s2_5.clear();	s2_6.clear();
	str.clear();	str2.clear();
}

void substr_s1() {
	s1_1.append(s1, 0, 1);	s1_1.append(s1, 5, 1);
	str = s1.substr(1, 4);
	//s1_2.append(s1, 1, 1);	s1_2.append(s1, 4, 1);
	//s1_3.append(s1, 2, 1);	s1_3.append(s1, 3, 1);
	//s1_4.append(s1, 3, 1);	s1_4.append(s1, 2, 1);
	//s1_5.append(s1, 4, 1);	s1_5.append(s1, 1, 1);
	//s1_6.append(s1, 5, 1);	s1_6.append(s1, 0, 1);
}

void substr_s2() {
	s2_1.append(s2, 0, 1);	s2_1.append(s2, 5, 1);
	s2_2.append(s2, 1, 1);	s2_2.append(s2, 4, 1);
	s2_3.append(s2, 2, 1);	s2_3.append(s2, 3, 1);
	s2_4.append(s2, 3, 1);	s2_4.append(s2, 2, 1);
	s2_5.append(s2, 4, 1);	s2_5.append(s2, 1, 1);
	s2_6.append(s2, 5, 1);	s2_6.append(s2, 0, 1);
}

bool color_check() {
	int s1_r = 0, s1_g = 0, s1_b = 0;
	int s2_r = 0, s2_g = 0, s2_b = 0;
	for (int k = 0; k < s1.length(); k++) {
		switch (s1[k]) {
		case 'r':
			s1_r++;
			break;
		case 'g':
			s1_g++;
			break;
		case 'b':
			s1_b++;
			break;
		}
	}
	for (int k = 0; k < s2.length(); k++) {
		switch (s2[k]) {
		case 'r':
			s2_r++;
			break;
		case 'g':
			s2_g++;
			break;
		case 'b':
			s2_b++;
			break;
		}
	}
	if (s1_r != s2_r)	return false;
	if (s1_g != s2_g)	return false;
	if (s1_b != s2_b)	return false;
	return true;
}

bool func1() { 
	str2 = s2.substr(1, 4);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 2, 1);	str2.append(s2, 4, 1);	str2.append(s2, 1, 1);	str2.append(s2, 3, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 3, 1);	str2.append(s2, 1, 1);	str2.append(s2, 4, 1);	str2.append(s2, 2, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 4, 1);	str2.append(s2, 3, 1);	str2.append(s2, 2, 1);	str2.append(s2, 1, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	return false;
}

bool func2() {
	str2.append(s2, 0, 1);	str2.append(s2, 3, 1);	str2.append(s2, 2, 1);	str2.append(s2, 5, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 2, 1);	str2.append(s2, 0, 1);	str2.append(s2, 5, 1);	str2.append(s2, 3, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 3, 1);	str2.append(s2, 5, 1);	str2.append(s2, 0, 1);	str2.append(s2, 2, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 5, 1);	str2.append(s2, 2, 1);	str2.append(s2, 3, 1);	str2.append(s2, 0, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	return false;
}

bool func3() {
	str2.append(s2, 0, 1);	str2.append(s2, 1, 1);	str2.append(s2, 4, 1);	str2.append(s2, 5, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 1, 1);	str2.append(s2, 5, 1);	str2.append(s2, 0, 1);	str2.append(s2, 4, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 4, 1); str2.append(s2, 0, 1);	str2.append(s2, 5, 1);	str2.append(s2, 1, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 5, 1);	str2.append(s2, 4, 1);	str2.append(s2, 1, 1);	str2.append(s2, 0, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	return false;
}

bool func4() {
	str2.append(s2, 0, 1);	str2.append(s2, 4, 1);	str2.append(s2, 1, 1);	str2.append(s2, 5, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 1, 1);	str2.append(s2, 0, 1);	str2.append(s2, 5, 1);	str2.append(s2, 4, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 4, 1);	str2.append(s2, 5, 1);	str2.append(s2, 0, 1);	str2.append(s2, 1, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 5, 1);	str2.append(s2, 1, 1);	str2.append(s2, 4, 1);	str2.append(s2, 0, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	return false;
}

bool func5() {
	str2.append(s2, 0, 1);	str2.append(s2, 2, 1);	str2.append(s2, 3, 1);	str2.append(s2, 5, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 2, 1);	str2.append(s2, 5, 1);	str2.append(s2, 0, 1);	str2.append(s2, 3, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 3, 1);	str2.append(s2, 0, 1);	str2.append(s2, 5, 1);	str2.append(s2, 2, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 5, 1);	str2.append(s2, 3, 1);	str2.append(s2, 2, 1);	str2.append(s2, 0, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	return false;
}

bool func6() {
	str2.append(s2, 1, 1);	str2.append(s2, 3, 1);	str2.append(s2, 2, 1);	str2.append(s2, 4, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 2, 1);	str2.append(s2, 1, 1);	str2.append(s2, 4, 1);	str2.append(s2, 3, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 3, 1);	str2.append(s2, 4, 1);	str2.append(s2, 1, 1);	str2.append(s2, 2, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	str2.append(s2, 4, 1);	str2.append(s2, 2, 1);	str2.append(s2, 3, 1);	str2.append(s2, 1, 1);
	if (str.compare(str2) == 0) return true;
	str2.clear();
	return false;
}

bool func() {
	if (s1_1.compare(s2_1)==0)	list.push_back(1);
	if (s1_1.compare(s2_2)==0)	list.push_back(2);
	if (s1_1.compare(s2_3)==0)	list.push_back(3);
	if (s1_1.compare(s2_4)==0)	list.push_back(4);
	if (s1_1.compare(s2_5)==0)	list.push_back(5);
	if (s1_1.compare(s2_6)==0)	list.push_back(6);

	while (! list.empty()) {
		it = list.begin();
		str2.clear();
		if (*it == 1) {
			if (func1() == true) 	return true;
		}
		else if (*it == 2) {
			if (func2() == true)	return true;
		}
		else if (*it == 3) {
			if (func3() == true)	return true;
		}
		else if (*it == 4) {
			if (func4() == true)	return true;
		}
		else if (*it == 5) {
			if (func5() == true) return true;
		}
		else if (*it == 6) {
			if (func6() == true)	return true;
		}
		list.erase(it);
	}
	return false;
}

int main() {
	ifstream input("cube.inp");
	ofstream output("cube.out");
	string s;

	while (!input.eof()) {
		input >> s;
		if (s == "") break;
		s1 = s.substr(0, 6);
		s2 = s.substr(6, 6);
		if (color_check() == false) {
			output << "FALSE" << endl;
			continue;
		}

		substr_s1();
		substr_s2();

		if (func() == true) {
			output << "TRUE" << endl;
		}
		else {
			output << "FALSE" << endl;
		}
		s_clear();
		s.clear();
		list.clear();
		list.resize(0);
	}
	input.close();
	output.close();
	return 0;
}