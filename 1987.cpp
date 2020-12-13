#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int R, C;
char inputchar[21][21];
bool visit[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 }; //동서북남
bool alphabetcheck[26]; //65(A)~90(Z)
int movecount = 0;
int maxresult = 0;

void inputs() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> inputchar[i][j];
		}
	}
}

bool movecheck(int x, int y ) {
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < R &&y + dy[i] >= 0 && y + dy[i] < C) {
			if (visit[x + dx[i]][y + dy[i]] == false && alphabetcheck[(int)inputchar[x + dx[i]][y + dy[i]] - 65] == false)
				return true;
		}
	}
	return false; //더 이상 갈 곳 없음
}

void dfs(int x, int y) {
	if (movecheck(x,y) == false) {
		if (maxresult < movecount) { maxresult = movecount; return; }
	}
	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i]; int nexty = y + dy[i];
		if (nextx >= 0 && nextx < R && nexty >= 0 && nexty < C) {
			if (visit[nextx][nexty] == false && alphabetcheck[(int)inputchar[nextx][nexty] - 65] == false) {
				alphabetcheck[(int)inputchar[nextx][nexty] - 65] = true;
				visit[nextx][nexty] = true;
				movecount++;
				dfs(nextx, nexty);
				movecount--;
				alphabetcheck[(int)inputchar[nextx][nexty] - 65] = false;
				visit[nextx][nexty] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	movecount++;
	alphabetcheck[inputchar[0][0] - 65] = true;
	visit[0][0] = true;
	dfs(0, 0);

	cout << maxresult << "\n";

	return 0;
}