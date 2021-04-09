#include<bits/stdc++.h>
using namespace std;
int n, k;
bool alpha[26]; //배웠는지 안배웠는지 여부
string inputs[50];
int resultcount;

int checkstring() {
	int tmpcount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < inputs[i].length(); j++) {
			if (alpha[inputs[i][j] - 'a'] == false) break;
			if (j == inputs[i].length() - 1) tmpcount++;
		}
	}
	return tmpcount;
}

void makecase(int cnt,int index) {
	if (cnt == k-5) {
		resultcount=max(resultcount,checkstring());
		return;
	}
	for (int i = index; i < 26; i++) {
		if (alpha[i] != true) {
			alpha[i] = true;
			makecase(cnt + 1, i + 1);
			alpha[i] = false;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> inputs[i];
	}
	if (k < 5) { cout << 0; return 0; }
	else { 
		alpha['a' - 'a'] = true;
		alpha['t' - 'a'] = true;
		alpha['i' - 'a'] = true;
		alpha['n' - 'a'] = true;
		alpha['c' - 'a'] = true;
	}
	makecase(0,0);
	cout << resultcount << "\n";
	return 0;
}