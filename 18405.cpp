#include<bits/stdc++.h>
using namespace std;

int ground[201][201];
int s, sx, sy;
int n, k;
struct xx {
	int ti, tj, virusnum;
};
queue<xx> tmpq;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void inputs() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ground[i][j];
			if (ground[i][j] != 0) {
				tmpq.push({ i,j,ground[i][j] });
			}
		}
	}
	cin >> s >> sx >> sy;
}
bool boundcheck(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	else return false;
}
bool compare(xx x1, xx x2) {
	if (x1.virusnum < x2.virusnum) return true;
	else return false;
}
void sortq() {
	vector<xx> tmpv;
	while (!tmpq.empty()) {
		tmpv.push_back(tmpq.front());
		tmpq.pop();
	}
	sort(tmpv.begin(), tmpv.end(), compare);
	for (int i = 0; i < tmpv.size(); i++) {
		tmpq.push(tmpv[i]);
	}
}
void movevirus() {
	int second = 0;
	while (1) {
		if (second == s) {
			if (ground[sx - 1][sy - 1] == 0) { cout << 0 << "\n"; }
			else { cout << ground[sx - 1][sy - 1] << "\n"; }
			return;
		}
		int qsize = tmpq.size();
		sortq(); //** 처음 한번만
		while (qsize--) {
			int nextx = tmpq.front().ti;
			int nexty = tmpq.front().tj;
			int vnum = tmpq.front().virusnum;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty)  && ground[tx][ty] == 0) {
					ground[tx][ty] = vnum;
					tmpq.push({ tx,ty,vnum });
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
	movevirus();
	return 0;
}