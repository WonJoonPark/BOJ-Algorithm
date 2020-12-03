#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, K;
int dp[100001]; // 버틸 수 있는 무게 별로 최대가치를 저장하는 테이블
int weightarr[101];
int valuearr[101];

void dypro() {
	for (int i = 1; i <= N; i++) {
		for (int j =K; j >= 0; j--) {
			if (weightarr[i]<= j) {
				dp[j] = max(dp[j], dp[j- weightarr[i]] + valuearr[i]);
			}
		}
	}
	cout << dp[K] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> weightarr[i] >> valuearr[i];
	}
	dypro();
	return 0;
}