#include<bits/stdc++.h>
using namespace std;

int n, m;
int ground[1001][1001];
int maxresult;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c; ground[i][j] = c - '0';
			if (ground[i][j]== 1) {
				ground[i][j] = min(min(ground[i][j - 1], ground[i - 1][j]), ground[i - 1][j - 1]) + 1;
				maxresult = max(maxresult, ground[i][j]);
			}
		}
	}
	cout << maxresult*maxresult;
	return 0;
}