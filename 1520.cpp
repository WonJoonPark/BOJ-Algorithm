#include<bits/stdc++.h>
using namespace std;

int n, m;
int ground[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int resultcount;
int dp[501][501];

void inputs() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			dp[i][j] = -1;
		}
	}
}
bool boundcheck(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m) return true;
	else return false;
}

int findway(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	int waysum = 0;
	for (int i = 0; i < 4; i++) {
		if (boundcheck(x + dx[i], y + dy[i])&&ground[x+dx[i]][y+dy[i]]>ground[x][y]) {
			waysum += findway(x + dx[i], y + dy[i]);
		}
	}
	dp[x][y] = waysum;
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	dp[0][0] = 1;
	cout << findway(n-1,m-1);
	return 0;
}