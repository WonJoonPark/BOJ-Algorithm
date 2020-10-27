#include<iostream>
using namespace std;

int N, R, C;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> R >> C;
	if ((R + C) % 2 == 0) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if ((i+j) % 2 == 0) {
					cout << 'v';
				}
				else { cout << '.'; }
			}
			cout << '\n';
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if ((i + j) % 2 == 0) {
					cout << '.';
				}
				else { cout << 'v'; }
			}
			cout << '\n';
		}
	}
	return 0;
}
