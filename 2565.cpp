#include<bits/stdc++.h>
using namespace std;

int n;
pair<int, int> inputarr[100];
int dp[100]; 


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inputarr[i].first >> inputarr[i].second;
		dp[i] = 1;
	}
	sort(inputarr,inputarr + n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (inputarr[i].second > inputarr[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	sort(dp, dp + n);
	cout <<n-dp[n-1];

	return 0;
}