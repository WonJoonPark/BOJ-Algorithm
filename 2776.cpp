#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> narr(n);
		for (int i = 0; i < n; i++) cin >> narr[i];
		sort(narr.begin(), narr.end()); // Á¤·Ä

		cin >> m;
		vector<int> marr(m);
		for (int i = 0; i < m; i++) cin >> marr[i];

		for (int i = 0; i < m; i++) { //¼öÃ¸ 2
			int lowindex = 0; int highindex = n - 1;
			while (1) {
				if (lowindex > highindex) { cout << 0<<"\n"; break;}
				int midindex = (lowindex + highindex) / 2;
				if (narr[midindex] == marr[i]) {cout << 1 << "\n"; break;}

				if (narr[midindex] > marr[i]) {
					highindex = midindex - 1;
				}
				else {
					lowindex = midindex + 1;
				}
			}
		}
	}
	return 0;
}