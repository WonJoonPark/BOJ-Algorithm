#include<bits/stdc++.h>
using namespace std;

int N, M;
char inputc[11][11];
int rx, ry, bx, by, hx, hy;
//��,������,�Ʒ�,����
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int minresult = 12;

void inputs() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> inputc[i][j];
			if (inputc[i][j] == 'R') {
				rx = i; ry = j;
				inputc[i][j] = '.';
			}
			if (inputc[i][j] == 'B') {
				bx = i; by = j;
				inputc[i][j] = '.';
			}
			if (inputc[i][j] == 'O') {
				hx = i; hy = j;
				inputc[i][j] = '.';
			}
		}
	}
}
int makemove(int dir) {
	int saverx = rx; int savery = ry;
	int savebx = bx; int saveby = by; // ���߿� ������� ���� �������� �����ϱ�����
	if (dir == 0) { //��
		while (inputc[bx][by] != '#') {
			bx += dx[dir];
			if (bx == hx && by == hy) { //�̵��ϴٰ� Ȧ�� ����
				return 0;
			}
		}
		bx++;

		while (inputc[rx][ry] != '#') {
			rx += dx[dir];
			if (rx == hx && ry == hy) { //�̵��ϴٰ� Ȧ�� ����
				return 1; //�������� �� (����)
			}
		}
		rx++;
	}

	else if (dir == 1) { //������
		while (inputc[bx][by] != '#') {
			by += dy[dir];
			if (bx == hx && by == hy) {
				return 0;
			}
		}
		by--;

		while (inputc[rx][ry] != '#') {
			ry += dy[dir];
			if (rx == hx && ry == hy) {
				return 1;
			}
		}
		ry--;
	}
	else if (dir == 2) { //�Ʒ�	
		while (inputc[bx][by] != '#') {
		bx += dx[dir];
		if (bx == hx && by == hy) {
			return 0;
			}
		}
		bx--;

		while (inputc[rx][ry] != '#') {
			rx += dx[dir];
			if (rx == hx && ry == hy) {
				return 1;
			}
		}
		rx--;
	}
	else { //����
		while (inputc[bx][by] != '#') {
			by += dy[dir];
			if (hx == bx && hy == by) {
				return 0; //�Ķ����� ����
			}
		}
		by++;

		while (inputc[rx][ry] != '#') {
			ry += dy[dir];
			if (rx == hx && ry == hy) {
				return 1;
			}
		}
		ry++;
	} 


	//���� �Ķ���,������ ������ �������ٸ�
	if (dir == 0 && bx == rx && by == ry) { //��
		if (savebx < saverx) { rx++; }
		else { bx++; }
	}
	if (dir == 1 && bx == rx && by == ry) { //������
		if (saveby < savery) { by--; }
		else ry--;
	}
	if (dir == 2 && bx == rx && by == ry) { //�Ʒ�
		if (savebx < saverx) { bx--; }
		else { rx--; }
	}
	if (dir == 3 && bx == rx && by == ry) { //����
		if (saveby < savery) { ry++; }
		else { by++; }
	}
	return 2;
}

void moveboard(int cnt, int prev) {
	if (cnt > 10) return;

	int tmprx = rx; int tmpry = ry; //dfs�� ����
	int tmpbx = bx; int tmpby = by;

	int r;
	for (int i = 0; i < 4; i++) {
		if (i == prev) continue;
		r=makemove(i);
		if (r == 0) { //���� (���̻� ������ ���ʿ� x
			rx = tmprx; ry = tmpry;
			bx = tmpbx; by = tmpby;
			continue;
		}

		if (r == 1) { //���� �ִܽð� ������ ���Ƿ� �� ���ʿ� x
		minresult = min(minresult, cnt);
		rx = tmprx; ry = tmpry;
		bx = tmpbx; by = tmpby; 
		continue;
		}

		moveboard(cnt + 1, i); //���� Ž�� ����
		rx = tmprx; ry = tmpry;
		bx = tmpbx; by = tmpby;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	
	moveboard(1,-1); // cnt, prevdir(��� �������� ����)
	if (minresult != 12) cout << minresult;
	else cout << -1;
	return 0;
}


