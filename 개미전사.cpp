#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N;
int dp[1001];

vector<int> foodcontainer;
void caldp(int i) {
	if (dp[i - 1] == 0) { caldp(i - 1); }
	if (dp[i - 2] == 0) { caldp(i - 2); }
	dp[i] = max(dp[i - 2] + foodcontainer[i], dp[i - 1]);
}
int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		foodcontainer.push_back(tmp);
	}
	dp[0] = foodcontainer[0];
	dp[1] = max(foodcontainer[0],foodcontainer[1]);
	caldp(N - 1);
	cout << dp[N-1];
	return 0;
}