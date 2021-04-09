#include<bits/stdc++.h>
using namespace std;

int n;
long long narr[81];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	narr[1] = 1; narr[2] = 1;
	for (int i = 3; i <= n; i++) narr[i] = narr[i - 1] + narr[i - 2];
	if (n >= 4) {
		cout << (long long)(3 * (narr[n]) + 2 * narr[n - 1] + 2 * narr[n - 2] + narr[n - 3]);
	}
	else {
		if (n == 1) cout << 4;
		else if (n == 2) cout << 6;
		else cout << 10;
	}

	return 0;
}