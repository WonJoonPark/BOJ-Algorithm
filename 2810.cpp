#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N,holder;
string inputs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> inputs;
	holder = N + 1; //±âº»
	for (int i = 0; i < N; i++) {
		if (inputs[i] == 'L') {
			holder--; i++;
		}
	}
	if (holder >= N) { cout << N << "\n"; }
	else cout << holder << "\n";
	return 0;
}