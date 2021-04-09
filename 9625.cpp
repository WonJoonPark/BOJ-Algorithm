#include<bits/stdc++.h>
using namespace std;

int k;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> k;
	int a = 1;
	int b = 0;
	int tmpb;
	for (int i = 1; i <= k; i++) {
		tmpb = b;
		b = (b + a);
		a = tmpb;
	}
	cout << a << " " << b;
	return 0;
}