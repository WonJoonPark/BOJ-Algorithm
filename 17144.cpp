#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int R, C, T;
int roominfo[51][51];
int copyroom[51][51];
int dx[4] = { 0,0,1,-1 }; //동서남북
int dy[4] = { 1,-1,0,0 };
int reverseclockx[4] = { 0,-1,0,1 }; //반시계
int reverseclocky[4] = { 1,0,-1,0 };
int clockx[4] = { 0,1,0,-1 }; //시계
int clocky[4] = { 1,0,-1,0 };
int dust;
vector<pair<int, int>> airfresh;

void inputs() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> roominfo[i][j];
			if (roominfo[i][j] == -1) {
				pair<int, int> tmpp; tmpp.first = i; tmpp.second = j;
				airfresh.push_back(tmpp);
			}
		}
	}
}

void dustmove() { //먼지이동
	for (int a = 0; a < R; a++) {
		for (int b = 0; b < C; b++) {
			if (roominfo[a][b] == -1) continue;
			int movedust = 0;
			for (int i = 0; i < 4; i++) {
				if (a + dx[i] < 0 || a + dx[i] >= R || b + dy[i] < 0 || b + dy[i] >= C) continue;
				if (roominfo[a + dx[i]][b + dy[i]] == -1) continue;
				roominfo[a + dx[i]][b+dy[i]] += copyroom[a][b] / 5;
				movedust++;
			}
			roominfo[a][b] -= (copyroom[a][b] / 5)*movedust;
		}
	}

}

void airclean() { //순환(공기청정)
	int dir = 0;
	int tmp,tmp2;
	int nextX = airfresh[0].first + reverseclockx[dir]; int nextY = airfresh[0].second + reverseclocky[dir];
	tmp = roominfo[nextX][nextY];
	roominfo[nextX][nextY] = 0;
	while (1) { //위쪽(반시계)
		if (nextX + reverseclockx[dir] == airfresh[0].first &&nextY + reverseclocky[dir] == airfresh[0].second) break; //공기 청정기를 만남
		if (nextX + reverseclockx[dir] == R || nextX + reverseclockx[dir] == -1 || nextY + reverseclocky[dir] == -1 || nextY + reverseclocky[dir] == C) { dir++; continue; }
		nextX += reverseclockx[dir]; nextY += reverseclocky[dir];
		tmp2 = roominfo[nextX][nextY];
		roominfo[nextX][nextY] = tmp;
		tmp = tmp2;
	}
	             //아래쪽(시계)
	dir = 0;
	nextX = airfresh[1].first + clockx[dir];  nextY = airfresh[1].second + clocky[dir];
	tmp = roominfo[nextX][nextY];
	roominfo[nextX][nextY] = 0;
	while (1) {
		if (nextX + clockx[dir] == airfresh[1].first &&nextY + clocky[dir] == airfresh[1].second) break;//공기 청정기를 만남
		if (nextX + clockx[dir] == R || nextX + clockx[dir] == -1 || nextY + clocky[dir] == -1 || nextY + clocky[dir] == C) { dir++; continue; }
		nextX += clockx[dir]; nextY += clocky[dir];
		tmp2 = roominfo[nextX][nextY];
		roominfo[nextX][nextY] = tmp;
		tmp = tmp2;
	}
}
void getdust() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (roominfo[i][j] > 0) dust += roominfo[i][j];
			}
		}
}
void copymap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			copyroom[i][j] = roominfo[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	for (int i = 0; i < T; i++) {
		copymap();
		dustmove();
		airclean();
	}
	getdust();
	cout << dust << "\n";
	return 0;
}