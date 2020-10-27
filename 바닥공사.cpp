#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long dp[1001];

int main() {
	int N;
	cin >> N;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 796796;
	}
	for (int i = 1; i <= N; i++) {
		cout << dp[i] % 796796 << endl;
	}
	cout << dp[N];

	return 0;
}