#include<bits/stdc++.h>
using namespace std;

char rc[1501][1501];
bool visited[1501][1501];
vector<pair<int, int>> swanarea;
queue<pair<int, int>> waterarea;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int r, c;

bool boundcheck(int x, int y) {
	if (x >= 1 && x <= r && y >= 1 && y <= c) return true;
	else return false;
}

void inputs() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> rc[i][j];
			if (rc[i][j] == 'L') { swanarea.push_back({ i,j }); } //���� �θ���
			if (rc[i][j] == 'L' || rc[i][j] == '.') waterarea.push({ i,j }); //�� or ���� (������ ���̴� ����)
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	queue<pair<int, int>> tmpq;
	tmpq.push(swanarea[0]);
	visited[swanarea[0].first][swanarea[0].second] = true;

	int second = 0;
	while (1) {
		queue<pair<int, int>> nextsearch; //������ ������ Ž���� ��ġ�� ����
		while (!tmpq.empty()) {
			int nextx = tmpq.front().first; int nexty = tmpq.front().second;
			tmpq.pop();
			//���� ����
			if (nextx == swanarea[1].first && nexty == swanarea[1].second) {
				cout << second; return 0;
			}
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i];
				int ty = nexty + dy[i];
				if (boundcheck(tx, ty)&&visited[tx][ty]==false) {
					visited[tx][ty] = true;
					if (rc[tx][ty] == 'X') {
						nextsearch.push({ tx, ty });
						continue; 
					}
					tmpq.push({ tx,ty });
				}
			}
		}

		// �����ܰ迡�� Ž���� ��ġ
		tmpq = nextsearch;
	    //���� �̸�ŭ�� ������ ��ġ
		int wqsize = waterarea.size();
		while (wqsize--) {
			int nextx = waterarea.front().first;
			int nexty = waterarea.front().second;
			waterarea.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i];
				int ty = nexty + dy[i];
				if (boundcheck(tx, ty)) {
					if (rc[tx][ty] == 'X') {
						rc[tx][ty] = '.'; //����
						waterarea.push({ tx,ty });
					}
				}
			}
		}
		second++;
	}
	return 0;
}