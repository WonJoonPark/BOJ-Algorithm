#include<bits/stdc++.h>
using namespace std;

int n, m;
//0 ��ĭ 1 �� 2 ���̷����� ���� �� �ִ� �� (���̷����� ���� �� �ִ� ��ĭ!)
int ground[51][51];
bool visited[51][51];
int emptygroundcount = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> tmp2v; //���̷����� ���� �� �ִ� ��ġ�� ���� ����
vector<pair<int, int>> tmpv; //������ ���� ����
bool suc;//�ѹ��̶� ���� ���ߴ� ���� üũ
queue<pair<int, int>> tmpq;
int minresult = 5000;


void inputs() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ground[i][j];
			if (ground[i][j] == 0 || ground[i][j] == 2) {
				emptygroundcount++;
				if (ground[i][j] == 2) tmp2v.push_back({ i,j });
			}
		}
	}
	emptygroundcount -= m; // ���̷����� �ɾ���ĭ�� ����
}
void visitedclear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}
void tmpqclear() {
	while (!tmpq.empty()) { tmpq.pop(); }
}
void vtoq() {
	for (int i = 0; i < tmpv.size(); i++) {
		tmpq.push({ tmpv[i].first, tmpv[i].second });
		visited[tmpv[i].first][tmpv[i].second] = true;
	}
}
bool boundcheck(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	else return false;
}
void bfs() {
	int second = 0;
	int fillcount = 0;
	while (1) {
		if (fillcount >= emptygroundcount) { //�� ������
			if (second < minresult) { minresult = second; }
			suc = true; return;
		}
		if (tmpq.empty()) { return; } //�� ������ ��Ʈ�� �� ���� ���
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first;
			int nexty = tmpq.front().second;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (boundcheck(tx, ty) && visited[tx][ty] == false && ground[tx][ty] != 1) {
					visited[tx][ty] = true;
					tmpq.push({ tx,ty });
					fillcount++;
				}
			}
		}
		second++;
	}
}
void makecase(int cnt,int index) {
	if (cnt == m) {
		tmpqclear();
		visitedclear();
		vtoq(); //���Ϳ� ��� ���� ť�� visitüũ ����
		bfs();
		return;
	}
	for (int i = index; i < tmp2v.size(); i++) {
		tmpv.push_back({ tmp2v[i].first,tmp2v[i].second });
		makecase(cnt + 1, i + 1);
		tmpv.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	makecase(0,0); //m���� ������ ����
	if (suc == false) {
		cout << -1 << "\n";
	}
	else cout << minresult << "\n";
	return 0;
}