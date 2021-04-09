#include<bits/stdc++.h>
using namespace std;

bool visited[301][301];
int l, nx, ny, ox, oy;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
queue<pair<int, int>> tmpq;

bool boundcheck(int x, int y) {
	return (x >= 0 && x < l&& y >= 0 && y < l);
}

void init() {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			visited[i][j] = false;
		}
	}
	while (!tmpq.empty()) tmpq.pop();
}
void bfs(int xx, int yy) {
	tmpq.push({ xx,yy });
	visited[xx][yy] = true;
	int second = 0;
	while (1) {
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first;
			int nexty = tmpq.front().second;
			if (nextx == ox && nexty == oy) { cout << second << "\n"; return; }
			tmpq.pop();
			for (int i = 0; i < 8; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty) && !visited[tx][ty]) {
					visited[tx][ty] = true;
					tmpq.push({ tx,ty });
				}
			}
		}
		second++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> l >> nx >> ny >> ox >> oy;
		init();
		bfs(nx, ny);
	}
	return 0;
}