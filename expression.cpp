#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#pragma warning (disable:4996)

vector<int> num;
vector<int> ::iterator it_num;
vector<pair<int, string>> op;
vector<pair<int, string>> ::iterator it_op;

bool calc() {
	int num1, num2, sum = 0;

	// num에서 숫자 2개 꺼내기
	it_num = num.end()-1;
	num2 = *it_num;
	num.erase(it_num);
	it_num = num.end()-1;
	num1 = *it_num;
	num.erase(it_num);

	//연산부호
	it_op = op.end()-1;
	//string o = it_op->second;
	if (it_op->first == 2) { 
		if (it_op->second == "*") 		sum = num1 * num2;
		else if (it_op->second == "/") {
			if (num2 == 0) 	return false;
			else	sum = num1 / num2;
		}
		else if (it_op->second == "%") {
			if (num2 == 0) return false;
			else sum = num1 % num2;
		}
	}
	else { //it_op->first ==1
		if (it_op->second == "+")	sum = num1 + num2;
		else if (it_op->second == "-") sum = num1 - num2;
	}

	op.erase(it_op); //pop
	num.push_back(sum);

	return true;
}

int main() {
	ifstream input("expression.inp");
	ofstream output("expression.out");

	int n, i, result, prior;
	bool check_error;
	string s;

	input >> n;
	for (i = 0; i < n; i++) {
		while (true) {
			input >> s;
			if (s == "=") {
				while (!op.empty()) {
					check_error = calc();
					if (check_error == false) {
						output << "Error!" << endl;
						goto EXIT;
					}
				}
				break;
			}
			else if (s == "*" || s == "/" || s == "%") 	prior = 2;
			else if (s == "+" || s == "-") 	prior = 1;
			else {
				num.push_back(stoi(s)); //정수
				continue;
			}
			while (!op.empty() && prior <= (op.end()-1)->first) {
				//if (num.size() == 1) break; //첫번째는 건너띄기
				check_error = calc();
				if (check_error == false) {
					output << "Error!" << endl;
					getline(input, s);
					goto EXIT;
				}
			}
			op.push_back(make_pair(prior, s));
		 } 
		it_num = num.begin();
		result = *it_num;
		output << result << endl;
	EXIT:
		num.clear();
		num.resize(0);
		op.clear();
		op.resize(0);
	}
	input.close();
	output.close();
	return 0;
}