#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

char hosu[1501][1501];
bool visit[1501][1501];
bool dfsvisit[1501][1501];
int R, C;
int lx, ly,lx2,ly2;
int days;
int dx[4] = { 0,0,1,-1 }; //동서남북 4방향 탐색
int dy[4] = { 1,-1,0,0 };
queue<pair<int,int>> waterqueue;
pair<int, int> h;
bool check;
vector<pair<int, int>> birds;

void inputs() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> hosu[i][j];
			if (hosu[i][j] == 'L') {
				pair<int, int> tmpp;
				tmpp.first = i; tmpp.second = j;
				birds.push_back(tmpp);
			}
			if (hosu[i][j] == '.') {
				pair<int, int> tmpp;
				tmpp.first = i; tmpp.second = j;
				waterqueue.push(tmpp);
				visit[i][j] = true;
			}
		}
	}
}
void resetvisit() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			dfsvisit[i][j] = false;
		}
	}
}
void dfs(int x,int y){
	if (x == birds[1].first &&y == birds[1].second) { check = true; return; }
	dfsvisit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < R &&y + dy[i] >= 0 && y + dy[i] < C) {
			if (dfsvisit[x + dx[i]][y + dy[i]] == false && (hosu[x+dx[i]][y+dy[i]]=='.'||hosu[x+dx[i]][y+dy[i]]=='L')) {
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}
}
void bfs() {
	while (1) {
		resetvisit();
		dfs(birds[0].first,birds[0].second);
		if (check == true) { cout << days << "\n"; break; }
		int si = waterqueue.size();
		while (si--) { //이게 하루
			pair<int, int> tmpp,tmpp2;
			tmpp.first = waterqueue.front().first;
			tmpp.second = waterqueue.front().second;
			waterqueue.pop();
			for (int i = 0; i < 4; i++) {
				if (tmpp.first + dx[i] >= 0 && tmpp.first + dx[i] < R &&tmpp.second+dy[i] >= 0 && tmpp.second+dy[i] <= C) {
					if (visit[tmpp.first + dx[i]][tmpp.second + dy[i]] == false) {
						if (hosu[tmpp.first + dx[i]][tmpp.second + dy[i]] == 'X') {
							tmpp2.first =tmpp.first+dx[i]; tmpp2.second =tmpp.second+dy[i];
							waterqueue.push(tmpp2);
							hosu[tmpp2.first][tmpp2.second] = '.';
							visit[tmpp2.first][tmpp2.second] = true;
						}
					}
				}
			}
		}
		days++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	bfs();
	return 0;
}