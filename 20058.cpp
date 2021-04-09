#include<bits/stdc++.h>
using namespace std;

int n, q;
int iceground[65][65];
int tmpground[65][65];
bool visited[65][65];
vector<int> order;
int totalsize;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> tmpq;

bool boundcheck(int x, int y) {
	if (x >= 0 && x < totalsize && y >= 0 && y < totalsize) return true;
	else return false;
}

bool checkmelting(int x, int y) {
	int tmpc = 0;
	for (int i = 0; i < 4; i++) {
		if (boundcheck(x + dx[i], y + dy[i]) && iceground[x + dx[i]][y + dy[i]] > 0) { // 얼음이 있으면
			tmpc++;
		}
	}
	return tmpc >= 3;
}

int makesize(int n) {
	int tsize = 1;
	for (int i = 0; i < n; i++) {
		tsize *= 2;
	}
	return tsize;
}
void inputs() {
	cin >> n >> q;
	totalsize = makesize(n);
	for (int i = 0; i < totalsize; i++) {
		for (int j = 0; j < totalsize; j++) {
			cin >> iceground[i][j];
		}
	}
	int tmp;
	for (int i = 0; i < q; i++) {
		cin >> tmp; order.emplace_back(tmp);
	}
}
int bfs(int sx,int sy) {
	tmpq.push({ sx,sy });
	visited[sx][sy] = true;
	int rsize = 1;
	while (1) {
		if (tmpq.empty()) break;
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first; 
			int nexty = tmpq.front().second;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty) && iceground[tx][ty] != 0 && !visited[tx][ty]) {
					tmpq.push({ tx,ty });
					visited[tx][ty] = true;
					rsize++;
				}
			}
		}
	}
	return rsize;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	for (int i = 0; i < q; i++) {
		int squaresize = makesize(order[i]);
		for (int j = 0; j < totalsize; j += squaresize) {
			for (int k = 0; k < totalsize; k += squaresize) {
				for (int a = 0; a < squaresize; a++) {
					for (int b = 0; b < squaresize; b++) {
						tmpground[j + b][k + a] = iceground[j + squaresize - 1 - a][k + b];
					}
				}
			}
		}
		for (int j = 0; j < totalsize; j++) {
			for (int k = 0; k < totalsize; k++) {
				iceground[j][k] = tmpground[j][k];
			}
		}
		for (int j = 0; j < totalsize; j++) { //얼음 녹이기
			for (int k = 0; k < totalsize; k++) {
				if (iceground[j][k]>0 && !checkmelting(j, k)) tmpground[j][k]--;
			}
		}
		for (int j = 0; j < totalsize; j++) {
			for (int k = 0; k < totalsize; k++) {
				iceground[j][k] = tmpground[j][k];
			}
		}
	}

	int resultsum = 0;
	for (int i = 0; i < totalsize; i++) { //남은 얼음 총량
		for (int j = 0; j < totalsize; j++) {
			resultsum += iceground[i][j];
		}
	}
	cout << resultsum<<"\n";
	int resultmax = 0;
	for (int i = 0; i < totalsize; i++) {
		for (int j = 0; j < totalsize; j++) {
			if (iceground[i][j] != 0 && visited[i][j] == false) {
				resultmax=max(resultmax,bfs(i, j)); }
		}
	}
	cout << resultmax << "\n";
	
	return 0;
}