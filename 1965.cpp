#include<bits/stdc++.h>
using namespace std;

int dp[1001]; // ��ǻ� ��Ȯ�� dp�� ������ �ִ� ���̺��� �ƴϴ�.
int n;
int narr[1001]; //������ ũ��


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) { //�ʱ�ȭ
		cin >> narr[i]; dp[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (narr[i] > narr[j] && dp[i]<dp[j]+1) {
				dp[i] = dp[j]+ 1;
			}
		}
	}
	sort(dp + 1, dp + (n + 1));
	cout << dp[n];

	return 0;
}