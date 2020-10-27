#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string A;
string B;
int result[100001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> A >> B;
	int Alen = A.length();
	int Blen = B.length();
	int Resultlength;
	// ÀÚ¸´¼ö ¸ÂÃçÁÖ±â
	if (Alen > Blen) {
		for (int i = 0; i < Alen; i++) {
			if (i < Alen - Blen) {
				result[i] = A[i] - '0';
			}
			else { result[i] = (A[i] - '0') + B[i - (Alen - Blen)] - '0'; }
		}
		for (int j = Alen - 1; j > 0; j--) {
			if (result[j] >= 10) {
				result[j] %= 10;
				result[j - 1]++;
			}
		}
		int c = 0;
		while (1) {
			if (Alen == c) { break; }
			cout << result[c];
			c++;
		}
		cout << '\n';
		char resulttostring[100001];
		for (int i = 0; i < Alen; i++) {
			cout << result[i];
			resulttostring[i] = (char)(result[i]+48);
			cout << resulttostring[i];
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < Blen; i++) {
			if (i < Blen - Alen) {
				result[i] = B[i] - '0';
			}
			else { result[i] = (B[i] - '0') + A[i - (Blen - Alen)] - '0'; }
		}
		for (int j = Blen - 1; j > 0; j--) {
			if (result[j] >= 10) {
				result[j] %= 10;
				result[j - 1]++;
			}
		}
		int c = 0;
		while (1) {
			if (Blen == c) { break; }
			cout << result[c];
			c++;
		}
		cout << '\n' << result[0];
		cout << '\n';
		char resulttostring[100001];
		for (int i = 0; i < Blen; i++) {
			resulttostring[i] = (char)(result[i]+48);
			cout << resulttostring[i];
		}
		cout << '\n';
	}

	return 0;
}