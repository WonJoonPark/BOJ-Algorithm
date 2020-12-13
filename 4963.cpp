#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int xarr[8] = { 1,1,1,-1,-1,-1,0,0 };
int yarr[8] = { 0,-1,1,0,-1,1,1,-1 };
int tmap[51][51];
bool visit[51][51];
int w, h;

void setmapvisit0() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			tmap[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}
void inputs() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> tmap[i][j];
		}
	}
}
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 8; i++) {
		if (x + xarr[i] >= 0 && x + xarr[i] < h &&y + yarr[i] >= 0 && y + yarr[i] < w) {
			if (tmap[x+xarr[i]][y+yarr[i]]==1 && visit[x + xarr[i]][y + yarr[i]] == false) {
				dfs(x + xarr[i], y + yarr[i]);
			}
		}
	}
}

int main() {
	while (1) {
		int islandcount = 0;
		setmapvisit0();
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		inputs();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (tmap[i][j]==1 && visit[i][j] == false) {
					islandcount++; dfs(i, j);
				}
			}
		}
		cout << islandcount << "\n";
	}
	return 0;
}