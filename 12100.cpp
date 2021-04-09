#include<bits/stdc++.h>
using namespace std;

int N;
int gameboard[21][21];
bool checkmodi[21][21];
int maxresult;
 //�� �Ʒ� �� �� 0 1 2 3

void inputs() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> gameboard[i][j];
		}
	}
}
void copyboard1(int s[][21]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) s[i][j] = gameboard[i][j];
	}
}
void copyboard2(int s[][21]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) gameboard[i][j] = s[i][j];
	}
}
void moveblock(int dir) {
	if (dir == 0) { //��
		for (int i = 1; i <= N; i++) { // �� ����
			for (int j = 2; j <= N; j++) {
				if (gameboard[j][i] == 0) continue;
				int tmpj = j;
				if ( gameboard[j-1][i]==0) {
					tmpj--;
					while (1) {
						if (gameboard[tmpj][i] != 0) {
							gameboard[tmpj+1][i] = gameboard[j][i];
							gameboard[j][i] = 0;
							tmpj++;
							break;
						} // tmpi+1�� �� �ڸ�
						if (tmpj == 1) {
							gameboard[tmpj][i] = gameboard[j][i];
							gameboard[j][i] = 0; 
							break;
						}
						tmpj--;
					}
				}
				if (gameboard[tmpj][i] == gameboard[tmpj - 1][i] &&checkmodi[tmpj-1][i]==false) {
					gameboard[tmpj-1][i] *= 2;
					gameboard[tmpj][i] = 0;
					checkmodi[tmpj - 1][i] = true; //������ ���� ����
				}
			}
		}
	}
	else if (dir == 1) { //�Ʒ�
		for (int i = 1; i <=N; i++) {
			for (int j = N-1; j >0 ; j--) {
				if (gameboard[j][i] == 0) continue;
				int tmpj = j;
				if (gameboard[j+1][i]==0 ) {
					tmpj++;
					while (1) {
						if (gameboard[tmpj][i]!=0) {
							gameboard[tmpj - 1][i] = gameboard[j][i];
							gameboard[j][i] = 0;
							tmpj--;
							break;
						}	
						if (tmpj == N) {
							gameboard[tmpj][i] = gameboard[j][i];
							gameboard[j][i] = 0;
							break;
						}
						tmpj++;
					}
				}
				if (gameboard[tmpj][i] == gameboard[tmpj + 1][i] && checkmodi[tmpj + 1][i] == false) {
					gameboard[tmpj + 1][i] *= 2;
					gameboard[tmpj][i] = 0;
					checkmodi[tmpj + 1][i] = true; //������ ���� ����
				}
			}
		}
	}
	else if (dir == 2) { //��
		for (int i = 1; i <= N; i++) { // �� ����
			for (int j = 2; j <= N; j++) {
				if (gameboard[i][j] == 0) continue;
				int tmpj = j;
				if (gameboard[i][j-1]==0) {
					 tmpj--;
					while (1) {
						if (gameboard[i][tmpj] != 0) {
							gameboard[i][tmpj+1] = gameboard[i][j];
							gameboard[i][j] = 0;
							tmpj++;
							break;
						} // tmpi+1�� �� �ڸ�
						if (tmpj == 1) {
							gameboard[i][tmpj] = gameboard[i][j];
							gameboard[i][j] = 0;
							break;
						}
						tmpj--;
					}
				}
				if (gameboard[i][tmpj] == gameboard[i][tmpj-1] && checkmodi[i][tmpj-1] == false) {
					gameboard[i][tmpj-1] *= 2;
					gameboard[i][tmpj] = 0;
					checkmodi[i][tmpj-1] = true; //������ ���� ����
				}
			}
		}
	}
	else { //��
		for (int i = 1; i <= N; i++) {
			for (int j = N-1; j > 0; j--) {
				if (gameboard[i][j] == 0) continue;
				int tmpj = j;
				if (gameboard[i][j+1] == 0) {
					tmpj++;
					while (1) {
						if (gameboard[i][tmpj] != 0) {
							gameboard[i][tmpj-1] = gameboard[i][j];
							gameboard[i][j] = 0;
							tmpj--;
							break;
						}
						if (tmpj == N) {
							gameboard[i][tmpj] = gameboard[i][j];
							gameboard[i][j] = 0;
							break;
						}
						tmpj++;
					}
				}
				if (gameboard[i][tmpj] == gameboard[i][tmpj + 1] && checkmodi[i][tmpj + 1] == false) {
					gameboard[i][tmpj + 1] *= 2;
					gameboard[i][tmpj] = 0;
					checkmodi[i][tmpj + 1] = true; //������ ���� ����
				}
			}
		}
	}
}
void initmodi() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) checkmodi[i][j] = false;
	}
}
void watchblock() {
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << gameboard[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void findmax() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) maxresult = max(maxresult, gameboard[i][j]);
	}
}
void makecase(int cnt) {
	if (cnt > 5) return;
	findmax();// �ִ��ũ�� ����ϴ� �κ�
	int saveboard[21][21];
	copyboard1(saveboard); // ������ �� ����
	for (int i = 0; i < 4; i++) {
		initmodi();
		moveblock(i);
		makecase(cnt + 1);
		copyboard2(saveboard); // �� �̵����״� �� ����
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	makecase(0);
	cout << maxresult;
	return 0;
}