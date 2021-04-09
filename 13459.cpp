#include<bits/stdc++.h>
using namespace std;

int rx, ry, bx, by;
int n, m;
char ground[11][11];
bool suc = false;
bool tmpfail = false;
vector<int> dirvector;//�������� (0,1,2,3)

//�������� ������ ����
// �Ķ����� �ְų� �Ѵ� ������ ����

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
		//�������� ��� �񱳸� ���� �������� �ʿ�

		if (dirvector[i] == 0) { //��
			//�Ķ��� �̵�
			while (ground[bx][by] != '#') {
				by++;
				if (ground[bx][by] == 'O') { tmpfail = true; return; }
			}
			by--; //��ĭ back

			//������ �̵�
			while (ground[rx][ry] != '#') {
				ry++;
				if (ground[rx][ry] == 'O') { //�Ķ����� ���� �ʰ� �������� �����
					suc = true; return;
				}
			}
			ry--;
		}
		else if (dirvector[i] == 2) {//��
						//�Ķ��� �̵�
			while (ground[bx][by] != '#') {
				by--;
				if (ground[bx][by] == 'O') { tmpfail = true; return; }
			}
			by++; //��ĭ back

			//������ �̵�
			while (ground[rx][ry] != '#') {
				ry--;
				if (ground[rx][ry] == 'O') { //�Ķ����� ���� �ʰ� �������� �����
					suc = true; return;
				}
			}
			ry++;
		}
		else if (dirvector[i] == 1) {//��
							//�Ķ��� �̵�
			while (ground[bx][by] != '#') {
				bx++;
				if (ground[bx][by] == 'O') { tmpfail = true; return; }
			}
			bx--; //��ĭ back

			//������ �̵�
			while (ground[rx][ry] != '#') {
				rx++;
				if (ground[rx][ry] == 'O') { //�Ķ����� ���� �ʰ� �������� �����
					suc = true; return;
				}
			}
			rx--;
		}
		else {//��
										//�Ķ��� �̵�
			while (ground[bx][by] != '#') {
				bx--;
				if (ground[bx][by] == 'O') { tmpfail = true; return; }
			}
			bx++; //��ĭ back

			//������ �̵�
			while (ground[rx][ry] != '#') {
				rx--;
				if (ground[rx][ry] == 'O') { //�Ķ����� ���� �ʰ� �������� �����
					suc = true; return;
				}
			}
			rx++;
		}


		//�������ٸ�
		if (rx == bx && ry == by) { //�� ���� �������� ��
			if (dirvector[i] == 0) { //�̵����� (��)
				if (sry < sby) { //������ �� �������� �� ���ʿ� �־���
					ry--;
				}
				else by--;
			}
			else if (dirvector[i] == 1) { //(��)
				if (srx < sbx) { //������ �� �������� �� ���ʿ� �־���
					rx--;
				}
				else bx--;
			}
			else if (dirvector[i] == 2) { //�̵����� (��)
				if (sry < sby) { //������ �� �������� �� ���ʿ� �־���
					by++;
				}
				else ry++;
			}
			else if (dirvector[i] == 3) { //(��)
				if (srx < sbx) { //������ �� �������� �� ���ʿ� �־���
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