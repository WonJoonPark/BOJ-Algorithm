#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

string s;
vector<char> carr;
vector<char> tmpc;
int resultlen;

bool isitpelen() {
	for (int i = 0; i < tmpc.size() / 2; i++) {
		if (tmpc[i] != tmpc[tmpc.size() - 1 - i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); i++) carr.push_back(s[i]);

	resultlen = s.length();
	tmpc = carr;
	if (isitpelen()){
		cout << resultlen << "\n"; return 0;
	}
	for (int i = 0; i < s.length(); i++) {
		tmpc = carr;
		for (int j = i; j >= 0; j--) {
			tmpc.push_back(s[j]);
			if (isitpelen()) {
				cout << resultlen + i + 1 << "\n"; return 0;
			}
		}
	}
	return 0;
}