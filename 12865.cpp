#include<bits/stdc++.h>
using namespace std;

int N, K;// ��ǰ�� ��, ��ƿ�� �ִ� ����
pair<int, int> narr[101]; //����,��ġ
int dpV[100001]; //��Ƽ�� ���Դ� �ִ밡ġ

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> narr[i].first>>narr[i].second;
	}
	sort(narr+1, narr+(N+1));
	for (int i = 1; i <= N; i++) {

		//** ���� �߿� �Ǽ����� �ݵ�� �ڿ��� ���� ���ߵ�
		for (int j = K; j >= narr[i].first; j--) { //������ ����
				dpV[j] = max(dpV[j], dpV[j - narr[i].first] + narr[i].second);
		}
	}
	cout << dpV[K];

	return 0;
}