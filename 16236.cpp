#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int sea[21][21];
bool visited[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N;
int sx, sy;
int sharksize = 2;
int sizecount = 0;
struct fish { int x, y, fsize; };
struct xy { int x, y; };
queue<xy> tmpq;
vector<fish> tmpf;
int second;
int tmpsize;
int fishcount = 0;


void inputs() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sea[i][j];
			if (sea[i][j] == 9) { sx = i; sy = j; }
			else if (sea[i][j] >= 1 && sea[i][j <= 6]) { fishcount++; }
		}
	}
}
void initvisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}
bool dfs(int x, int y) {
	if (sea[x][y] == 9) { return true; }
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < N&&y + dy[i] >= 0 && y + dy[i] < N&& visited[x + dx[i]][y + dy[i]] == false) {
			if (sea[x + dx[i]][y + dy[i]] <= sharksize) { dfs(x + dx[i], y + dy[i]); }
		}
	}
	return false;
}
bool checksea() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (sea[i][j] != 0 && sea[i][j]!=9 &&sea[i][j]<sharksize) { 
				initvisited();
				if (dfs(i, j) == false) { return true ; }
				return false; }
			//���� ���̰� �ִ�.
		//���̿��� ������ ���� �ִ��� Ȯ���ؾ� �Ѵ�.
		}
	}
	return true;
}

bool cmp(fish a, fish b) {
	if (a.x < b.x) return true;
	else if (a.x == b.x) {
		if (a.y < b.y) return true;
		else return false;
	}
	else return false;
}
void searchfish() {
	while (1) {
		if (tmpf.empty() == false) {
			sort(tmpf.begin(), tmpf.end(), cmp);
			sizecount++;
			if (sizecount==sharksize) {
				sharksize++; //��� ũ�� 1 ����
				sizecount = 0;
			}
			sea[tmpf[0].x][tmpf[0].y] = 9; //�� ����� �ڸ���
			sea[sx][sy] = 0; sx = tmpf[0].x; sy = tmpf[0].y; 
			tmpf.clear(); //���� ����ֱ�
			tmpsize = tmpq.size();
			for (int i = 0; i < tmpsize; i++) { //ť ����ֱ�
				tmpq.pop();
			}
			break;
		}
		bool cc = false;
		tmpsize = tmpq.size();
		for (int a = 0; a < tmpsize; a++) {
			int x = tmpq.front().x; int y = tmpq.front().y;
			tmpq.pop();
			visited[x][y] = true;
			for (int i = 0; i < 4; i++) {
				if (x + dx[i] >= 0 && x + dx[i] < N&&y + dy[i] >= 0 && y + dy[i] < N&& visited[x+dx[i]][y+dy[i]]==false) {
					if (sea[x + dx[i]][y + dy[i]] == 0 || sea[x + dx[i]][y + dy[i]] == sharksize) { //������ ���� �������⸸ (ť��)
						xy txy; txy.x =x+dx[i]; txy.y = y + dy[i];
						tmpq.push(txy);
					}
					else if (sea[x + dx[i]][y + dy[i]] < sharksize) { //�Ծ���� (���Ϳ�)
						fish tfish; tfish.x = x + dx[i]; tfish.y = y + dy[i]; tfish.fsize = sea[x + dx[i]][y + dy[i]];
						tmpf.push_back(tfish);
					}
					else {
						visited[x + dx[i]][y + dy[i]] = true; //��������
						continue;
					}
				}
			}
		}
		second++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	inputs();
	int change = 1;

	while (1) {
		if (checksea()) break;
		xy tmp; tmp.x = sx; tmp.y = sy; //����� ��ġ
		tmpq.push(tmp);
		initvisited();
		searchfish(); //���⿡ ���ٴ� �� ������ ���� ���̴� �ִٴ� ��
	}
	cout << second;

	return 0;
}