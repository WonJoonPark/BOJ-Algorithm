#include<bits/stdc++.h>
using namespace std;

int mars[1002][1002];
int dp[1002][1002];
int tmp[2][1002];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> mars[i][j];
		}
	}

	for (int j = 1; j <= M; j++) { //첫째 행은 다른 경우의 수 가 없다.
		dp[1][j] += dp[1][j - 1] + mars[1][j];
	}

	for (int i = 2; i <= N; i++) {
		tmp[0][0] = dp[i - 1][1];
		for (int j = 1; j <= M; j++) {
			tmp[0][j] = max(dp[i - 1][j], tmp[0][j - 1]) + mars[i][j];
		}

		tmp[1][M + 1] = dp[i - 1][M];
		for (int j = M; j > 0; j--) {
			tmp[1][j] = max(dp[i - 1][j], tmp[1][j + 1]) + mars[i][j];
		}

		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(tmp[0][j], tmp[1][j]);
		}
	}

	cout << dp[N][M];
	return 0;
}