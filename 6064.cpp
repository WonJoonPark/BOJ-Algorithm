#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T;
int M, N, x, y;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;
		int tx = 1; int ty = 1;
		int resultday = 1;
		bool check = false;
		while (1) {
			if (tx == x && ty == y) { check = true; break; }
			if (tx == M && ty == N) { break; }
			if (tx < M) { tx++; }
			else { tx = 1; }
			if (ty < N) { ty++; }
			else { ty = 1; }
			resultday++;
		}
		if (check == true) { cout << resultday << "\n"; }
		else { cout << -1 << "\n"; }
	}
	return 0;
}