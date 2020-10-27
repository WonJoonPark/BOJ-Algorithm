#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int loadarr[200000001];

struct homecopor {
	int home;
	int copor;
	int length;
};
bool cmp(homecopor a, homecopor b) {
	if (a.length < b.length) { return true; }
	else return false;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int d, n;
	cin >> n;
	vector<homecopor> hcarr;
	homecopor tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp.home >> tmp.copor;
		if (tmp.home - tmp.copor < 0) {
			tmp.length = tmp.copor - tmp.home;
		}
		else {
			tmp.length = tmp.home - tmp.copor;
		}
		hcarr.push_back(tmp);
	}
	cin >> d;
	sort(hcarr.begin(), hcarr.end(), cmp);
	for (int i = 0; i < hcarr.size(); i++) {
		if (hcarr[i].length > d) { break; }
		if (hcarr[i].home > hcarr[i].copor) {
			for (int j = hcarr[i].copor; j <= hcarr[i].home; j++) {
				loadarr[j]++;
			}
		}
		else {
			for (int j = hcarr[i].home; j <= hcarr[i].copor; j++) {
				loadarr[j]++;
			}
		}
	}
}