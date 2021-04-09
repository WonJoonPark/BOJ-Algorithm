#include<bits/stdc++.h>
using namespace std;

int t, n;
long long koongarr[68];
long long makefibo(int n) {
	if (koongarr[n] != 0) return koongarr[n];
	koongarr[n] = makefibo(n - 1) + makefibo(n - 2) + makefibo(n - 3) + makefibo(n - 4);
	return koongarr[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	koongarr[0] = 1; koongarr[1] = 1; koongarr[2] = 2; koongarr[3] = 4;
	while (t--) {
		cin >> n;
		cout<<makefibo(n)<<"\n";
	}
	return 0;
}