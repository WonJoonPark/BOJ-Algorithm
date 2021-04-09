#include<bits/stdc++.h>
using namespace std;

int numarr[1000001];

int n;

/* 메모리초과(스택)
int makenum(int n) {
	if (numarr[n] != 0) return numarr[n];
	if (n % 3 == 0 && n % 2 == 0) {
		numarr[n] = min(makenum(n / 3)+1,min( makenum(n / 2)+1, makenum(n - 1)+1));
	}
	else if (n % 3 == 0) {
		numarr[n] = min(makenum(n / 3)+1, makenum(n - 1)+1);
	}
	else if (n % 2 == 0) {
		numarr[n] = min(makenum(n / 2)+1, makenum(n - 1)+1);
	}
	else { numarr[n] = makenum(n - 1)+1; }
	return numarr[n];

}
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	numarr[1] = 0;
	numarr[2] = 1;
	numarr[3] = 1;
	numarr[4] = 2;
	cin >> n;

	for (int i = 5; i <= n; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			numarr[i] = min(numarr[i / 3] + 1, min(numarr[i / 2] + 1, numarr[i - 1] + 1));
		}
		else if (i % 3 == 0) {
			numarr[i] = min(numarr[i / 3] + 1, numarr[i - 1] + 1);
		}
		else if (i % 2 == 0) {
			numarr[i] = min(numarr[i / 2] + 1, numarr[i - 1] + 1);
		}
		else numarr[i] = numarr[i - 1] + 1;
	}
	cout << numarr[n];


	return 0;
}