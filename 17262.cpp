#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int fir=0;
int last = 100001;
vector<pair<int, int>> fans;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		if (tmp.second < last) { last = tmp.second; }
		if (tmp.first > fir) { fir = tmp.first; }
	}
	if (fir - last <= 0) { cout << 0 << "\n"; }
	else cout << fir - last << "\n";
	return 0;
}