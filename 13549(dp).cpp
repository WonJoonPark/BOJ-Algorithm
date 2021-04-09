#include<bits/stdc++.h>
using namespace std;

int n, k; // 수빈, 동생
pair<bool, int> dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if (n >= k) { cout << n - k; }
	else {

		for (int i = 0; i <100001; i++) {
			dp[i].second = 100001;
		}

		dp[n].first = true; dp[n].second = 0;
		for (int i = n; i <=k; i++) {
			//순간이동 (시간소모 없음)
			if (2 * i <= 100000) {
				if (dp[2 * i].first == false) {
					dp[2 * i].first = true;
					dp[2 * i].second = dp[i].second;
				}
				else {
					dp[2 * i].second = min(dp[2 * i].second, dp[i].second);
				}

			//-1
			if (i != 0) {
				if (dp[i - 1].first == false) {
					dp[i - 1].first = true;
					dp[i - 1].second = dp[i].second + 1;
				}
				else {
					if (dp[i - 1].second > (dp[i].second + 1)) {
						dp[i - 1].second = dp[i].second + 1;
						if (2 * (i - 1) <= 100000) {
							dp[2 * (i - 1)].second = min(dp[2 * (i - 1)].second, dp[i - 1].second);
						}
					}
				}
			}

			//+1
			if(i+1<=100000){
				if (dp[i + 1].first == false) {
				dp[i + 1].first = true;
				dp[i + 1].second = dp[i].second + 1;
				}
				else {
					if (dp[i + 1].second > (dp[i].second + 1)) {
						dp[i + 1].second = dp[i].second + 1;
						if (2 * (i + 1) <= 100000) {
							dp[2 * (i + 1)].second = min(dp[2 * (i + 1)].second, dp[i + 1].second);
						}
						}
				}
			}
		}
		for (int i = n; i <= 2 * k; i++) {
			cout << dp[i].second << " ";
		}
		cout << endl;
		cout << dp[k].second;
	}

	return 0;
}