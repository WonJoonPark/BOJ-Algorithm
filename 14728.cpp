#include<bits/stdc++.h>
using namespace std;

int N, T;
pair<int, int> Narr[101]; //������νð�, ����
int dp[10001]; //���νð��� ȹ���Ҽ��ִ� �ִ�����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		cin >> Narr[i].first >> Narr[i].second;
	}
	for (int i = 1; i <= N; i++) {
		for (int j =T; j >= Narr[i].first; j--) {
			dp[j] = max(dp[j], dp[j - Narr[i].first] + Narr[i].second);
		}
	}
	cout << dp[T];
	return 0;
}