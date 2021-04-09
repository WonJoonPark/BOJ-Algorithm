#include<bits/stdc++.h>
using namespace std;
int m;
bool checknum[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m;
	int tmp;
	string tmps;
	while (m--) {
		cin >> tmps;
		if (tmps[0] == 'a' && tmps[1] == 'd') { //´õÇÔ
			cin >> tmp; checknum[tmp] = true;
		}
		else if (tmps[0] == 'r') {
			cin >> tmp; checknum[tmp] = false;
		}
		else if (tmps[0] == 'c') {
			cin >> tmp;
			if (checknum[tmp]) cout << 1<<"\n";
			else cout << 0 << "\n";
		}
		else if (tmps[0] == 't') {
			cin >> tmp;
			if (checknum[tmp]) { checknum[tmp] = false; }
			else { checknum[tmp] = true; }
		}
		else if (tmps[0] == 'a') {
			for (int i = 1; i <= 20; i++) {
				checknum[i] = true;
			}
		}
		else { //empty
			for (int i = 1; i <= 20; i++) {
				checknum[i] = false;
			}
		}
	}

	return 0;
}