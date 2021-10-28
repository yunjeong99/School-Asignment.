#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

ifstream input("card.inp");
ofstream output("card.out");
int card[1100]; int card2[3][1100];
int n, num1, cnt, result;

void reset() {
	for (int k = 0; k < cnt; k++)
	{
		input >> num1;
		card[k] = num1;
	}

	for (int k = 0; k < 3; k++)
	{
		card2[k][0] = card[0];
		card2[k][1] = card[1];
		card2[k][2] = card[2];
	}

	card2[2][3] = card[3] + card[0];
	card2[1][3] = card[3] + card[0];
	card2[0][3] = card[3] + card[1];
}

int func(int flag, int data) {
	for (int j = 4; j < cnt; j++)
	{
		if (card2[1][j - 2] > card2[2][j - 2])
		{
			card2[0][j] = card[j] + card2[1][j - 2];
		}
		else
		{
			card2[0][j] = card[j] + card2[2][j - 2];
		}

		if (card2[1][j - 3] > card2[2][j - 3])
		{
			flag = card2[1][j - 3];
		}
		else
		{
			flag = card2[2][j - 3];
		}
		if (card2[0][j - 3] > flag)
		{
			card2[1][j] = card2[0][j - 3] + card[j];
		}
		else
		{
			card2[1][j] = card[j] + flag;
		}

		if (card2[1][j - 4] > card2[2][j - 4])
		{
			flag = card2[1][j - 4];
		}
		else
		{
			flag = card2[2][j - 4];
		}
		if (card2[0][j - 4] > flag)
		{
			card2[2][j] = card[j] + card2[0][j - 4];
		}
		else card2[2][j] = card[j] + flag;
	}

	if (card2[0][cnt - 1] > card2[1][cnt - 1])
	{
		flag = card2[0][cnt - 1];
	}
	else flag = card2[1][cnt - 1];

	if (flag > card2[2][cnt - 1])
	{
		data = flag;
	}
	else data = card2[2][cnt - 1];
	return data;
}

int main()
{

	input >> n;
	for (int i = 0; i < n; i++)
	{
		input >> cnt;
		reset();

		int flag = 0, data = 0;
		result=func(flag, data);
		output << result << endl;
	}
}