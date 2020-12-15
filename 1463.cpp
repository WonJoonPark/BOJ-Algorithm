#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int X;
int dp[1000001];

//메모리 초과
/*int getdp(int num) {
	if (dp[num] == 0) {
		if (num % 3 == 0) { dp[num] = min((getdp(num - 1) + 1), (getdp(num / 3) + 1)); return dp[num]; }
		else if (num % 2 == 0) { dp[num] = min((getdp(num - 1) + 1),(getdp(num / 2) + 1)); return dp[num]; }
		else { dp[num] = getdp(num - 1) + 1; return dp[num]; }
	}
	else { return dp[num]; }
}*/
void bottomup() {
	for (int i = 6; i < 1000001; i++) {
		if (i % 3 == 0) {dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);}
		else if(i%2==0){ dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1); }
		else { dp[i] = dp[i - 1] + 1; }
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> X;   //  X>1
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 3;
	bottomup();
	cout<<dp[X]<<"\n";
	return 0;
}