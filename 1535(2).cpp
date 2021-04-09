#include<bits/stdc++.h>
using namespace std;


//1~N 까지의 사람
// 체력은 100 기쁨은 0

int N;
int peopleL[21];
int peopleJ[21];
int dp[21][101]; // 사람 , 체력 ==> value는 기쁨

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> peopleL[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> peopleJ[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 100; j++) {
			if (j - peopleL[i] > 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - peopleL[i]] + peopleJ[i]);
			}
			else { dp[i][j] = dp[i - 1][j]; }
		}
	}
	cout << dp[N][100];
	return 0;
}