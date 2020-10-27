#include<iostream>
#include<vector>
using namespace std;

vector<int> lps(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) { //중간에 가다가 틀리는 경우
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			j += 1;
			table[i] = j;
		}
	}
	return table;
}
void KMP(string whatstring, string pattern) {
	vector<int> table = lps(pattern);
	int whatstringtSize = whatstring.size();
	int patternSize = pattern.size();
	int j = 0;
	int result;
	for (int i = 0; i < whatstringtSize; i++) {
		while (j > 0 && whatstring[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (whatstring[i] == pattern[j]) {
			if (j == patternSize - 1) {
				result = i - patternSize+2;
				j = table[j];
				cout << "찾은 위치--> " << result << '\n';
			}
			else { j++; }
		}
	}
}
int main() {
	string inputstring = "ABABACABACAABACAABA";
	string pattern = "ABACAABA";
	KMP(inputstring, pattern);
	return 0;
}