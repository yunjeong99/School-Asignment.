#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int n, m, i, j, k;
int num, process_num, temp, cnt; //num�� input���Ͽ��� �о�� ����
string command;

char com_1[] = "request";
char com_2[] = "release";
vector<int> available;
vector<int> res_command; //�ڿ� ��û,��ȯ ��ɾ�
vector <int> alloc_sum;

struct Wait {
	int wait_pnum;
	vector <int> wait_command;
};
queue <Wait> wait;

struct Process {
	vector<int> max;
	vector<int> alloc;
	vector<int> need;
};
Process arr[50];

void request() {
	vector<int> av_print(available); //������ ���� ���� av����
//	vector<int> alloc_print(arr[process_num].alloc);
	//vector<int> need_print(arr[process_num].need);
	cnt = 0;
	for (i = 0; i < m; i++) {
		temp = available[i] - res_command[i];
		if (temp < 0) { //������ �Ǹ� ��� ���� ���ϴ� ���̹Ƿ�
			for (j = 0; j < i; j++) //av���� �ٽ� ���󺹱� 
				available[j] = av_print[j];
			wait.push({ process_num, res_command }); //���ť push
			return;
		}
		else { //������ �ƴϸ� av���� ��û�� ����
			available[i] = temp;
		}
	}

	for (i = 0; i < n; i++) { //�ٸ� ���μ����� �ڿ� need�� ������ų �� �ִ��� Ȯ��
		if (i == process_num)	continue;
		for (j = 0; j < m; j++) {
			temp = available[j] - arr[i].need[j];
			if (temp < 0) {
				cnt++;
				break;
			}
		}
	}
	if (cnt == (n - 1)) { //�ٸ� ���μ����� �ڿ� need�� ��� ������ �� ���� ��
		wait.push({ process_num, res_command }); //���ť push
		for (i = 0; i < m; i++) { //av�� ���󺹱�
			available[i] = av_print[i];
			//arr[process_num].alloc[i] = alloc_print[i];
			//arr[process_num].need[i]=need_print[i];
		}
		return;
	}

	for (i = 0; i < m; i++) {
		arr[process_num].need[i] -= res_command[i]; //need-res_command
		arr[process_num].alloc[i] += res_command[i]; //alloc+res_command
	}
}

void release() {
	for (i = 0; i < m; i++) {
		available[i] += res_command[i];
		arr[process_num].alloc[i] -= res_command[i];
		arr[process_num].need[i] += res_command[i];
	}
}

bool check_wait() {
	if (wait.empty())		return false;
	else {
		process_num = wait.front().wait_pnum;
		res_command = wait.front().wait_command;
		wait.pop();
		printf("���ť pnum: %d!\n", process_num);
		return true;
	}
}

int main() {
	ifstream input("banker.inp");
	FILE* output = fopen("banker.out", "wt");
	input >> n;
	input >> m;
	
	
	for (i = 0; i < m; i++) { // available �� �Ҵ�
		input >> num;
		available.push_back(num);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			input >> num;
			arr[i].max.push_back(num);
		}
	}
	for (i = 0; i < n; i++) { // input_alloc
		for (j = 0; j < m; j++) {
			input >> num;
			arr[i].alloc.push_back(num);
		}
	}
	alloc_sum.assign(m, 0); // 0���� m���� ���� �Ҵ�
	for (i = 0; i < n; i++) { //calc_alloc
		for (j = 0; j < m; j++) {
			alloc_sum[j] += arr[i].alloc[j];
		}
	}
	for (i = 0; i < available.size(); i++) { //calc_av
		available[i] -= alloc_sum[i];
	}
	for (i = 0; i < n; i++) { //calc_need
		for (j = 0; j < m; j++) {
			int temp = arr[i].max[j] - arr[i].alloc[j];
			arr[i].need.push_back(temp);
		}
	}

	
	for (i = 0; i < n; i++) {
		printf("���μ��� %d��\n ", i);
		for (j = 0; j < m; j++) {
			printf("%d ", arr[i].need[j]);
		}
		printf("\n==============\n");
	}

	while (true) {
		char ch, compare = '\n';
		input >> command;
		input >> process_num;
		for (int k = 0; k < m; k++) {
			input >> num;
			res_command.push_back(num);
		}
		
		if (command.compare(com_1)==0)		request();
		else if (command.compare(com_2) == 0) { //release
			release();
			
			printf("���μ��� ��ȣ : %d\n", process_num);
			printf("ALLOC => ");
			for (i = 0; i < m; i++)
				printf("%d ", arr[process_num].alloc[i]);
			printf("\nNEED => ");
			for (i = 0; i < m; i++)
				printf("%d ", arr[process_num].need[i]);
			printf("\n\n");			
		}
		else	break;


		int ws = wait.size();
		for (k = 0; k < ws; k++) {
			if (check_wait() == true)
				request();
		}
		
		printf("���μ��� ��ȣ : %d\n", process_num);
		printf("ALLOC => ");
		for (i = 0; i < m; i++)
			printf("%d ", arr[process_num].alloc[i]);
		printf("\nNEED => ");
		for (i = 0; i < m; i++)
			printf("%d ", arr[process_num].need[i]);
		printf("\n\n");
		

		for (i = 0; i < available.size(); i++) {
			fprintf(output, "%d ", available[i]);
		}
		fprintf(output, "\n");
		res_command.resize(0);
	}
	input.close();
	fclose(output);
	return 0;
}
