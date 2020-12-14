#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int  n;
int dp[1001];

int getdpvalue(int num) {
	if (dp[num] == 0) { 
		dp[num] = (getdpvalue(num - 1) % 10007 + getdpvalue(num - 2) % 10007);
		return dp[num] % 10007;
	}
	else return dp[num]%10007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	dp[1] = 1; dp[2] = 2; dp[3] = 3; // 3�� �ʱ�ȭ�����൵ �Ǳ��ϴ�
	                                 // (������ ����Ǽ� �׸� �׷������ϱ�..�Ʊ����)
	cout<<getdpvalue(n)<<"\n";

	return 0;
}