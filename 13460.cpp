#include<bits/stdc++.h>
using namespace std;

int N, M;
char inputc[11][11];
int rx, ry, bx, by, hx, hy;
//위,오른쪽,아래,왼쪽
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
	int savebx = bx; int saveby = by; // 나중에 어떤구슬을 빡꾸 시켜줄지 결정하기위해
	if (dir == 0) { //위
		while (inputc[bx][by] != '#') {
			bx += dx[dir];
			if (bx == hx && by == hy) { //이동하다가 홀에 빠짐
				return 0;
			}
		}
		bx++;

		while (inputc[rx][ry] != '#') {
			rx += dx[dir];
			if (rx == hx && ry == hy) { //이동하다가 홀에 빠짐
				return 1; //빨간색이 들어감 (성공)
			}
		}
		rx++;
	}

	else if (dir == 1) { //오른쪽
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
	else if (dir == 2) { //아래	
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
	else { //왼쪽
		while (inputc[bx][by] != '#') {
			by += dy[dir];
			if (hx == bx && hy == by) {
				return 0; //파란색이 빠짐
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


	//만일 파란색,빨간색 구슬이 겹쳐졌다면
	if (dir == 0 && bx == rx && by == ry) { //위
		if (savebx < saverx) { rx++; }
		else { bx++; }
	}
	if (dir == 1 && bx == rx && by == ry) { //오른쪽
		if (saveby < savery) { by--; }
		else ry--;
	}
	if (dir == 2 && bx == rx && by == ry) { //아래
		if (savebx < saverx) { bx--; }
		else { rx--; }
	}
	if (dir == 3 && bx == rx && by == ry) { //왼쪽
		if (saveby < savery) { ry++; }
		else { by++; }
	}
	return 2;
}

void moveboard(int cnt, int prev) {
	if (cnt > 10) return;

	int tmprx = rx; int tmpry = ry; //dfs를 위한
	int tmpbx = bx; int tmpby = by;

	int r;
	for (int i = 0; i < 4; i++) {
		if (i == prev) continue;
		r=makemove(i);
		if (r == 0) { //실패 (더이상 조합을 볼필요 x
			rx = tmprx; ry = tmpry;
			bx = tmpbx; by = tmpby;
			continue;
		}

		if (r == 1) { //성공 최단시간 성공만 보므로 더 볼필요 x
		minresult = min(minresult, cnt);
		rx = tmprx; ry = tmpry;
		bx = tmpbx; by = tmpby; 
		continue;
		}

		moveboard(cnt + 1, i); //다음 탐색 진행
		rx = tmprx; ry = tmpry;
		bx = tmpbx; by = tmpby;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	
	moveboard(1,-1); // cnt, prevdir(방금 움직였던 방향)
	if (minresult != 12) cout << minresult;
	else cout << -1;
	return 0;
}


