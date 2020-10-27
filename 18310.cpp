#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> homeset;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		homeset.push_back(tmp);
	}
	sort(homeset.begin(), homeset.end());
	cout << homeset[(N - 1) / 2];
	return 0;
}