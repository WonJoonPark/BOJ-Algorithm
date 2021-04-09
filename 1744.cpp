#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> minusnum;
priority_queue<int, vector<int>, greater<int>> plusnum;
int tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int resultsum = 0;
	int zeronum = 0;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 1) { // 1은 더하는게 나음
			resultsum++;
		}
		else if (tmp == 0) zeronum++;
		else if(tmp>0){ //양수
			plusnum.push(tmp);
		}
		else  {
			minusnum.push(tmp);
		}
	}
	if (plusnum.size() % 2 == 1) { plusnum.push(1); } // 양수가 홀수개면 1을 넣어줌 (그냥 더하는 효과)

	if (minusnum.size() % 2 == 1) {
		if (zeronum == 0) minusnum.push(1); //0이 있으면 0을 곱해주는게 나음
		else minusnum.push(0);
	}
	while (1) {
		if (plusnum.empty()) break;
		int f = plusnum.top(); plusnum.pop();
		int s = plusnum.top(); plusnum.pop();
		resultsum += (f * s);
	}
	while (1) {
		if (minusnum.empty()) break;
		int f = minusnum.top(); minusnum.pop();
		int s = minusnum.top(); minusnum.pop();
		resultsum += (f * s);
	}
	cout << resultsum << "\n";
	return 0;
}