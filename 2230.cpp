#include<bits/stdc++.h>
using namespace std;
int n, m;
int num1, num2;
int tmpnum;
int minresult=2000000010;
int numarr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> numarr[i];
	}
	sort(numarr, numarr + n);
	int sindex = 0;
	int eindex = 1;
	while (eindex<n) {
		if (numarr[eindex] - numarr[sindex] >= m) { //m ÀÌ»ף
			if (minresult > (numarr[eindex] - numarr[sindex])) {
				minresult = numarr[eindex] - numarr[sindex];
			}
			sindex++;
		}
		else eindex++;
	}
	cout << minresult;
	return 0;
}