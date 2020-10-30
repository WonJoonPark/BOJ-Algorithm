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
			//아직 먹이가 있다.
		//먹이에서 상어까지 길이 있는지 확인해야 한다.
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
				sharksize++; //상어 크기 1 증가
				sizecount = 0;
			}
			sea[tmpf[0].x][tmpf[0].y] = 9; //상어가 물고기 자리로
			sea[sx][sy] = 0; sx = tmpf[0].x; sy = tmpf[0].y; 
			tmpf.clear(); //벡터 비워주기
			tmpsize = tmpq.size();
			for (int i = 0; i < tmpsize; i++) { //큐 비워주기
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
					if (sea[x + dx[i]][y + dy[i]] == 0 || sea[x + dx[i]][y + dy[i]] == sharksize) { //먹을건 없고 지나가기만 (큐에)
						xy txy; txy.x =x+dx[i]; txy.y = y + dy[i];
						tmpq.push(txy);
					}
					else if (sea[x + dx[i]][y + dy[i]] < sharksize) { //먹어버려 (벡터에)
						fish tfish; tfish.x = x + dx[i]; tfish.y = y + dy[i]; tfish.fsize = sea[x + dx[i]][y + dy[i]];
						tmpf.push_back(tfish);
					}
					else {
						visited[x + dx[i]][y + dy[i]] = true; //못지나감
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
		xy tmp; tmp.x = sx; tmp.y = sy; //상어의 위치
		tmpq.push(tmp);
		initvisited();
		searchfish(); //여기에 들어간다는 건 무조건 먹을 먹이는 있다는 것
	}
	cout << second;

	return 0;
}