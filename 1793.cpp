#include<bits/stdc++.h>
using namespace std;




vector<int> bigintadd(vector<int> v1, vector<int> v2) {

	if (v1.size() < v2.size()) { // v1이 항상 더 큰수
		vector<int> tmpv = v1; v1 = v2; v2 = tmpv;
	}
	vector<int> result(v1.size());
	for (int i = 0; i < v1.size(); i++) {
		result[i] = 0;
	}
	if (v1.size() == v2.size() && (v1[v1.size() - 1] + v2[v2.size() - 1]) >= 10) {
		result.push_back(0); //사이즈 하나 증가
	}

	for (int i = 0; i < v2.size(); i++) {
		int tmpi = v1[i] + v2[i]+result[i];
		if (tmpi >= 10) { result[i + 1] += 1; result[i] =( tmpi-10); }
		else result[i] = tmpi;
	}
	for (int i = v2.size(); i < v1.size(); i++) {
		result[i] += v1[i];
	}

	return result;
}

// 점화식 dp[i]=dp[i-1]+dp[i-2]*(3-1)
// 큰수의 곱을 구현해야 한다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int> dp[251];
	dp[0].push_back(1); dp[1].push_back(1); dp[2].push_back(3);
	for (int i = 3; i <= 250; i++) {
		dp[i] = bigintadd(dp[i - 1], bigintadd(dp[i - 2], dp[i - 2])); //8은 171 7은 85   171+85+85
	}
	int n;
	while (cin>>n) {
		for (int i = dp[n].size() - 1; i >= 0; i--) {
			cout << dp[n][i];
		}
		cout << "\n";
	}
	return 0;
}