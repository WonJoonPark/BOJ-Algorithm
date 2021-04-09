#include<bits/stdc++.h>
using namespace std;

//.Àº ºóÄ­, #Àº ¿ïÅ¸¸®, o´Â ¾ç, v´Â ´Á´ë
char madang[251][251];
bool visited[251][251];
int r, c;
int tmplamb;
int tmpwolf;
int totallamb = 0;
int totalwolf = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> tmpq;

bool boundcheck(int x, int y) {
	if (x >= 0 && x < r && y >= 0 && y < c) return true;
	else return false;
}

void inputs() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> madang[i][j];
			if (madang[i][j] == 'o') totallamb++;
			if (madang[i][j] == 'v') totalwolf++;
		}
	}
}

void bfs() {
	while (!tmpq.empty()) {
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first;
			int nexty = tmpq.front().second;
			if (madang[nextx][nexty] == 'o') tmplamb++;
			if (madang[nextx][nexty] == 'v') tmpwolf++;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty) && visited[tx][ty]==false && madang[tx][ty] !='#') {
					visited[tx][ty] = true;
					tmpq.push({ tx,ty });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (madang[i][j] != '#' && visited[i][j]==false) {
				tmplamb = 0;
				tmpwolf = 0;
				visited[i][j] = true;
				tmpq.push({ i,j });
				bfs();
				if (tmplamb > tmpwolf) { totalwolf -= tmpwolf; }
				else { totallamb -= tmplamb; }
			}
		}
	}
	cout << totallamb << " " << totalwolf << "\n";

	return 0;
}