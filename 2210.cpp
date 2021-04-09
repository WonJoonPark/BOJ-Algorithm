#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int ground[5][5];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int resultcount;
vector<int> resultarr;
int tmp ;
int deci ;

void dfs(int x, int y,int cnt) {
	if (cnt == 5) {
		bool check = false;
		for (int i = 0; i < resultarr.size(); i++) {
			if (tmp == resultarr[i]) { check = true; break; }
		}
		if (check == false) { resultarr.push_back(tmp); resultcount++; }
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i]; int nexty = y + dy[i];
		if (nextx >= 0 && nextx < 5 && nexty >= 0 && nexty < 5) {
			tmp *= 10;
			tmp += ground[nextx][nexty];
			dfs(nextx, nexty, cnt + 1);
			tmp -= ground[nextx][nexty];
			tmp /= 10;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> ground[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp = ground[i][j]; deci = 1;
			dfs(i, j,0);
		}
	}
	cout << resultcount << "\n";
	return 0;
}