#include<bits/stdc++.h>
using namespace std;

bool notpri[1003002]; //백만을 넘으면서 소수이면서 펠린드롬
string inputs;

bool pelin(string s) {
	int slen = s.length();
	for (int i = 0; i < slen / 2; i++) {
		if (s[i] != s[slen - 1 - i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> inputs;
	for (int i = 2; i <= 1003001; i++) { //범위 설정 조심
		if (notpri[i] == true) continue; //이미 소수 아님
		int t = 2;
		while (t * i <= 1003001) {
			notpri[t * i] = true;
			t++;
		}
		if (stoi(inputs) <= i) { //소수 이면서 inputs 보다 크거나 같음
			if (pelin(to_string(i))) {
				cout << i; return 0;
			}
		}
	}
}
