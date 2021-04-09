#include<bits/stdc++.h>
using namespace std;

int rx, ry, bx, by;
int n, m;
char ground[11][11];
bool suc = false;
bool tmpfail = false;
vector<int> dirvector;//동남서북 (0,1,2,3)

//빨간구슬 넣으면 성공
// 파란구슬 넣거나 둘다 넣으면 실패

void inputs() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			if (ground[i][j] == 'R') {
				rx = i; ry = j;
				ground[i][j] = '.';
			}
			if (ground[i][j] == 'B') {
				bx = i; by = j;
				ground[i][j] = '.';
			}
		}
	}
}


void testthecase(int rx, int ry, int bx, int by) {
	for (int i = 0; i < dirvector.size(); i++) {
		int srx = rx; int sry = ry;
		int sbx = bx; int sby = by;
		//겹쳐지는 경우 비교를 위해 시작점이 필요

		if (dirvector[i] == 0) { //동
			//파란공 이동
			while (ground[bx][by] != '#') {
				by++;
				if (ground[bx][by] == 'O') { tmpfail = true; return; }
			}
			by--; //한칸 back

			//빨간공 이동
			while (ground[rx][ry] != '#') {
				ry++;
				if (ground[rx][ry] == 'O') { //파란색은 들어가지 않고 빨간색만 들어간경우
					suc = true; return;
				}
			}
			ry--;
		}
		else if (dirvector[i] == 2) {//서
						//파란공 이동
			while (ground[bx][by] != '#') {
				by--;
				if (ground[bx][by] == 'O') { tmpfail = true; return; }
			}
			by++; //한칸 back

			//빨간공 이동
			while (ground[rx][ry] != '#') {
				ry--;
				if (ground[rx][ry] == 'O') { //파란색은 들어가지 않고 빨간색만 들어간경우
					suc = true; return;
				}
			}
			ry++;
		}
		else if (dirvector[i] == 1) {//남
							//파란공 이동
			while (ground[bx][by] != '#') {
				bx++;
				if (ground[bx][by] == 'O') { tmpfail = true; return; }
			}
			bx--; //한칸 back

			//빨간공 이동
			while (ground[rx][ry] != '#') {
				rx++;
				if (ground[rx][ry] == 'O') { //파란색은 들어가지 않고 빨간색만 들어간경우
					suc = true; return;
				}
			}
			rx--;
		}
		else {//북
										//파란공 이동
			while (ground[bx][by] != '#') {
				bx--;
				if (ground[bx][by] == 'O') { tmpfail = true; return; }
			}
			bx++; //한칸 back

			//빨간공 이동
			while (ground[rx][ry] != '#') {
				rx--;
				if (ground[rx][ry] == 'O') { //파란색은 들어가지 않고 빨간색만 들어간경우
					suc = true; return;
				}
			}
			rx++;
		}


		//겹쳐졌다면
		if (rx == bx && ry == by) { //두 공이 겹쳐졌을 때
			if (dirvector[i] == 0) { //이동방향 (동)
				if (sry < sby) { //시작할 때 빨간색이 더 왼쪽에 있었다
					ry--;
				}
				else by--;
			}
			else if (dirvector[i] == 1) { //(남)
				if (srx < sbx) { //시작할 때 빨간색이 더 위쪽에 있었다
					rx--;
				}
				else bx--;
			}
			else if (dirvector[i] == 2) { //이동방향 (서)
				if (sry < sby) { //시작할 때 빨간색이 더 왼쪽에 있었다
					by++;
				}
				else ry++;
			}
			else if (dirvector[i] == 3) { //(북)
				if (srx < sbx) { //시작할 때 빨간색이 더 위쪽에 있었다
					bx++;
				}
				else rx++;
			}
		}
	}
}

void makecase(int cnt,int preindex,int rx, int ry, int bx, int by) {
	
	if (suc == true) return;
	if (cnt > 10) return;
	if (!dirvector.empty()) {
		tmpfail = false;
		testthecase(rx, ry, bx, by);
		if (tmpfail == true) return;
	}

	for (int i = 0; i < 4; i++) {
		if (i != preindex) {
			dirvector.push_back(i);
			makecase(cnt + 1,i, rx, ry, bx, by);
			dirvector.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	inputs();
	makecase(0, 4, rx, ry, bx, by);
	cout << suc;


	return 0;
}