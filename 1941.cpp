#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/1941


vector<pair<int, int>> tmpv;
queue<pair<int, int>> tmpq;
vector<pair<int, int>> totalxy;


char classroom[5][5];
bool visited[5][5];
bool copymap[5][5];
int resultcount;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void inputs() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> classroom[i][j];
			totalxy.push_back({ i,j });
		}
	}
}
bool boundcheck(int x, int y) {
	if (x >= 0 && x < 5 && y >= 0 && y < 5) return true;
	else return false;
}
void makecopymap() { // 5*5 이므로 메모리가 크지않고 빠르게 조회 가능하게 함
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			copymap[i][j] = false;
		}
	}
	for (int i = 0; i < 7; i++) {
		copymap[tmpv[i].first][tmpv[i].second] = true;
	}
}

void visitclear() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visited[i][j] = false;
		}
	}
}

bool bfs() {
	tmpq.push({ tmpv[0].first,tmpv[0].second });
	visited[tmpv[0].first][tmpv[0].second] = true;
	int scount = 0; int ycount = 0;

	if (classroom[tmpv[0].first][tmpv[0].second] == 'Y') ycount++;
	else scount++;

	while (1) {
		if ((scount + ycount) == 7) {
			return (scount >= 4);
		}
		if (tmpq.empty()) { return false; }
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first; int nexty = tmpq.front().second;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty) && visited[tx][ty] == false && copymap[tx][ty] == true) {
					tmpq.push({ tx,ty });
					visited[tx][ty] = true;
					if (classroom[tx][ty] == 'S') scount++;
					else ycount++;
				}
			}

		}
	}
}
void qclear() {
	while (!tmpq.empty()) {
		tmpq.pop();
	}
}

void makecase(int cnt, int iindex) {
	if (cnt == 7) {
		makecopymap();
		visitclear();
		qclear();
		if (bfs()) { resultcount++; }
		return;
	}
	for (int i = iindex; i < totalxy.size(); i++) {
		tmpv.push_back({ totalxy[i].first,totalxy[i].second });
		makecase(cnt + 1, i + 1);
		tmpv.pop_back();
	}
	/*
	for (int i = iindex; i < 5; i++) {
		for (int j = jindex; j < 5; j++) {
			tmpv.push_back({ i, j });
			if (j == 4) {
				makecase(cnt + 1, i + 1, 0);
			}
			else {
				makecase(cnt + 1, i, j + 1);
			}
			tmpv.pop_back();
		}
	}*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	makecase(0,0);
	cout << resultcount;
	return 0;
}