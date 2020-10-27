#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> bnum;
	int num3, num5;
	int kgnum;
	num3 = 0; num5 = 0;
	cin >> kgnum;

	int tmpnum = kgnum;
	while (tmpnum>0) {
		if (tmpnum % 3 == 0) {
			int tmp3 = tmpnum / 3;
			bnum.push_back(tmp3 + num5);
		}
		else if (tmpnum % 5 == 0) {
			int tmp5 = tmpnum / 5;
			bnum.push_back(tmp5 + num5);
		}
		tmpnum -= 5;
		num5++;
	}
	tmpnum = kgnum;
	num3 = 0; num5 = 0;
	while (tmpnum > 0) {
		if (tmpnum % 3 == 0) {
			int tmp3 = tmpnum / 3;
			bnum.push_back(tmp3 + num3);
		}
		else if (tmpnum % 5 == 0) {
			int tmp5 = tmpnum / 5;
			bnum.push_back(tmp5 + num3);
		}
		tmpnum -= 3;
		num3++;
	}
	if (bnum.empty() == true) { cout << -1 << '\n'; return 0; }
	sort(bnum.begin(), bnum.end());
	cout << bnum[0] << '\n';
	return 0;
}