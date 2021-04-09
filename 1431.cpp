#include<bits/stdc++.h>
using namespace std;

int n;
string serial[1001];

int getsum(string s) {
	int tmpsum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') tmpsum += s[i] - '0';
	}
	return tmpsum;
}

bool compare(string& s1, string& s2) {
	if (s1.length() < s2.length()) return true;
	else if (s1.length() == s2.length()) {
		if (getsum(s1) < getsum(s2)) return true;
		else if (getsum(s1) == getsum(s2)) {
			return s1 < s2;
		}
		else return false;
	}
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}
	sort(serial, serial + n,compare);
	for (int i = 0; i < n; i++) {
		cout << serial[i] << "\n";
	}
	return 0;
}