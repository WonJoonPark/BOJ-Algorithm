#include<bits/stdc++.h>
using namespace std;

int n,sx,sy;
int sendpan[500][500];
int outsend = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
// 0123 ¼­³²µ¿ºÏ
bool boundcheck(int x, int y) {
	if (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1) return true;
	else return false;
}
void sendmove(int dir,int x,int y) {
	int sendsum = sendpan[x][y];
	int restsum = sendpan[x][y];
	if (dir == 0) { //¼­
		if (boundcheck(x + 1, y+1)) sendpan[x+1][y+1]+= (sendsum / 100);
		else outsend += (sendsum / 100);
		restsum -= (sendsum / 100);

		if (boundcheck(x - 1, y+1)) sendpan[x - 1][y+1] += (sendsum / 100);
		else outsend += (sendsum / 100);
		restsum -= (sendsum / 100);

		if (boundcheck(x + 1, y)) sendpan[x + 1][y] += (sendsum*7 / 100);
		else outsend += (sendsum*7 / 100);
		restsum -= (sendsum*7 / 100);

		if (boundcheck(x - 1, y)) sendpan[x - 1][y] += (sendsum * 7 / 100);
		else outsend += (sendsum * 7 / 100);
		restsum -= (sendsum * 7 / 100);

		if (boundcheck(x + 2, y)) sendpan[x + 2][y] += (sendsum * 2 / 100);
		else outsend += (sendsum * 2 / 100);
		restsum -= (sendsum * 2 / 100);

		if (boundcheck(x - 2, y)) sendpan[x - 2][y] += (sendsum * 2 / 100);
		else outsend += (sendsum * 2 / 100);
		restsum -= (sendsum * 2 / 100);

		if (boundcheck(x -1, y -1)) sendpan[x - 1][y - 1] += (sendsum / 10);
		else outsend += (sendsum  / 10);
		restsum -= (sendsum / 10);

		if (boundcheck(x +1, y - 1)) sendpan[x +1][y - 1] += (sendsum  / 10);
		else outsend += (sendsum  / 10);
		restsum -= (sendsum / 10);

		if (boundcheck(x, y - 2)) sendpan[x][y - 2] += (sendsum*5 / 100);
		else outsend += (sendsum * 5 / 100);
		restsum -= (sendsum * 5 / 100);

		if (boundcheck(x, y-1)) { sendpan[x][y-1] += restsum; }
		else outsend += restsum;
	}
 	else if (dir == 1) { //³²
		if (boundcheck(x-1 , y+1)) sendpan[x-1][y+1] += (sendsum / 100);
		else outsend += (sendsum / 100);
		restsum -= (sendsum / 100);

		if (boundcheck(x-1, y-1)) sendpan[x-1][y-1] += (sendsum / 100);
		else outsend += (sendsum / 100);
		restsum -= (sendsum / 100);

		if (boundcheck(x, y + 1)) sendpan[x][y + 1] += (sendsum * 7 / 100);
		else outsend += (sendsum * 7 / 100);
		restsum -= (sendsum * 7 / 100);

		if (boundcheck(x, y - 1)) sendpan[x][y - 1] += (sendsum * 7 / 100);
		else outsend += (sendsum * 7 / 100);
		restsum -= (sendsum * 7 / 100);

		if (boundcheck(x, y +2)) sendpan[x][y +2] += (sendsum * 2 / 100);
		else outsend += (sendsum * 2 / 100);
		restsum -= (sendsum * 2 / 100);

		if (boundcheck(x, y - 2)) sendpan[x][y - 2] += (sendsum * 2 / 100);
		else outsend += (sendsum * 2 / 100);
		restsum -= (sendsum * 2 / 100);

		if (boundcheck(x + 1, y +1)) sendpan[x + 1][y +1] += (sendsum / 10);
		else outsend += (sendsum / 10);
		restsum -= (sendsum / 10);

		if (boundcheck(x + 1, y - 1)) sendpan[x +1][y - 1] += (sendsum / 10);
		else outsend += (sendsum / 10);
		restsum -= (sendsum / 10);

		if (boundcheck(x+2, y)) sendpan[x+2][y] += (sendsum * 5 / 100);
		else outsend += (sendsum * 5 / 100);
		restsum -= (sendsum * 5 / 100);

		if (boundcheck(x + 1, y)) { sendpan[x + 1][y] += restsum; }
		else outsend += restsum;\
	}
	else if (dir == 2) { //µ¿
		if (boundcheck(x + 1, y-1)) sendpan[x + 1][y-1] += (sendsum / 100);
		else outsend += (sendsum / 100);
		restsum -= (sendsum / 100);

		if (boundcheck(x - 1, y-1)) sendpan[x - 1][y-1] += (sendsum / 100);
		else outsend += (sendsum / 100);
		restsum -= (sendsum / 100);

		if (boundcheck(x + 1, y)) sendpan[x + 1][y] += (sendsum * 7 / 100);
		else outsend += (sendsum * 7 / 100);
		restsum -= (sendsum * 7 / 100);

		if (boundcheck(x - 1, y)) sendpan[x - 1][y] += (sendsum * 7 / 100);
		else outsend += (sendsum * 7 / 100);
		restsum -= (sendsum * 7 / 100);

		if (boundcheck(x + 2, y)) sendpan[x + 2][y] += (sendsum * 2 / 100);
		else outsend += (sendsum * 2 / 100);
		restsum -= (sendsum * 2 / 100);

		if (boundcheck(x - 2, y)) sendpan[x - 2][y] += (sendsum * 2 / 100);
		else outsend += (sendsum * 2 / 100);
		restsum -= (sendsum * 2 / 100);

		if (boundcheck(x - 1, y + 1)) sendpan[x - 1][y + 1] += (sendsum / 10);
		else outsend += (sendsum / 10);
		restsum -= (sendsum / 10);

		if (boundcheck(x + 1, y + 1)) sendpan[x + 1][y + 1] += (sendsum / 10);
		else outsend += (sendsum / 10);
		restsum -= (sendsum / 10);

		if (boundcheck(x, y + 2)) sendpan[x][y + 2] += (sendsum * 5 / 100);
		else outsend += (sendsum * 5 / 100);
		restsum -= (sendsum * 5 / 100);

		if (boundcheck(x, y+1)) { sendpan[x][y+1] += restsum; }
		else outsend += restsum;
	}
	else { //ºÏ
	if (boundcheck(x+1, y - 1)) sendpan[x+1][y - 1] += (sendsum / 100);
	else outsend += (sendsum / 100);
	restsum -= (sendsum / 100);

	if (boundcheck(x+1, y + 1)) sendpan[x+1][y + 1] += (sendsum / 100);
	else outsend += (sendsum / 100);
	restsum -= (sendsum / 100);

	if (boundcheck(x, y + 1)) sendpan[x][y + 1] += (sendsum * 7 / 100);
	else outsend += (sendsum * 7 / 100);
	restsum -= (sendsum * 7 / 100);

	if (boundcheck(x, y - 1)) sendpan[x][y - 1] += (sendsum * 7 / 100);
	else outsend += (sendsum * 7 / 100);
	restsum -= (sendsum * 7 / 100);

	if (boundcheck(x, y + 2)) sendpan[x][y + 2] += (sendsum * 2 / 100);
	else outsend += (sendsum * 2 / 100);
	restsum -= (sendsum * 2 / 100);

	if (boundcheck(x, y - 2)) sendpan[x][y - 2] += (sendsum * 2 / 100);
	else outsend += (sendsum * 2 / 100);
	restsum -= (sendsum * 2 / 100);

	if (boundcheck(x - 1, y + 1)) sendpan[x - 1][y + 1] += (sendsum / 10);
	else outsend += (sendsum / 10);
	restsum -= (sendsum / 10);

	if (boundcheck(x - 1, y - 1)) sendpan[x - 1][y - 1] += (sendsum / 10);
	else outsend += (sendsum / 10);
	restsum -= (sendsum / 10);

	if (boundcheck(x - 2, y)) sendpan[x - 2][y] += (sendsum * 5 / 100);
	else outsend += (sendsum * 5 / 100);
	restsum -= (sendsum * 5 / 100);

	if (boundcheck(x - 1, y)) { sendpan[x - 1][y] += restsum; }
	else outsend += restsum;
	
	}


	sendpan[x][y] = 0;
}


void inputs() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sendpan[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	int tmpdir = 0;
	int l = 0;
	sx = n / 2; sy = n / 2;
	while (1) {
		for (int i = 0; i <= l; i++) {
			sx += dx[tmpdir];
			sy += dy[tmpdir];
			sendmove(tmpdir, sx, sy);
			if (sx == 0 && sy == 0) {
				cout << outsend;
				return 0;
			}
		}
		tmpdir++;
		if (tmpdir % 2 == 0) { l++; }
		tmpdir = tmpdir % 4;
	}



	return 0;
}