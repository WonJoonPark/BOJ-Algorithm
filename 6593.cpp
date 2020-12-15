#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int L, R, C;
int seconds;
char sangbumbuilding[31][31][31];
bool visit[31][31][31];
int dx[6] = { 1,-1,0,0,0,0 }; //6방향 탐색
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
struct area {
	int x, y, z;
};

queue<area> tmpq;
area S;
area E;
area tmpa, tmparea;
bool inputs() {
	cin >> L >> R >> C;
	if (L == 0 && R == 0 && C == 0) return true;

	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				visit[i][j][k] = false;
				cin >> sangbumbuilding[i][j][k];
				if(sangbumbuilding[i][j][k]=='S'){
					S.x = i; S.y = j; S.z = k;
				}
				if (sangbumbuilding[i][j][k] == 'E') {
					E.x = i; E.y = j; E.z = k;
				}
			}
		}
	}
	return false;
}

void bfs(area s) {
	tmpq.push(s);
	while (1) {
		if (tmpq.empty()) { cout << "Trapped!" << "\n"; return; }
		int tmpsize = tmpq.size();
		while(tmpsize--) { //1초당
			tmpa = tmpq.front();
			tmpq.pop();
			if (tmpa.x == E.x &&tmpa.y == E.y&&tmpa.z == E.z) {
				cout << "Escaped in "<<seconds<<" minute(s)."<<"\n"; return;
			}
			for (int i = 0; i < 6; i++) { //6방향탐색
				//범위 검사
				if (tmpa.x + dx[i] >= 1 && tmpa.x + dx[i] <= L && tmpa.y + dy[i] >= 1 && tmpa.y + dy[i] <= R && tmpa.z + dz[i] >= 1 && tmpa.z + dz[i] <= C) {
					if (sangbumbuilding[tmpa.x + dx[i]][tmpa.y + dy[i]][tmpa.z + dz[i]] == '.'|| sangbumbuilding[tmpa.x + dx[i]][tmpa.y + dy[i]][tmpa.z + dz[i]] == 'E') {
						if (visit[tmpa.x + dx[i]][tmpa.y + dy[i]][tmpa.z + dz[i]] == false) {
							tmparea.x = tmpa.x + dx[i]; tmparea.y = tmpa.y + dy[i]; tmparea.z = tmpa.z + dz[i];
							visit[tmparea.x][tmparea.y][tmparea.z] = true;
							tmpq.push(tmparea);
						}
					}
				}
			}
		}
		seconds++;
	}
}
void resetqueue() {
	while (1) {
		if (tmpq.empty()) return;
		tmpq.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		resetqueue();
		if(inputs()) break;
		seconds = 0;
		bfs(S);
	}
	return 0;
}