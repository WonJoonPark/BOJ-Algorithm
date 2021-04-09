#include<bits/stdc++.h>
using namespace std;

pair<int, int> ground[22][22]; //first =선거구, second= 구역별 인원
int n;
queue<pair<int, int>> tmpq;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int numcount[6];
int resultmin = 20000;

void inputs() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ground[i][j].second;
		}
	}
}
bool boundcheck(int i, int j, int a, int b) {
	return ((i + a + b) <= n && (j - a >= 1) && (j + b <= n));
}
void initground() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ground[i][j].first = 0;
		}
	}
}
bool bfsboundcheck(int x, int y) {
	return (x <= n&& x >= 1 && y >= 1 && y <= n);
}
void bfs(int x, int y) {
	ground[x][y].first = 5;
	tmpq.push({ x,y });
	while (!tmpq.empty()) {
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first;
			int nexty = tmpq.front().second;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i];
				int ty = nexty + dy[i];
				if (bfsboundcheck(tx, ty) && ground[tx][ty].first != 5) {
					tmpq.push({ tx,ty });
					ground[tx][ty].first = 5;
				}
			}
		}
	}
}

void makeoutside(int x,int y,int d1,int d2) {
	// 일단 경계선
	for (int i = 0; i <= d1; i++) {
		ground[x + i][y - i].first = 5;
		ground[x + d2 + i][y + d2 - i].first = 5;
	}
	for (int j = 0; j <= d2; j++) {
		ground[x + j][y + j].first = 5;
		ground[x + d1 + j][y - d1 + j].first = 5;
	}
	//bfs 돌리고 + 4면이 모두 5인 곳은 따로 체크
	if (ground[x + 1][y].first == 0) bfs(x + 1, y);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int tmpcount = 0;
			for (int k = 0; k < 4; k++) {
				if (ground[i + dx[k]][j + dy[k]].first == 5) {
					tmpcount++;
				}
				else break;
			}
			if (ground[i][j].first != 5 && tmpcount == 4) { ground[i][j].first = 5; }
		}
	}
	for (int i = 1; i < x + d1; i++) { //1번 선거구
		for (int j = 1; j <= y; j++) {
			if (ground[i][j].first == 5) continue;
			ground[i][j].first = 1;
		}
	}
	for (int i = 1; i <= x + d2; i++) { //2번 선거구
		for (int j = y+1; j <= n; j++) {
			if (ground[i][j].first == 5) continue;
			ground[i][j].first = 2;
		}
	}
	for (int i = x + d1; i <= n; i++) { //3번 선거구
		for (int j = 1; j < y - d1 + d2;j++) {
			if (ground[i][j].first == 5) continue;
			ground[i][j].first = 3;
		}
	}
	for (int i = x + d2+1; i <= n; i++) {
		for (int j = y - d1 + d2; j <= n; j++) {
			if (ground[i][j].first == 5) continue;
			ground[i][j].first = 4;
		}
	}
}
void numcheckreset() {
	for (int i = 1; i <= 5; i++) {
		numcount[i] = 0;
	}
}
void getnumcount() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			numcount[ground[i][j].first] += ground[i][j].second;
		}
	}
}
bool emptycheck() {
	for (int i = 1; i <= 5; i++) {
		if (numcount[i] == 0) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	inputs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int a = 1; a <= n; a++) {
				for (int b = 1; b <= n; b++) {
					if (boundcheck(i, j, a, b)) { //범위를 만족할 때만
						initground();
						makeoutside(i,j,a,b);
						numcheckreset();
						getnumcount();
						if (emptycheck()) continue; //적어도 하나의 구역 포함
						sort(numcount + 1, numcount + 6);
						resultmin = min(resultmin, numcount[5] - numcount[1]);
					}
				}
			}
		}
	}
	cout << resultmin;
	return 0;
}