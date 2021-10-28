#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

string s;
char temp_f, temp_b, temp;
int life, flag, sum, cnt;

bool func() {
	while (true) {
		int it_front = 0, it_back = s.length() - 1;

		if (it_front == it_back || it_front > it_back)
			break;

		if (s[it_front] == s[it_back]) { //문자 같음
			s.erase(it_front, 1);
			s.erase(it_back - 1, 1);
		}
		else { //문자 다름

			if (s[it_front+1] == s[it_back]) {
				if (s[it_back - 1] == s[it_front]) {
					if (s[it_front] == s[it_back - 1] && s[it_front + 1] == s[it_back - 2]) {
						s.erase(it_back, 1);
						life--;
					}
					else if (s[it_back] == s[it_front + 1] && s[it_back - 1] == s[it_front + 2]) {
						s.erase(it_front, 1);
						life--;
					}
					else {
						s.erase(it_back, 1);
						s.erase(it_back - 1, 1);
						s.erase(it_front, 2);
						life -= 2;
					}
				}
				else if (s[it_front] == s[it_back - 2]) {
					if (s[it_front] == s[it_back - 2]) {
						if (s[it_front + 1] == s[it_back]) {
							s.erase(it_front, 1);
							life--;
						}
						else {
							s.erase(it_back, 1);
							s.erase(it_back - 1, 1);
							life -= 2;
						}
					}
					else if (s[it_front + 1] == s[it_back]) {
						s.erase(it_front, 1);
						life--;
					}
					else {
						s.erase(it_back, 1);
						s.erase(it_back - 1, 1);
						life -= 2;
					}
				}
				else if (s[it_front + 1] == s[it_back]) {
					s.erase(it_front, 1);
					life--;
				}
				else {
					s.erase(it_front, 1);
					life--;
				}
			}

			else if (s[it_back - 1] == s[it_front]) {
				s.erase(it_back, 1);
				life--;
			}

			else if (s[it_front + 1] == s[it_back - 1]) {
				s.erase(it_front, 1);
				s.erase(it_back-1, 1);
				life -= 2;
			}
			else if (s[it_front] == s[it_back - 2]) {
				s.erase(it_back, 1);
				s.erase(it_back - 1, 1);
				life -= 2;
			}
			else if (s[it_front + 2] == s[it_back]) {
				s.erase(it_front, 2);
				life -= 2;
			}
			else {
				life -= 3;
				break;
			}
		}
	}
	if (life < 0) return false;
	else {
		cnt=2 - life;
		return true;
	}
}

int main() {
	ifstream input("palindrome.inp");
	ofstream output("palindrome.out");

	int n;
	input >> n;

	for (int count = 0; count < n; count++) {
		input >> s;
		cnt = 0, life = 2;
		if (func() == false)
			output << "-1" << endl;
		else if (cnt == 0)
			output << "0" << endl;
		else
			output << cnt << endl;

	}
	input.close();
	output.close();
	return 0;
}