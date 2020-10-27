#include<iostream>
#include<vector>
using namespace std;

int lottonum[6];
int k;
int karr[13];
void lotto(int start, int num) {
	if (num == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lottonum[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < k; i++) {
		lottonum[num] = karr[i];
		lotto(i + 1, num + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> k;
		if (k == 0) { break; }
		for (int i = 0; i < k; i++) {
			cin >> karr[i];
		}
		lotto(0, 0);
		cout << '\n';
	}
	return 0;
}