#include<iostream>
using namespace std;

int T;
int dp[12];

void filldp() {
	for (int i = 0; i < 12; i++) {
		if (i - 1 >= 0) {
			dp[i] += dp[i - 1];
		}
		if (i - 2 >= 0) {
			dp[i] += dp[i - 2];
		}
		if (i - 3 >= 0) {
			dp[i] += dp[i - 3];
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	int n;
	dp[0] = 1;
	filldp();
	while (T--) {
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}