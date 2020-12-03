#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string inputstring;
string fi, se, th;
string output;
string minresult="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
void reverse() {
	for (int i = 0; i < fi.length()/2; i++) {
		char tmpc=fi[i];
		fi[i]=fi[fi.length() - 1 - i];
		fi[fi.length() - 1 - i] = tmpc;
	}
	for (int i = 0; i < se.length()/2; i++) {
		char tmpc = se[i];
		se[i] = se[se.length() - 1 - i];
		se[se.length() - 1 - i] = tmpc;
	}
	for (int i = 0; i < th.length()/2; i++) {
		char tmpc = th[i];
		th[i] = th[th.length() - 1 - i];
		th[th.length() - 1 - i] = tmpc;
	}
	for (int i = 0; i < fi.length(); i++) {
		output.push_back(fi[i]);
	}
	for (int i = 0; i < se.length(); i++) {
		output.push_back(se[i]);
	}
	for (int i = 0; i < th.length(); i++) {
		output.push_back(th[i]);
	}
	if (minresult > output) { minresult = output; }
	output.clear();
}

void setstring(int i, int j, int k) {
	for (int a = 0; a <= i; a++) {
		fi.push_back(inputstring[a]);
	}
	for (int b = i + 1; b <= j; b++) {
		se.push_back(inputstring[b]);
	}
	for (int c = j + 1; c <= k; c++) {
		th.push_back(inputstring[c]);
	}
	reverse();
}

void divide() {
	for (int i = 0; i < inputstring.length() - 2; i++) {
		for (int j = i + 1; j < inputstring.length() - 1; j++) {
				setstring(i,j,inputstring.length()-1);
				fi.clear(); se.clear(); th.clear();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> inputstring;
	divide();
	cout << minresult << "\n";
	return 0;

}