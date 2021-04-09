#include<bits/stdc++.h>
using namespace std;

int n, k; // 전체날짜 수 , 연속구간의 수
int narr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int tmpk = 0;
	int tsum = 0;
	for (int i = 0; i < n; i++) {
		cin >> narr[i];
		if (tmpk < k) { // 0~ k-1 까지 구간합
			tsum += narr[i]; tmpk++;
		}
	}
	int sindex = 0;
	int eindex = k - 1;
	int resultmax = tsum;
	while (eindex < n - 1) {
		tsum -= narr[sindex];
		tsum += narr[eindex + 1];
		sindex++; eindex++;
		resultmax = max(resultmax, tsum);
	}
	cout << resultmax;

	return 0;
}