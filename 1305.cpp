#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> lpstable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			j += 1;
			table[i] = j;
		}
	}
	return table;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int L;
	string inputstring;
	cin >> L>>inputstring;
	vector<int> lps = lpstable(inputstring);
	cout << L - lps[L - 1] << '\n';
	return 0;
}