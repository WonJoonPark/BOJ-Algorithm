#include<bits/stdc++.h>
using namespace std;

int T, N, M;
int coin[21];
int dp[10001];//M���� ����� ������� ��

void init() {
	for (int i = 0; i <= M; i++) {
		dp[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> N; //������ ���� ��

		for (int i = 1; i <= N; i++) {
			cin >> coin[i];
		}
		cin >> M; //������ �ϴ� �ݾ�
		init();		
		dp[0] = 1; //�ʱ�ȭ�� ����
		for (int i = 1; i <= N; i++) {
			for (int j = coin[i]; j <= M; j++) { //���������̴ϱ�
				dp[j] += dp[j - coin[i]];
			}
		}
		/*
		for (int i = 1; i <= M; i++) {
				cout << dp[i]<<" ";
		}
		cout << "\n";*/
		cout << dp[M] << "\n";
	}
	return 0;
}