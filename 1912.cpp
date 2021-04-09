#include<bits/stdc++.h>
using namespace std;

vector<int> numarr;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int tmpinput;
	int tmpmax = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmpinput;
		if (i == 0) { numarr.push_back(tmpinput); tmpmax = tmpinput; continue; }
		numarr.push_back(max(numarr[i - 1] + tmpinput, tmpinput));
		if (tmpmax < numarr[i]) tmpmax = numarr[i];
	}
	cout << tmpmax;

	return 0;
}