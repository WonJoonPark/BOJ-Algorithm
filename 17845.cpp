#include<bits/stdc++.h>
using namespace std;

int dp[1001][10001]; // [과목수]

int n, k, l, t;
//한 과목을 무제한으로 할수 있는 것이 아니다.


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	//memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= k; i++) {
		cin >> l >> t;
		for (int j = 0; j <= n; j++) {
			if (j - t >= 0) {
				dp[i][j] = max(dp[i - 1][j], l + dp[i - 1][j - t]);
			}
			else { dp[i][j] = dp[i - 1][j]; }
		}
	}
	/*for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << dp[k][n] << "\n";

	return 0;
}