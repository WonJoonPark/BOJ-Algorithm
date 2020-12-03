#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == N-i-1) cout << "*";
			else cout << " ";
		}
		for (int j = 0; j < i; j++) {
			if (j == i - 1) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}

	return 0;
}