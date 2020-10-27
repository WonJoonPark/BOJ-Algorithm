#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> moneyarr(N,0);
	for (int i = N - 1; i >= 0; i--) {
		cin >> moneyarr[i];
	}
	int moneycount=0;
	int arrnum = 0;
	while (1) {
		if (K == 0) { cout << moneycount << '\n'; break;}
		moneycount += K / moneyarr[arrnum];
		K= K % moneyarr[arrnum];
		arrnum++;
	}
	return 0;
}