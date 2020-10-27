#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> portarr(N, 0);
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> portar;
	}
	int bigorsmall = 0;
	int contemporarycount = 1;
	int maxcount = 0;
	for (int i = 0; i < N; i++) {
		bigorsmall = portarr[i];
		for (int j = i+1; j < N; j++) {
			if (bigorsmall < portarr[j]) {
				bigorsmall = portarr[j];
				contemporarycount++;
			}
		}
		if (contemporarycount > maxcount) {
			maxcount = contemporarycount;
		}
		contemporarycount = 1; // 첫번째 꺼는 무조건 연결 가능하므로
	}
	cout << maxcount << '\n';
	return 0;
}