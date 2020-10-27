#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int N;
vector<string> sarr;
bool compare(string a, string b) {
	if (a.length() == b.length()) { //길이가 같으면
		if (a < b) { return true; }
		else { return false; }
	}
	else {
		if (a.length() < b.length()) {
			return true;
		}
		else { return false; }
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	string ts;
	for (int i = 0; i < N; i++) {
		cin >> ts;
		sarr.push_back(ts);
	}
	sort(sarr.begin(), sarr.end(), compare);
	for (int i = 0; i < sarr.size(); i++) {
		if (i != sarr.size() - 1) {
			if (sarr[i] == sarr[i + 1]) {
				continue;
			}
			else { cout << sarr[i] << "\n"; }
		}
		else {
			cout << sarr[i] << "\n";
		}
	}
	return 0;
}