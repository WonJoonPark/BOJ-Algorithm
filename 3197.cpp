#include<bits/stdc++.h>
using namespace std;

char rc[1501][1501];
bool visited[1501][1501];
vector<pair<int, int>> swanarea;
queue<pair<int, int>> waterarea;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int r, c;

bool boundcheck(int x, int y) {
	if (x >= 1 && x <= r && y >= 1 && y <= c) return true;
	else return false;
}

void inputs() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> rc[i][j];
			if (rc[i][j] == 'L') { swanarea.push_back({ i,j }); } //백조 두마리
			if (rc[i][j] == 'L' || rc[i][j] == '.') waterarea.push({ i,j }); //물 or 백조 (얼음을 녹이는 지역)
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	queue<pair<int, int>> tmpq;
	tmpq.push(swanarea[0]);
	visited[swanarea[0].first][swanarea[0].second] = true;

	int second = 0;
	while (1) {
		queue<pair<int, int>> nextsearch; //백조가 다음에 탐색할 위치를 담자
		while (!tmpq.empty()) {
			int nextx = tmpq.front().first; int nexty = tmpq.front().second;
			tmpq.pop();
			//만남 조건
			if (nextx == swanarea[1].first && nexty == swanarea[1].second) {
				cout << second; return 0;
			}
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i];
				int ty = nexty + dy[i];
				if (boundcheck(tx, ty)&&visited[tx][ty]==false) {
					visited[tx][ty] = true;
					if (rc[tx][ty] == 'X') {
						nextsearch.push({ tx, ty });
						continue; 
					}
					tmpq.push({ tx,ty });
				}
			}
		}

		// 다음단계에서 탐색할 위치
		tmpq = nextsearch;
	    //이제 이만큼에 백조가 위치
		int wqsize = waterarea.size();
		while (wqsize--) {
			int nextx = waterarea.front().first;
			int nexty = waterarea.front().second;
			waterarea.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i];
				int ty = nexty + dy[i];
				if (boundcheck(tx, ty)) {
					if (rc[tx][ty] == 'X') {
						rc[tx][ty] = '.'; //녹음
						waterarea.push({ tx,ty });
					}
				}
			}
		}
		second++;
	}
	return 0;
}