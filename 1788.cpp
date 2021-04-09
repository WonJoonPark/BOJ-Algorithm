#include<bits/stdc++.h>
using namespace std;
const int ZEROINDEX = 1000000;
const int MODENUM = 1000000000;

//f(n)=f(n-1)+f(n-2)
//f(n-2)=f(n)+f(n-1)
int fibo[2000001];
int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	fibo[ZEROINDEX] = 0; fibo[ZEROINDEX+1] = 1;
	fibo[ZEROINDEX-1] = 1;
	//양수부
	for (int i = 1000002; i <= 2000000; i++) { //양수부
		fibo[i] = fibo[i - 1]% MODENUM + fibo[i - 2]% MODENUM;
	}
	for (int i = 999998; i >= 0; i--) { //음수부
		fibo[i]= fibo[i + 2]% MODENUM - fibo[i + 1]% MODENUM;
	}
	n += 1000000;
	if (fibo[n] % MODENUM == 0) cout << 0 << "\n";
	else if (fibo[n] % MODENUM > 0) cout << 1 << "\n";
	else cout << -1 << "\n";
	cout << abs(fibo[n]) % MODENUM;

	return 0;
}