#include<bits/stdc++.h>
using namespace std;

int tmpsum[1025][1025];
int dp[1025][1025];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tmpsum[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]+tmpsum[i][j];
		}
	}
	int x1, x2, y1, y2;
	while (m--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2]+dp[x1-1][y1-1] << "\n";
	}
	return 0;
}