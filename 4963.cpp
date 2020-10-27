#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int xarr[8] = { 1,1,1,-1,-1-1,0,0 };
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
void inputsetting() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> tmap[i][j];
		}
	}
}
void dfs(int a,int b) {
	visit[a][b] = 1;
	for (int i = 0; i < 8; i++) {
		if ((a + xarr[i]) >= 0 && ((a + xarr[i]) < h)&&(b + yarr[i]) >= 0 && (b + yarr[i]) < w) {
			if (tmap[a + xarr[i]][b + yarr[i]] == 1 && visit[a + xarr[i]][b + yarr[i]] == 0) {
				dfs(a + xarr[i], b + yarr[i]);
			}
		}
	}
}
int main() {
	while (1) {
		setmapvisit0();
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		inputsetting();
		int islandcount = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visit[i][j] == 0 && tmap[i][j] == 1) {
					dfs(i,j);
					islandcount++;
				}
			}
		}
		cout << islandcount<<'\n';
	}
	return 0;
}