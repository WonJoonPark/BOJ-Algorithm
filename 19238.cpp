#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int ground[21][21];
bool visit[21][21];
int n, m, fuel;
int texix, texiy;
int tmpx, tmpy;
//북서동남
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
queue<pair<int, int>> tmpq;
bool fail = false;
int nextx, nexty;
int distances;
int ssize;
vector<pair<int,int>> tmpvector;

struct client {
	int sx, sy, ex, ey;
};
vector<client> clients;
bool compare(pair<int,int> &lhs, pair<int,int> &rhs) {
	if (lhs.first < rhs.first) return true;
	else if (lhs.first == rhs.first) {
		if (lhs.second < rhs.second) return true;
		else return false;
	}
	else return false;
}
void inputs() {
	cin >> n >> m>>fuel;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ground[i][j];
		}
	}
	cin >> texix >> texiy;
	texix -= 1; texiy -= 1;
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ground[x1-1][y1-1] = 2;
		clients.push_back({ x1-1,y1-1,x2-1,y2-1 });
	}
}
void qclear() {
	while (!tmpq.empty()) {
		tmpq.pop();
	}
}
void visitclear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}
bool boundcheck(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	else return true;
}

void bfs() {
	distances = 0;
	bool checking = false;
	while (1) {
		if (tmpq.empty()) { fail = true; return; }
		 ssize = tmpq.size();
		while (ssize--) {
			 nextx = tmpq.front().first;
			 nexty = tmpq.front().second;
			 tmpq.pop();
			if (ground[nextx][nexty] == 2) { //손님을 찾으면 break;
				tmpvector.clear();
				tmpvector.push_back({ nextx,nexty });
				while (ssize--) { //  !!!!!! (!tmpq.empty()) 하면 틀림
					int ttx = tmpq.front().first;
					int tty = tmpq.front().second;
					tmpq.pop();
					if (ground[ttx][tty] == 2) {
						tmpvector.push_back({ ttx,tty });
					}
				}
				sort(tmpvector.begin(), tmpvector.end(), compare);
				nextx = tmpvector[0].first;
				nexty = tmpvector[0].second;
				checking = true; break;
			}
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty) && visit[tx][ty] == false && ground[tx][ty] != 1) {
					visit[tx][ty] = true;
					tmpq.push({ tx,ty });
				}
			}
		}
		if (checking == true) { break; }
		distances++;
	}
	fuel -= distances; //이동한만큼 연료소모
	if (fuel < 0) { fail = true; return; }
	ground[nextx][nexty] = 0; // 손님을 태웠슴
	int clientindex = -1;
	for (int i = 0; i < clients.size(); i++) {
		if (clients[i].sx == nextx && clients[i].sy == nexty) {
			clientindex = i; break; //손님의 목적지를 알기위해
		}
	}
	visitclear();
	qclear();
	tmpq.push({ nextx,nexty }); //출발지점
	ground[nextx][nexty] = 0; //손님을 태움
	visit[nextx][nexty] = true;

	distances = 0;
	checking = false;
	while (1) {
		if (tmpq.empty()) { fail = true; return; }
		ssize = tmpq.size();
		while (ssize--) {
			nextx = tmpq.front().first;
			nexty = tmpq.front().second;
			tmpq.pop();
			if (nextx==clients[clientindex].ex &&nexty==clients[clientindex].ey) { //손님을 찾으면 break;
				checking = true; break;
			}
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty) && visit[tx][ty] == false && ground[tx][ty] != 1) {
					visit[tx][ty] = true;
					tmpq.push({ tx,ty });
				}
			}
		}
		if (checking == true) {break; }
		distances++;
	}
	fuel -= distances;
	if (fuel < 0) {
		fail = true; return;
	}
	texix = nextx; texiy = nexty; //택시 위치 변경
	fuel += (2 * distances);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	inputs();
	for (int i = 0; i < m; i++) {
		qclear();
		visitclear();
		tmpq.push({ texix,texiy });
		visit[texix][texiy] = true;
		bfs();//손님찾자
		if (fail == true) { cout << -1 << "\n"; return 0; }
	}

	cout << fuel << "\n";
	return 0;
}