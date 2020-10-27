#include<iostream>
#include<vector>
using namespace std;

int N;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 1) { cout << ' '; }
		for (int j = 0; j < N; j++) {
			cout << "* ";
		}
		cout << '\n';
	}
	return 0;
}