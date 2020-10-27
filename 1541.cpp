#include<iostream>
#include<string>
using namespace std;

bool minuscheck = 0;
string inputstring;
string tmpnumstored = "";
int resultnum = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
		cin >> inputstring;
		int minus = 0;
		for (int i = 0; i <= inputstring.size(); i++) {
			if (inputstring[i] == '+' || inputstring[i] == '-' || inputstring[i] == NULL) { //마지막 것도
				if (minus == 1) {
					resultnum -= stoi(tmpnumstored); 
				}
				else{
					resultnum += stoi(tmpnumstored);
				}
				tmpnumstored = "";
				if (inputstring[i] == '-') {
					minus = 1; 
				}
			}
			else { tmpnumstored += inputstring[i]; }
		}
		cout << resultnum;


	return 0;
}