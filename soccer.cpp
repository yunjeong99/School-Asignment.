#include <stdio.h>
#pragma warning (disable:4996)

struct Team {
	int score = 0; //����
	int ds = 0; //���
	int away = 0; //����� ����
};

int rank[100];

int main() {
	FILE* input = fopen("soccer.inp", "rt");
	FILE* output = fopen("soccer.out", "wt");
	int T, n, k, X, Y, a, b;

	fscanf(input, "%d", &T);
	for (int i = 0; i < T; i++) {
		fprintf(output, "Test Case #%d:", i + 1);
		fscanf(input, "%d %d", &n, &k);
		struct Team t[100];
		rank[100] = { 0, };

		for (int j = 1; j <= n; j++) {  // rank�迭 4�� �ʱ�ȭ, score, away �ʱ�ȭ
			rank[j] = n;
		}
		for (int j = 0; j < ((n / 2) * k * 2 * (n - 1)); j++) {
			fscanf(input, "%d-%d %d %d", &X, &Y, &a, &b);
			if (a > b) // X�� �̰��� ��
				t[X].score = t[X].score + 3;
			else if (a < b) // Y�� �̰�����
				t[Y].score = t[Y].score + 3;
			else { // ����� ��
				t[X].score = t[X].score + 1;
				t[Y].score = t[Y].score + 1;
			}
			t[X].ds = t[X].ds + (a - b); // X ���
			t[Y].ds = t[Y].ds + (b - a); // Y ���
			t[X].away = t[X].away + a; // ����� ���
		}
		for (int j = 1; j < n; j++) { //rank ���
			for (int u = j + 1; u <= n; u++) {
				if (t[j].score > t[u].score)
					rank[j] -= 1;
				else if (t[j].score < t[u].score)
					rank[u] -= 1;
				else { //����2�� ���
					if (t[j].ds > t[u].ds)
						rank[j] -= 1;
					else if (t[j].ds < t[u].ds)
						rank[u] -= 1;
					else { //����3�� away
						if (t[j].away > t[u].away)
							rank[j] -= 1;
						else if (t[j].away < t[u].away)
							rank[u] -= 1;
						else {
							rank[j] -= 1;
							rank[u] -= 1;
						}
					}
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			fprintf(output, " %d", rank[j]);
		}
		fprintf(output, "\n");
	}
	fclose(input);
	fclose(output);
	return 0;
}