#include<bits/stdc++.h>
using namespace std;

int n, k;
long long icesum;
int icearr[1000001]; //��ǥ�� �ִ� ������ ��

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int g, x;
	for (int i = 0; i < n; i++) {
		cin >> g >> x;
		icearr[x] = g;
	}
	int sindex = 0;
	int eindex = 2 * k; //index�ϱ� �� 0~2k (2k+1)

	if (eindex > 1000000) { //�׳� ��� ������ �� ���Ҽ� �ִ� ���
		for (int i = 0; i <= 1000000; i++) {
			icesum += icearr[i];
		}
		cout << icesum;
		return 0;
	}

	for (int i = sindex; i <= eindex; i++) {
		icesum += icearr[i];
	}
	long long maxice = 0;
	while (eindex <= 1000000) {
		icesum -= icearr[sindex];
		icesum += icearr[eindex + 1];
		sindex++; eindex++;
		maxice = max(maxice, icesum);
	}
	cout << maxice;

	return 0;
}