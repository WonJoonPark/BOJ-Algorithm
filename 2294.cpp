#include<bits/stdc++.h>
using namespace std;

int n, k;
int narr[100];
int dp[100001]; //k ���� ����� �ִ� ������ �� (������ �ִ� ��ġ ������ 10������)


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i <= k; i++) { //�ִ�ġ �̻����� �ʱ�ȭ
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