#include<bits/stdc++.h>
using namespace std;

int n, m;
int tmpsum[10001];
int sindex = 0;
int eindex = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int tmp = 0;
	for (int i = 1; i <= n; i++) { //1~n까지의 합들이 저장됨
		cin >> tmpsum[i];
		tmpsum[i] += tmp;
		tmp = tmpsum[i];
	}
	int resultcount = 0;
	while (sindex <= n) {
		if (m == (tmpsum[eindex] - tmpsum[sindex])) {
			resultcount++;
			sindex++; 
			if (eindex == n) break;
			eindex++;
			continue;
		}
		if (m < (tmpsum[eindex] - tmpsum[sindex])) {
			sindex++;
		}
		if (m > (tmpsum[eindex] - tmpsum[sindex])) {
			if (eindex == n) break;
			eindex++;
		}
	}
	cout << resultcount << "\n";

	return 0;
}