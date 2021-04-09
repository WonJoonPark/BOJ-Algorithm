#include<bits/stdc++.h>
using namespace std;

int n;
double money;
int c;
double price;
int dp[10001]; //돈 m당 구매할 수 있는 가장 높은 칼로리
int newprice;
vector<pair<int, int>> candyset;

int makedp(int money) {
	if (dp[money] != -1) return dp[money]; //이미 존재
	dp[money] = 0;
	for (int i = 0; i < n; i++) {
		if (money - candyset[i].second >= 0) {
			dp[money] = max(dp[money], candyset[i].first + makedp(money - candyset[i].second));
		}
	}
	return dp[money];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> n >> money;
		memset(dp, -1, sizeof(dp));
		candyset.clear();
		if (n == 0 && money == 0.00) break;
		for (int i = 0; i < n; i++) {
			cin >> c >> price;
			newprice = (int)(price * 100+0.5);
			candyset.push_back({ c,newprice });
		}
		cout << makedp((int)(money * 100 + 0.5))<<"\n";
	}
	return 0;
}