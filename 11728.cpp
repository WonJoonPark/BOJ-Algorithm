#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m,tmp;
	cin >> n >> m;
	vector<int> resultarr;
	for (int i = 0; i < n; i++) {
		cin >> tmp; resultarr.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp; resultarr.push_back(tmp);
	}
	sort(resultarr.begin(), resultarr.end());
	for (int i = 0; i < resultarr.size(); i++) {
		cout << resultarr[i] << " ";
	}
	return 0;
}