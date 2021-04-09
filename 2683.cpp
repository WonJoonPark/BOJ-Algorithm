#include<bits/stdc++.h>
using namespace std;

int n, m;
//1�� ġ�� , 0 �� ��ĭ , 2�� �ǿܰ���
int ground[101][101];
bool visited[101][101];
int cheesecount = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct cheese {
	int cx, cy;
	bool check;
};
vector<pair<int, int>> sideindex;
queue<pair<int, int>> tmpq;
vector<cheese> tmpv;

void inputs() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			if (ground[i][j] == 1) {
				cheesecount++; tmpv.push_back({ i,j,false });
			}
		}
	}
	sideindex.push_back({ 0, 0 }); sideindex.push_back({ n - 1,0 }); //
	sideindex.push_back({ 0,m - 1 }); sideindex.push_back({ n - 1,m - 1 });
}
bool boundcheck(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}
void makeoutside() {
	while (!tmpq.empty()) {
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
					ground[tx][ty] = 2;
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	int second = 0;		
	//�ǿܰ��� ���ϱ�
	for (int i = 0; i < 4; i++) {
		visited[sideindex[i].first][sideindex[i].second] = true;
		ground[sideindex[i].first][sideindex[i].second] = 2;
		tmpq.push(sideindex[i]);
	}
	
	makeoutside(); // ó�� �ܺΰ��� ���ϱ�

	while (1) {
		if (cheesecount == 0) break;
		for (int i = 0; i < tmpv.size(); i++) {
			if (tmpv[i].check == true) continue; //���ÿ� �Ͼ�� ��
			int vsize = 0;
			for (int j = 0; j < 4; j++) { //4���� Ž��
				if (ground[tmpv[i].cx + dx[j]][tmpv[i].cy + dy[j]] == 2) {
					vsize++;
				}
				if (vsize >= 2) {
					cheesecount--;
					visited[tmpv[i].cx + dx[j]][tmpv[i].cy + dy[j]] = true;
					tmpv[i].check = true; //����� ������
					tmpq.push({ tmpv[i].cx + dx[j],tmpv[i].cy + dy[j] });
					break;
				}
			}
		}
		for (int i = 0; i < tmpv.size(); i++) { //ġ� ������
			if (tmpv[i].check == true) {
				ground[tmpv[i].cx][tmpv[i].cy] = 2;
			}
		}
		makeoutside(); //������ ġ��� ���� �ǳ����⿡�� �ܺΰ��Ⱑ �Ǵ� �༮�� üũ
		second++;
	}
	cout << second;
	return 0;
}