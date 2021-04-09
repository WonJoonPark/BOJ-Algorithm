#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int k, w, h;
int chesspan[200][200];
bool visit[200][200][31]; //k는 0~30
int horsemovex[8] = { -1,-2,-2,-1,1,2,2,1 };
int horsemovey[8] = { -2,-1,1,2,2,1,-1,-2 };
int dx[4] = { 0,0,1,-1 }; //k번을 다 소모했을 경우
int dy[4] = { 1,-1,0,0 };
int s = 0;
int mincount = 99999999;
bool fail = false;
struct xyk {
	int x, y, kn,s;
};
queue<xyk> tmpq;

void inputs() { //1은 장애물
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> chesspan[i][j];
		}
	}
}
bool boundcheck(int x, int y) {
	if (x >= 0 && x < h && y >= 0 && y < w) return true;
	else return false;
}
int bfs() {
	while (1) {
		int qsize = tmpq.size();
		while (qsize--) {
			if (tmpq.empty()) { fail = true; return 0; }
			int nextx = tmpq.front().x;
			int nexty = tmpq.front().y;
			int nextk = tmpq.front().kn;
			int nexts = tmpq.front().s;
			tmpq.pop();
			if (nextx == h - 1 && nexty == w - 1) { 
				return nexts; }
			if (nextk != 0) {
				for (int i = 0; i < 8; i++) {
					int tx = nextx+ horsemovex[i]; int ty =nexty+ horsemovey[i];
					if (boundcheck(tx, ty) && visit[tx][ty][nextk-1] == false && chesspan[tx][ty] != 1) {
						tmpq.push({ tx,ty,nextk - 1,nexts +1 });
						visit[tx][ty][nextk-1] = true;
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				int tx2=nextx +dx[i]; int ty2 =nexty+ dy[i];
				if (boundcheck(tx2, ty2) && visit[tx2][ty2][nextk] == false && chesspan[tx2][ty2] != 1) {
					tmpq.push({ tx2,ty2,nextk,nexts +1 });
					visit[tx2][ty2][nextk] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	tmpq.push({ 0,0,k,0 });
	//출발점은 0,0 도착점은 h-1,w-1
	int r=bfs();
	if (fail == true) { cout << -1 << "\n"; }
	else cout <<r << "\n";


	return 0;
}