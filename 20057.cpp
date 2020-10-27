#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 }; //서남동북
int N;
int sendmap[500][500];
int totalaway = 0;
int sx, sy;
int increasecount = 1;
int direction = 0; //처음엔 서쪽
void inputs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sendmap[i][j];
		}
	}
}

int caculate(int dir, int x, int y, int r, int s) {
	int sendsum = 0;
	int res = s;
	if (dir == 0) { //서
		if (y - 2 * r >= 0) { sendmap[x][y - 2 * r] += sendmap[x][y] * 0.05; }
		else { sendsum += sendmap[x][y] * 0.05; }
		res -= (int)(sendmap[x][y] * 0.05);
		if (x - 1 * r >= 0 && y - 1 * r >= 0) { sendmap[x - 1 * r][y - 1 * r] += sendmap[x][y] * 0.1; }
		else { sendsum += sendmap[x][y] * 0.1; }
		res -= (int)(sendmap[x][y] * 0.1);
		if (x + 1 * r < N&&y - 1 * r >= 0) { sendmap[x + 1 * r][y - 1 * r] += sendmap[x][y] * 0.1; }
		else { sendsum += sendmap[x][y] * 0.1; }
		res -= (int)(sendmap[x][y] * 0.1);
		if (x - 2 * r >= 0) {
			sendmap[x - 2 * r][y] += sendmap[x][y] * 0.02;
			sendmap[x - 1 * r][y] += sendmap[x][y] * 0.07;
		}
		else { sendsum += sendmap[x][y] * 0.02; sendsum += sendmap[x][y] * 0.07; }
		res -= (int)(sendmap[x][y] * 0.02);
		res -= (int)(sendmap[x][y] * 0.07);
		if (x + 2 * r < N) {
			sendmap[x + 2 * r][y] += sendmap[x][y] * 0.02;
			sendmap[x + 1 * r][y] += sendmap[x][y] * 0.07;
		}
		else { sendsum += sendmap[x][y] * 0.02; sendsum += sendmap[x][y] * 0.07; }
		res -= (int)(sendmap[x][y] * 0.02);
		res -= (int)(sendmap[x][y] * 0.07);
		if (x + 1 * r < N && y + 1 * r < N) { sendmap[x + 1 * r][y + 1 * r] += sendmap[x][y] * 0.01; }
		else { sendsum += sendmap[x][y] * 0.01; }
		res -= (int)(sendmap[x][y] * 0.01);
		if (x - 1 * r >= 0 && y + 1 * r >= 0) { sendmap[x - 1 * r][y + 1 * r] += sendmap[x][y] * 0.01; }
		else { sendsum += sendmap[x][y] * 0.01; }
		res -= (int)(sendmap[x][y] * 0.01);
		if (y - 1 * r >= 0) { sendmap[x][y - 1 * r] += res; }
		else { sendsum += res; }
		return sendsum;
	}

		if (dir == 1) { //남
			if (x + 2 * r < N) {
				sendmap[x + 2 * r][y] += sendmap[x][y] * 0.05;
			}
			else { sendsum += sendmap[x][y] * 0.05; }
			res -= (int)(sendmap[x][y] * 0.05);
			if (x + 1 * r < N&&y - 1 * r >= 0) { sendmap[x + 1 * r][y - 1 * r] += sendmap[x][y] * 0.1; }
			else { sendsum += sendmap[x][y] * 0.1; }
			res -= (int)(sendmap[x][y] * 0.1);
			if (x + 1 * r < N && y + 1 * r < N) { sendmap[x + 1 * r][y + 1 * r] += sendmap[x][y] * 0.1; }
			else { sendsum += sendmap[x][y] * 0.1; }
			res -= (int)(sendmap[x][y] * 0.1);
			if (y - 2 * r >= 0) {
				sendmap[x][y - 2 * r] += sendmap[x][y] * 0.02;
				sendmap[x][y - 1 * r] += sendmap[x][y] * 0.07;
			}
			else {sendsum += sendmap[x][y] * 0.02; sendsum += sendmap[x][y] * 0.07;}
			res -= (int)(sendmap[x][y] * 0.07);
			res -= (int)(sendmap[x][y] * 0.02);
			if (y + 2 * r < N) {
				sendmap[x][y + 2 * r] += sendmap[x][y] * 0.02;
				sendmap[x][y + 1 * r] += sendmap[x][y] * 0.07;
			}
			else { sendsum += sendmap[x][y] * 0.02; sendsum += sendmap[x][y] * 0.07; }
			res -= (int)(sendmap[x][y] * 0.07);
			res -= (int)(sendmap[x][y] * 0.02);
			if (x - 1 * r >= 0 && y - 1 * r >= 0) { sendmap[x - 1 * r][y - 1 * r] += sendmap[x][y] * 0.01; }
			else { sendsum += sendmap[x][y] * 0.01; }
			res -= (int)(sendmap[x][y] * 0.01);
			if (x - 1 * r >= 0 && y + 1 * r < N) { sendmap[x - 1 * r][y + 1 * r] += sendmap[x][y] * 0.01; }
			else { sendsum += sendmap[x][y] * 0.01; }
			res -= (int)(sendmap[x][y] * 0.01);
			if (x + 1 * r < N) {
				sendmap[x + 1 * r][y] += res;
			}
			else { sendsum += res; }
			return sendsum;
		}

		if (dir == 2) { //동
			if (y - 2 * r < N) { sendmap[x][y - 2 * r] += sendmap[x][y] * 0.05; }
			else { sendsum += sendmap[x][y] * 0.05; }
			res -= (int)(sendmap[x][y] * 0.05);
			if (x - 1 * r < N && y - 1 * r < N) { sendmap[x - 1 * r][y - 1 * r] += sendmap[x][y] * 0.1; }
			else { sendsum += sendmap[x][y] * 0.1; }
			res -= (int)(sendmap[x][y] * 0.1);
			if (x + 1 * r >= 0 && y - 1 * r < N) { sendmap[x + 1 * r][y - 1 * r] += sendmap[x][y] * 0.1; }
			else { sendsum += sendmap[x][y] * 0.1; }
			res -= (int)(sendmap[x][y] * 0.1);
			if (x - 2 * r < N) {
				sendmap[x - 2 * r][y] += sendmap[x][y] * 0.02;
				sendmap[x - 1 * r][y] += sendmap[x][y] * 0.07;
			}
			else { sendsum += sendmap[x][y] * 0.02; sendsum += sendmap[x][y] * 0.07; }
			res -= (int)(sendmap[x][y] * 0.02);
			res -= (int)(sendmap[x][y] * 0.07);
			if (x + 2 * r >= 0) {
				sendmap[x + 2 * r][y] += sendmap[x][y] * 0.02;
				sendmap[x + 1 * r][y] += sendmap[x][y] * 0.07;
			}
			else { sendsum += sendmap[x][y] * 0.02; sendsum += sendmap[x][y] * 0.07; }
			res -= (int)(sendmap[x][y] * 0.02);
			res -= (int)(sendmap[x][y] * 0.07);
			if (x + 1 * r >= 0 && y + 1 * r >= 0) { sendmap[x + 1 * r][y + 1 * r] += sendmap[x][y] * 0.01; }
			else { sendsum += sendmap[x][y] * 0.01; }
			res -= (int)(sendmap[x][y] * 0.01);
			if (x - 1 * r < N && y + 1 * r < N) { sendmap[x - 1 * r][y + 1 * r] += sendmap[x][y] * 0.01; }
			else { sendsum += sendmap[x][y] * 0.01; }
			res -= (int)(sendmap[x][y] * 0.01);
			if (y - 1 * r < N) { sendmap[x][y - 1 * r] += res; }
			else { sendsum += res; }
			return sendsum;
		}

		if (dir == 3) { //남
			if (x + 2 * r >= 0) {
				sendmap[x + 2 * r][y] += sendmap[x][y] * 0.05;
			}
			else { sendsum += sendmap[x][y] * 0.05;  }
			res -= (int)(sendmap[x][y] * 0.05);
			if (x + 1 * r >= 0 && y - 1 * r < N) { sendmap[x + 1 * r][y - 1 * r] += sendmap[x][y] * 0.1; }
			else { sendsum += sendmap[x][y] * 0.1; }
			res -= (int)(sendmap[x][y] * 0.1);
			if (x + 1 * r >= 0 && y + 1 * r >= 0) { sendmap[x + 1 * r][y + 1 * r] += sendmap[x][y] * 0.1; }
			else { sendsum += sendmap[x][y] * 0.1; }
			res -= (int)(sendmap[x][y] * 0.1);
			if (y - 2 * r < N) {
				sendmap[x][y - 2 * r] += sendmap[x][y] * 0.02;
				sendmap[x][y - 1 * r] += sendmap[x][y] * 0.07;
			}
			else {
				sendsum += sendmap[x][y] * 0.02; sendsum += sendmap[x][y] * 0.07;
			}
			res -= (int)(sendmap[x][y] * 0.02);
			res -= (int)(sendmap[x][y] * 0.07);
			if (y + 2 * r >= 0) {
				sendmap[x][y + 2 * r] += sendmap[x][y] * 0.02;
				sendmap[x][y + 1 * r] += sendmap[x][y] * 0.07;
			}
			else { sendsum += sendmap[x][y] * 0.02; sendsum += sendmap[x][y] * 0.07; }
			res -= (int)(sendmap[x][y] * 0.02);
			res -= (int)(sendmap[x][y] * 0.07);
			if (x - 1 * r < N && y - 1 * r < N) { sendmap[x - 1 * r][y - 1 * r] += sendmap[x][y] * 0.01; }
			else { sendsum += sendmap[x][y] * 0.01; }
			res -= (int)(sendmap[x][y] * 0.01);
			if (x - 1 * r < N&& y + 1 * r >= 0) { sendmap[x - 1 * r][y + 1 * r] += sendmap[x][y] * 0.01; }
			else { sendsum += sendmap[x][y] * 0.01; }
			res -= (int)(sendmap[x][y] * 0.01);
			if (x + 1 * r >= 0) {
				sendmap[x + 1 * r][y] += res;
			}
			else { sendsum += res; }
			return sendsum;
		}
	}

	void watch() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << sendmap[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "sendsum: " << totalaway << endl;
	}
int main() {
	cin >> N;
	sx = N / 2; sy = N / 2;
	inputs();
	cout << endl;
	while (1) {
		for (int i = 0; i < 2; i++) { //같은 방향으로 칸의 이동 수 11 22 33 44
			for (int j = 0; j < increasecount; j++) {
				sx = sx + dx[direction];
				sy = sy + dy[direction];
				if(direction==0 ||direction==1){ totalaway += caculate(direction, sx, sy,1,sendmap[sx][sy]); } //서,남
				else{ totalaway += caculate(direction, sx, sy,-1, sendmap[sx][sy]); }//동북
				sendmap[sx][sy] = 0;
				watch();
				if (sx == 0 && sy == 0) { cout << totalaway; return 0; }
			}
			direction = (direction + 1) % 4; //방향이동
		}
		increasecount++;
	}
}