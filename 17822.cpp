#include<bits/stdc++.h>
using namespace std;

int N, M, T; // 반지름, 원판당 수, T번 회전시킨다.
int circle[51][51]; // 몇번째 원/ 몇번째 수
bool visited[51][51]; //bfs를 위한 
queue<pair<int, int>> tmpq;
int xi, di, ki;
int xdk[51][3];
bool checkexist = false;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
double tmpsum, tmpn;
bool neighbor = false;

//번호가 xi의 배수인 원판을 di방향(0-시계,1-반시계) ki칸 만큼 회전
void inputs() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> circle[i][j];
		}
	}
	for (int i = 1; i <= T; i++) {
		cin >> xdk[i][0] >> xdk[i][1] >> xdk[i][2];
	}
}
bool boundcheck(int x) {
	return (x >= 1 && x <= N); //원의 범위
}
void rotate(int r) {
	for (int k = 0; k < xdk[r][2]; k++) {
		for (int i = 1; i <= N; i++) {
			if (i % xdk[r][0] != 0) continue; // xi의 배수인 원판만 회전

			int tmpnum;
			if (xdk[r][1] == 0) { // 시계방향
				tmpnum = circle[i][M];
				for (int j = M; j >= 2; j--) {
					circle[i][j] = circle[i][j - 1];
				}
				circle[i][1] = tmpnum;
			}
			else { //반시계방향
				tmpnum = circle[i][1];
				for (int j = 1; j < M; j++) {
					circle[i][j] = circle[i][j + 1];
				}
				circle[i][M] = tmpnum;
			}
		}
	}
}
void initvisit() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = false;
		}
	}
}
void bfs(int x, int y) {
	visited[x][y] = true;
	tmpq.push({x,y});
	while (!tmpq.empty()) {
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first;
			int nexty = tmpq.front().second;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (ty == 0) ty = M; //circular
				if (ty == M + 1) ty = 1;
				
				if (boundcheck(tx) && !visited[tx][ty] && circle[tx][ty] == circle[x][y]) {
					tmpq.push({ tx,ty });
					visited[tx][ty] = true;
					neighbor = true;
					circle[tx][ty] = 0; //지우기
					checkexist = true;
				}
			}
		}
	}
	if (neighbor == true) {
		circle[x][y] = 0; 
	} //하나라도 존재하면 여기도 지우기 (시작점)
}
void getsum() {
	tmpsum = 0; tmpn = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (circle[i][j] != 0) {
				tmpsum += circle[i][j];
				tmpn++;
			}
		}
	}
}
/*void watchcircle() {
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << circle[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs(); //원판 셋팅
	for(int a=1;a<=T;a++) {
		rotate(a); //회전
		getsum(); // 전체 존재의 수와 그들의 합
		if (tmpn == 0) { cout << 0; return 0; }
		initvisit();
		checkexist = false; // 인접하면서 같은 수가 하나라도 존재하는지 체크
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				neighbor = false; //이웃이 하나라도 있으면 삭제되고 아니면 지워지지 않음
				if (circle[i][j] != 0 && visited[i][j] == false) {
					bfs(i, j);
				} // 인접
			}
		}
		if (checkexist == false) { //인접한 수가 존재하지 않을 때
			double avg = tmpsum / tmpn;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (circle[i][j] == 0) continue;

					if (circle[i][j] > avg) {
						circle[i][j]--; continue;
					}
					else if (circle[i][j] < avg) {
						circle[i][j]++; continue;
					}
				}
			}
		}
	}
	int resultsum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			resultsum += circle[i][j];
		}
	}
	cout << resultsum;
	return 0;
}