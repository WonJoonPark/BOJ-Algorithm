#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int dp[1001];

int getdpvalue(int num) {
	if(dp[num]==0){
		dp[num] = (getdpvalue(num - 1) % 10007 + (2*getdpvalue(num - 2)) % 10007)%10007;
		return dp[num];
	}
	else return dp[num];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	dp[1] = 1; dp[2] = 3;
	cout<<getdpvalue(n)<<"\n";
	return 0;
}