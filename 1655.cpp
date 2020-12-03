#include<iostream>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N;
int centervalue;

priority_queue<int, vector<int>> pqless;
priority_queue<int, vector<int>, greater<int>> pqgreater;

void InputToQueue(int num) {
	if (num <= centervalue) { pqless.push(num); }
	else { pqgreater.push(num); }
}
void ModifyQueue() {
	if (pqless.size() > pqgreater.size() + 1) { //2이상 차이날 경우
		int modinum = pqless.top();
		pqless.pop();
		pqgreater.push(modinum);
	}
	else if (pqgreater.size() > pqless.size() + 1) { //2이상 차이날 경우
		int modinum = pqgreater.top();
		pqgreater.pop();
		pqless.push(modinum);
	}
}
void GetCenterValue() {
	if (pqless.size() >= pqgreater.size()) {
		centervalue = pqless.top();
	}
	else {
		centervalue = pqgreater.top();
	}
	cout << centervalue << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (i == 0) {
			pqless.push(tmp); centervalue = tmp; cout << centervalue << "\n"; continue;
		}
		InputToQueue(tmp);
		ModifyQueue();
		GetCenterValue();
	}
	return 0;
}