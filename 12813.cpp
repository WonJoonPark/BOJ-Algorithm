#include<bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s1 >> s2;
	for (int a = 0; a < 5; a++) {
		if (a == 0) {// s1 & s2
			for (int i = 0; i < 100000; i++) {
				if (s1[i] == '1' && s2[i] == '1') {
					cout << "1";
				}
				else cout << "0";
			}
			cout << "\n";
		}
		if (a == 1) {// s1 | s2
			for (int i = 0; i < 100000; i++) {
				if (s1[i] == '1' || s2[i] == '1') {
					cout << "1";
				}
				else cout << "0";
			}
			cout << "\n";
		}
		if (a == 2) {// s1 ^ s2
			for (int i = 0; i < 100000; i++) {
				if (s1[i] !=s2[i]) {
					cout << "1";
				}
				else cout << "0";
			}
			cout << "\n";
		}
		if (a == 3) {// !s1
			for (int i = 0; i < 100000; i++) {
				if (s1[i] == '1') {
					cout << "0";
				}
				else cout << "1";
			}
			cout << "\n";
		}
		if (a == 4) {// !s2
			for (int i = 0; i < 100000; i++) {
				if (s2[i] == '1') {
					cout << "0";
				}
				else cout << "1";
			}
			cout << "\n";
		}
	}
	return 0;
}