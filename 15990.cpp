#include<bits/stdc++.h>
using namespace std;

const int modenum = 1000000009;

int T, n;
long long dp[100001][4]; // 1,2,3의 합으로 나타내는 방법의 수 (열은 마지막 더한 수)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	dp[1][1] = 1; dp[2][1] = 0; dp[3][1] = 1; //초기화 
	dp[1][2] = 0; dp[2][2] = 1; dp[3][2] = 1;
	dp[1][3] = 0; dp[2][3] = 0; dp[3][3] = 1;
	cin >> T;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%modenum;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3])%modenum;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2])%modenum;
	}
	while (T--) {
		cin >> n;
		cout << (dp[n][1]+dp[n][2]+dp[n][3])%modenum<<"\n";
	}
	return 0;
}
// 5  --> 1+3  +1, 2+1 +2,3 +2