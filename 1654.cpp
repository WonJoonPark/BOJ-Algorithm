#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long N;
int K;
vector<int> lanarr;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> K >> N;
	int tmp;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		lanarr.push_back(tmp);
	}
	sort(lanarr.begin(), lanarr.end(), greater<int>() );
	int reminus=lanarr[0];
	long long sum = 0;
	while (1) {
		sum = 0;
		for (int i = 0; i < lanarr.size(); i++) {
			int tmparr=lanarr[i];
			if (tmparr < reminus) { break; }
			while (1) {
				tmparr -= reminus;
				if (tmparr < 0) { break; }
				sum++;
			}
		}
		if (sum == N) {break; }
		reminus--;
	}
	cout << reminus << '\n';
	return 0;
}