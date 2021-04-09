#include<bits/stdc++.h>
using namespace std;

int dp[1001]; // 사실상 정확한 dp를 가지고 있는 테이블은 아니다.
int n;
int narr[1001]; //상자의 크기


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) { //초기화
		cin >> narr[i]; dp[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (narr[i] > narr[j] && dp[i]<dp[j]+1) {
				dp[i] = dp[j]+ 1;
			}
		}
	}
	sort(dp + 1, dp + (n + 1));
	cout << dp[n];

	return 0;
}