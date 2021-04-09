#include<bits/stdc++.h>
using namespace std;
using std::acos;

const double pi = acos(-1);

const long long modenum = 1000000000000000000;

long long dp[1001][1001]; //i 는 정수 , j는 pi의 수
long long n;


long long getfibo(int n, int i, int j) {
	double tmp = n - i - (long double)(pi * j);
	if (0 <= tmp && tmp <= pi) return 1;
	else if (tmp < 0) return 0;

	if (dp[i][j] != 0) return dp[i][j];
	else {
		dp[i][j] = (getfibo(n, i + 1, j) % modenum + getfibo(n, i, j + 1) % modenum)%modenum;
		return dp[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cout<<getfibo(n, 0, 0);

	return 0;
}