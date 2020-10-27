#include<iostream>
#include<vector>
#include<string>
using namespace std;

string input;
int count;

vector<int> lps(string pattern) {
	int patternsize = pattern.size();
	vector<int> table(patternsize, 0);
	int j = 0;
	for (int i = 1; i < patternsize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			j++;
			table[i] = j;
		}
	}
	return table;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	while (1) {
		cin >> input;
		if (input == ".") { break;}

}
	return 0;
}