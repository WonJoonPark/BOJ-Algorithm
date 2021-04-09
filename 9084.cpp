#include<bits/stdc++.h>
using namespace std;

int T, N, M;
int coin[21];
int dp[10001];//M원을 만드는 모든방법의 수

void init() {
	for (int i = 0; i <= M; i++) {
		dp[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> N; //동전의 가짓 수

		for (int i = 1; i <= N; i++) {
			cin >> coin[i];
		}
		cin >> M; //만들어야 하는 금액
		init();		
		dp[0] = 1; //초기화를 위해
		for (int i = 1; i <= N; i++) {
			for (int j = coin[i]; j <= M; j++) { //오름차순이니까
				dp[j] += dp[j - coin[i]];
			}
		}
		/*
		for (int i = 1; i <= M; i++) {
				cout << dp[i]<<" ";
		}
		cout << "\n";*/
		cout << dp[M] << "\n";
	}
	return 0;
}