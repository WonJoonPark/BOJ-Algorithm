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
	for (int i = 0; i < n; i++) { //0�� ��ĭ, 1�� ��, 2�� ���̷��� ������ġ
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
		visitclear(); //�湮�迭 �ʱ�ȭ
		qclear(); //ť �� ���� �� ���� �ʱ�ȭ
		vtoq(); //���Ϳ��� ť�� �ű�� (�湮üũ��)
		tmpzero = totalzero; // ���̷����� ��� ���ĵǾ�����Ȯ��
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