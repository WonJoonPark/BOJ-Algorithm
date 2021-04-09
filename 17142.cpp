#include<iostream>
#include<string>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int n, m;
int vground[51][51];
bool visit[51][51];
int minresult = 9999;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> canvirus;
vector<pair<int, int>> tmpvirus;
queue<pair<int, int>> tmpq;
bool suc = false;
int totalzero = 0;
int tmpzero = 0;


void inputs() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) { //0은 빈칸, 1은 벽, 2는 바이러스 가능위치
		for (int j = 0; j < n; j++) {
			cin >> vground[i][j];
			if (vground[i][j] == 2) {
				canvirus.push_back({ i,j });
			}
			if (vground[i][j] == 0) {
				totalzero++;
			}
		}
	}
}
void qclear() {
	while (!tmpq.empty()) {
		tmpq.pop();
	}
}
void vtoq() {
	for (int i = 0; i < tmpvirus.size(); i++) {
		tmpq.push(tmpvirus[i]);
		visit[tmpvirus[i].first][tmpvirus[i].second] = true;
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
	int second=0;
	while (1) {
		if (tmpzero==0|| tmpq.empty()) break;
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first;
			int nexty = tmpq.front().second;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty) && visit[tx][ty] == false && vground[tx][ty]!=1) {
					tmpq.push({ tx,ty });
					visit[tx][ty] = true;
					if (vground[tx][ty] == 0) tmpzero--;
				}
			}
		}
		second++;
	}
	if (tmpzero==0) {
		suc = true;
		if (second < minresult) minresult = second;
	}

}

void makecase(int index,int cnt) {
	if (cnt == m) {
		visitclear(); //방문배열 초기화
		qclear(); //큐 를 먼저 싹 빼줌 초기화
		vtoq(); //벡터에서 큐로 옮기기 (방문체크도)
		tmpzero = totalzero; // 바이러스가 모두 전파되었는지확인
		bfs();
		return;
	}
	for (int i = index; i < canvirus.size(); i++) {
		tmpvirus.push_back(canvirus[i]);
		makecase(i + 1, cnt + 1);
		tmpvirus.pop_back();
	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	makecase(0,0);
	if (suc == true) cout << minresult << "\n";
	else cout << -1 << "\n";
	return 0;
}