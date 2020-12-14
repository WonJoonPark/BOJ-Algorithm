#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int N,M;
int remote[10]; //0~9
int casestore[1000001];
int len;

bool onlynum(int num) {
	len = 0;
	int tmp = num;
	while (1) {
		if (remote[tmp % 10] == true) return false; //고장나서 버튼만으로는 이동불가
		tmp /= 10;
		len++;
		if (tmp == 0) break;
	}
	return true;
}
void inputs() {
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		remote[tmp] = true; //true는 고장
	}
}
void makecase() {
	casestore[100] = 0;
	for (int i = 0; i < 1000001; i++) {
		if (i == 100) continue;
		if(onlynum(i)==true)
		{
			casestore[i] = min(abs(i - 100), len);
		}
	}
}
void setcase() {
	for (int i = 0; i < 1000001; i++) {
		casestore[i] = -1;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	setcase();
	makecase();

	if (N == 100) { cout << 0 << "\n"; return 0; }
	if(casestore[N]!=-1){
		cout << casestore[N] << "\n"; return 0;
	}
	else{
		int index = 1;
		while (1) {
			if (N - index >= 0) {
				if (casestore[N - index] != -1) {
					cout << min(abs(N - 100),casestore[N - index] + index) << "\n";
					return 0;
				}
			}
			if (N + index <= 1000000) {
				if (casestore[N + index] != -1) {
					cout << min(abs(N - 100),casestore[N + index] + index) << "\n";
					return 0;
				}
			}
			index++;
		}
	}
	return 0;
}