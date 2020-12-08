#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dx[4] = { -1,0,1,0 }; //북동남서
int dy[4] = { 0,1,0,-1 }; //0,1,2,3
int N, M;
int rx, ry, rd;
int robomap[51][51]; //빈칸은 0, 벽은 1
int cleancount;

void inputs() {
	cin >> N >> M;
	cin >> rx >> ry >> rd;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> robomap[i][j];
		}
	}
}

void cleanroom() {
	while (1) {
		if (robomap[rx][ry] == 0) {
			robomap[rx][ry] = 2; //청소
			cleancount++;
		}
		bool lastcheck = false;
		for (int i = 0; i < 4; i++) {//종료조건 검사
			if (robomap[rx + dx[i]][ry + dy[i]] == 0) { lastcheck = true; break; }
		}
		if (lastcheck == false) {
			if (robomap[rx + dx[(rd + 2) % 4]][ry + dy[(rd + 2) % 4]] == 1) { 
				cout << cleancount << "\n"; break;
			}
			else {
				rx += dx[(rd + 2) % 4]; ry += dy[(rd + 2) % 4];
			}
		}
		else if (lastcheck == true) {
			while (1) {
				if (robomap[rx + dx[(rd + 3) % 4]][ry + dy[(rd + 3) % 4]] == 0) {
					rd = (rd + 3) % 4;
					rx += dx[rd]; ry += dy[rd];
					break;
				}
				else {
					rd = (rd + 3) % 4;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	cleanroom();

	return 0;
}
