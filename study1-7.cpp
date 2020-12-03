#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string minsik;
int N;
int cacul(string s) {
	int Lcount = 0;
	int Ocount = 0;
	int Vcount = 0;
	int Ecount = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'L') Lcount++;
		if (s[i] == 'O') Ocount++;
		if (s[i] == 'V') Vcount++;
		if (s[i] == 'E') Ecount++;
	}
	for (int i = 0; i < minsik.length(); i++) {
		if (minsik[i] == 'L') Lcount++;
		if (minsik[i] == 'O') Ocount++;
		if (minsik[i] == 'V') Vcount++;
		if (minsik[i] == 'E') Ecount++;
	}
	return ((Lcount + Ocount)*(Lcount + Vcount)*(Lcount + Ecount)*
		(Ocount + Vcount)*(Ocount+Ecount)*(Vcount+Ecount)) % 100;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> minsik;// ¿À¹Î½Ä
	cin >> N;
	int maxvalue;
	string choosen;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (i == 0) { choosen = tmp;
		maxvalue = cacul(tmp);
		continue;
		}
		if (cacul(tmp) >= maxvalue) {
			if (cacul(tmp) == maxvalue) {
				if (tmp < choosen) { choosen = tmp; }
			}
			else choosen = tmp; maxvalue = cacul(tmp);
		}
	}
	cout << choosen << "\n";
	return 0;
}