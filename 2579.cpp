#include<iostream>
#include<vector>
using namespace std;

int stairs;
vector<int> stairvalue;
int dp[301];
int max(int x, int y) {
	return x > y ? x : y;
}
void fillstairvalue() {
	int tmp;
	stairvalue.push_back(0); //시작(바닥)
	for (int i = 0; i < stairs; i++) {
		cin >> tmp;
		stairvalue.push_back(tmp);
	}
}
void filldp() {
	dp[0] = 0;
	dp[1] = stairvalue[1];
	dp[2] = stairvalue[1] + stairvalue[2]; //한칸 한칸이 무조건 처음 두칸보다는 큼
	for (int i = 3; i <= stairs; i++) {
		dp[i] = max(dp[i - 2] + stairvalue[i], dp[i - 3] + stairvalue[i - 1] + stairvalue[i]);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> stairs;
	fillstairvalue();
	filldp();
	cout << dp[stairs] << '\n';
	return 0;
}