#include<bits/stdc++.h>
using namespace std;

int n, k;
int narr[100];
int dp[100001]; //k 원을 만들수 있는 동전의 수 (동전의 최대 가치 때문에 10만으로)


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i <= k; i++) { //최대치 이상으로 초기화
		dp[i] = 10001;
	}
	for (int i = 0; i < n; i++) {
		cin >> narr[i];  dp[narr[i]] = 1;
	}
	for (int i = 1; i <= k; i++) {
		if (dp[i] != 10001) {
			for (int j = 0; j < n; j++) {
				dp[i + narr[j]] = min(dp[i + narr[j]], dp[i] + 1);
			}
		}
	}
	if (dp[k] == 10001) cout << -1;
	else cout << dp[k];
	return 0;
}