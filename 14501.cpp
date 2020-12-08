#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dp[16];
int N;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	vector < pair<int, int>> sangdam(N);
	int Ti, Pi;
	int maxresult = 0;
	for (int i = 1; i <= N; i++) {
		cin >> Ti >> Pi;
		for (int j = 0; j <= i; j++) {
			if (dp[j] > maxresult) maxresult = dp[j];
		}
		dp[i + Ti] = max(dp[i + Ti], maxresult + Pi);
		maxresult = 0;
	}
	
	for (int i = 0; i <= N + 1; i++) {
		if (maxresult < dp[i]) { maxresult = dp[i]; }
	}
	cout << maxresult << "\n";
	return 0;
}