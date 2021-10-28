#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int n, m, i, j, k;
int num, process_num, temp, cnt; //num은 input파일에서 읽어올 변수
string command;

char com_1[] = "request";
char com_2[] = "release";
vector<int> available;
vector<int> res_command; //자원 요청,반환 명령어
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
	vector<int> av_print(available); //복구를 위한 복제 av벡터
//	vector<int> alloc_print(arr[process_num].alloc);
	//vector<int> need_print(arr[process_num].need);
	cnt = 0;
	for (i = 0; i < m; i++) {
		temp = available[i] - res_command[i];
		if (temp < 0) { //음수가 되면 명령 실행 못하는 것이므로
			for (j = 0; j < i; j++) //av값을 다시 원상복구 
				available[j] = av_print[j];
			wait.push({ process_num, res_command }); //대기큐 push
			return;
		}
		else { //음수가 아니면 av에서 요청값 빼줌
			available[i] = temp;
		}
	}

	for (i = 0; i < n; i++) { //다른 프로세스의 자원 need를 충족시킬 수 있는지 확인
		if (i == process_num)	continue;
		for (j = 0; j < m; j++) {
			temp = available[j] - arr[i].need[j];
			if (temp < 0) {
				cnt++;
				break;
			}
		}
	}
	if (cnt == (n - 1)) { //다른 프로세스의 자원 need를 모두 충족할 수 없을 때
		wait.push({ process_num, res_command }); //대기큐 push
		for (i = 0; i < m; i++) { //av값 원상복구
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
		printf("대기큐 pnum: %d!\n", process_num);
		return true;
	}
}

int main() {
	ifstream input("banker.inp");
	FILE* output = fopen("banker.out", "wt");
	input >> n;
	input >> m;
	
	
	for (i = 0; i < m; i++) { // available 값 할당
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
	alloc_sum.assign(m, 0); // 0으로 m개의 원소 할당
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
		printf("프로세스 %d번\n ", i);
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
			
			printf("프로세스 번호 : %d\n", process_num);
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
		
		printf("프로세스 번호 : %d\n", process_num);
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
