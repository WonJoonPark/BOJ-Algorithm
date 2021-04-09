#include<bits/stdc++.h>
using namespace std;

int n, k;
int coinarr[100];
int dp[10001]; // k를 만들 수 있느 동전의 최소개수 (동전의 가치 때문에 10만개까지)

//동전의 최소개수
// 가치가 같은 동전이 여러개 주어질 수 도 있다.

int makedp(int k) {
	if (dp[k] != 0) return dp[k];
	int minresult = 10001;

	for (int i = 0; i < n; i++) {
		if (k - coinarr[i] > 0) { //동전의 액수가 k보다 클 경우는 무시한다
			minresult = min(minresult, makedp(k - coinarr[i]) + 1);
		}
	}
	dp[k] = minresult;
	return dp[k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coinarr[i];
		if (coinarr[i] > k) continue;
		dp[coinarr[i]] = 1; //초기화
	}

	if (makedp(k) == 10001) cout << -1<<"\n";
	else cout << dp[k] << "\n";

	return 0;
}