#include<bits/stdc++.h>
using namespace std;

int dp[501][501]; //i장부터 j장까지 더하는데 드는 최소비용
int costsum[501];

int t, n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> tmpv(n+1);
		for (int i = 1; i <= n; i++) {
			cin >> tmpv[i];
			costsum[i] = costsum[i - 1] + tmpv[i]; // 누적 코스트 배열
		}

		for (int i = 1; i <= n; i++) {
			for (int s = 1; s + i <= n+1; s++) {
				dp[s][s + i] = 1e9;
				for (int m = s; m <= s + i; m++) {
					dp[s][s + i] = min(dp[s][s + i], dp[s][m] + dp[m + 1][s + i] + costsum[s + i] - costsum[s - 1]);
				}
			}
		}

		cout << dp[1][n] << "\n";
	}


	return 0;
}