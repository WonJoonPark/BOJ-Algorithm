#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct opera {
	int num;
	int p, mi, mu, d; //각자가 연산자 수를 가지고 있어야 한다 (하나씩만 쓸거니까 완탐)
};

vector<int> inputnumarr;// 피연산자를 저장해 놓을 배열
queue<opera> operationresultarr; //연산자를 가지고 있고 bfs에 사용할 큐
vector<opera> resultarr; // 정렬하여 출력할 결과배열
int n;
int pluss, minuss, multi, divi;

void bfs() {
	opera tmpqueue; //임시큐
	int index = 1;
	int queuesize = 0;
	while (1) {
		if (operationresultarr.empty()) { break; }
		queuesize = operationresultarr.size();
		for (int i = 0; i <queuesize; i++) {
			tmpqueue = operationresultarr.front();
			operationresultarr.pop();
			if (tmpqueue.p != 0) {
				opera tmp1 = tmpqueue;
				tmp1.p--; //연산자를 하나씩 만을 사용하여 계산 하고 그 구조체들이 각자 그 연산자수를 카운트
				tmp1.num += inputnumarr[index];
				if (tmp1.p == 0 && tmp1.mi == 0 && tmp1.mu == 0 && tmp1.d == 0) {
					resultarr.push_back(tmp1);}
				else operationresultarr.push(tmp1);
			}
			if (tmpqueue.mi != 0) {
				opera tmp1 = tmpqueue;
				tmp1.mi--;//연산자를 하나씩 만을 사용하여 계산 하고 그 구조체들이 각자 그 연산자수를 카운트
				tmp1.num -= inputnumarr[index];
				if (tmp1.p == 0 && tmp1.mi == 0 && tmp1.mu == 0 && tmp1.d == 0) {
					resultarr.push_back(tmp1);}
				else operationresultarr.push(tmp1);
			}
			if (tmpqueue.mu != 0) {
				opera tmp1 = tmpqueue;
				tmp1.mu--;//연산자를 하나씩 만을 사용하여 계산 하고 그 구조체들이 각자 그 연산자수를 카운트
				tmp1.num *= inputnumarr[index];
				if (tmp1.p == 0 && tmp1.mi == 0 && tmp1.mu == 0 && tmp1.d == 0) {
					resultarr.push_back(tmp1);}
				else operationresultarr.push(tmp1);
			}
			if (tmpqueue.d != 0) {
				opera tmp1 = tmpqueue;
				tmp1.d--;//연산자를 하나씩 만을 사용하여 계산 하고 그 구조체들이 각자 그 연산자수를 카운트
				tmp1.num /= inputnumarr[index];
				if (tmp1.p == 0 && tmp1.mi == 0 && tmp1.mu == 0 && tmp1.d == 0) {
					resultarr.push_back(tmp1);
				}
				else operationresultarr.push(tmp1);
			}}
		index++;
	}}
bool cmp(opera a, opera b) {
	if (a.num > b.num) { return true; }
	else return false;
}
void resultmaxminget() {
	sort(resultarr.begin(), resultarr.end(),cmp);
	cout << resultarr[0].num << ' ' << resultarr[resultarr.size() - 1].num << '\n';
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	int tmp;
	opera tmpo;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		inputnumarr.push_back(tmp);
		if (i == 0) { tmpo.num = tmp; }
	}
	cin >> tmpo.p >> tmpo.mi >> tmpo.mu >> tmpo.d;
	operationresultarr.push(tmpo);
	bfs();
	resultmaxminget();
	return 0;
}