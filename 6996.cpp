#include<bits/stdc++.h>
using namespace std;

int alpharr[26];

int n;
string s1,s2;
void alphaclear() {
	for (int i = 0; i < 26; i++) {
		alpharr[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		bool suc = true;
		cin >> s1>>s2;
		alphaclear();
		if (s1.length() != s2.length()) { //무조건 실패
			cout << s1 << " & " << s2 << " are NOT anagrams.\n";
			continue;
		}
		else {
			for (int i = 0; i < s1.length(); i++) {
				alpharr[(s1[i] - 'a')]++;
			}
			for (int i = 0; i < s2.length(); i++) {
				if (alpharr[(s2[i] - 'a')] == 0) { suc = false; break; }
				else alpharr[(s2[i] - 'a')]--;
			}
		}
		if (suc == true) {
			cout << s1 << " & " << s2 << " are anagrams.\n";
		}
		else {
			cout << s1 << " & " << s2 << " are NOT anagrams.\n";
		}
	}
	return 0;
}