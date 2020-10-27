#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string plans;
int n;

int main() {
	int x = 1; int y = 1;
	cin >> n;
	cin.ignore(); // 버퍼 비우기 
	getline(cin, plans);
	// 이동 계획을 하나씩 확인
	for (int i = 0; i < plans.size(); i++) {
		if (plans[i] == ' ') continue;
		if (plans[i] == 'R') {
			if (y + 1 == n + 1) continue;
			else y += 1;
		}
		else if (plans[i] == 'L') {
			if (y - 1 == 0) continue;
			else y += 1;

		}
		else if (plans[i] == 'U') {
			if (x - 1 == 0) continue;
			else x += 1;

		}
		else if (plans[i] == 'D') {
			if (x + 1 == n + 1) continue;
			else x += 1;
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}