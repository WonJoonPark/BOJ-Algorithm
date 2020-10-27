#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int map[101][101]; //사과가 있는지 여부를 알기 위해
int jirung[101][101];//지렁이의 현재위치
int directionjirung[101][101]; //꼬리를 위한 지렁이가 그 좌표에서 보고있던 방향을 기록
int N;
int K;
int dx[4] = {0,1,0,-1}; //동남서북
int dy[4] = {1,0,-1,0};
int direction=0; //지렁이가 보고있는 방향(처음엔 동쪽 보고있다.)
int gamesecond;
int L;
int headx, heady,tailx,taily;
queue<pair<int, char>> dq;

void setapple() {
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		map[x][y] = 1; //사과가 존재하는 위치
	}
}
void setqueue() {
	pair<int, char> tmppair;
	for (int i = 0; i < L; i++) {
		cin >> tmppair.first >> tmppair.second;
		dq.push(tmppair);
	}
}

int main() {
	cin >> N >> K;
	setapple();
	cin >> L;
	setqueue();
	headx = 1; heady = 1; tailx = 1; taily = 1;
	jirung[1][1] = 1;
	while (1) {
		while (1) {
			if (dq.empty() == false && gamesecond == dq.front().first) {
				if (dq.front().second == 'L') { //왼쪽 회전
					direction = (direction + 3) % 4;
				}
				else {//오른쪽 회전
					direction = (direction + 1) % 4;
				}
				dq.pop();
			}
			else break;
		}
		gamesecond++;

		directionjirung[headx][heady] = direction; //꼬리를위해 방향을 기록먼저 !
		headx += dx[direction]; heady += dy[direction];
		if (headx <= 0 || heady <= 0 || headx > N || heady > N || jirung[headx][heady] == 1) {  break; } //종료조건 (map의 범위 1~N)

		jirung[headx][heady] = 1; //머리가 도착한 곳 표시
		if (map[headx][heady] == 1) { //사과가 있다면
			map[headx][heady] = 0; 
		}
		else {
			jirung[tailx][taily] = 0; //사과가 없다면 꼬리좌표 지워짐
			int tmptailx = tailx;
			int tmptaily = taily;
			tailx = tailx + dx[directionjirung[tmptailx][tmptaily]]; //꼬리의 위치 업데이트 (머리가 지나갈때 간 방향으로 업데이트)
			taily = taily + dy[directionjirung[tmptailx][tmptaily]];
		}
	}
	cout << gamesecond << "\n";
			return 0;
}
