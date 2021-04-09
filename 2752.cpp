#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int numarr[3];
	for (int i = 0; i < 3; i++) {
		cin >> numarr[i];
	}
	sort(numarr, numarr + 3);
	for (int i = 0; i < 3; i++) {
		cout << numarr[i] << " ";
	}
	return 0;
}