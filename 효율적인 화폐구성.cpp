#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[100001];

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> moneyclass(N);
	for (int i = 0; i < N; i++) {
		cin >> moneyclass[i];
		dp[moneyclass[i]] = 1; //자기자신으론무조건 가능
	}
	for(int i=1;i<=M;i++){
		vector<int> tmparr;
		for (int  j= 0; j < N; j++) {
			if (dp[i- moneyclass[j]] != 0 && i-moneyclass[j]>0) {
				tmparr.push_back(dp[i - moneyclass[j]] + 1);
			}
		}
		sort(tmparr.begin(), tmparr.end());
		if (tmparr.empty() == true) { continue; }
		else { dp[i] = tmparr[0]; }
	}
	if (dp[M] == 0) { cout << -1 << "\n"; }
	else { cout << dp[M] << "\n"; }
	return 0;
}