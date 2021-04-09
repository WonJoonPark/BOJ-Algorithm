#include<bits/stdc++.h>
using namespace std;

int N;
int peopleL[21]; //¾ò´Â±â»Ý
int peopleJ[21]; //ÀÒ´ÂÃ¼·Â
int dp[101];

int makedp(int k) {
	if (dp[k] != 0) return dp[k];
	else {
		dp[k]=
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> peopleL[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> peopleJ[i];
		dp[peopleJ[i]] = peopleL[i];
	}
	cout << makedp(100);
	return 0;
}