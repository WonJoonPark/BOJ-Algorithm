#include<bits/stdc++.h>
using namespace std;

char ground[51][51];
bool visited[51][51];
int n, m;
vector<pair<int, int>> larr;
queue<pair<int, int>> tmpq;
int resultsecond=0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void inputs() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			if (ground[i][j] == 'L') {
				larr.push_back({ i,j });
			}
		}
	}
}
void visitclear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}
bool boundcheck(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}

void bfs(int x, int y) {
	visitclear();
	tmpq.push({ x,y });
	visited[x][y] = true;
	int second = 0;
	while (1) {
		if (tmpq.empty()) {
			if (second > resultsecond) { resultsecond = second; }
			break;
		}
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first;
			int nexty = tmpq.front().second;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty) && visited[tx][ty] == false && ground[tx][ty] == 'L') {
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
	inputs();
	for (int i = 0; i < larr.size(); i++) {
		bfs(larr[i].first,larr[i].second);
	}
	cout << resultsecond-1 << "\n";

	return 0;
}