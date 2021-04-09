#include<bits/stdc++.h>
using namespace std;

int n, k;
int coinarr[100];
int dp[10001]; // k�� ���� �� �ִ� ������ �ּҰ��� (������ ��ġ ������ 10��������)

//������ �ּҰ���
// ��ġ�� ���� ������ ������ �־��� �� �� �ִ�.

int makedp(int k) {
	if (dp[k] != 0) return dp[k];
	int minresult = 10001;

	for (int i = 0; i < n; i++) {
		if (k - coinarr[i] > 0) { //������ �׼��� k���� Ŭ ���� �����Ѵ�
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
		dp[coinarr[i]] = 1; //�ʱ�ȭ
	}

	if (makedp(k) == 10001) cout << -1<<"\n";
	else cout << dp[k] << "\n";

	return 0;
}