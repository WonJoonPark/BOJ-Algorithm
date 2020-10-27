#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int loadmap[101][101];
int L;
int result = 0;
int init;
bool check;
bool checkrow[101];

void inputs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> loadmap[i][j];
		}
	}
}
int gap(int a, int b) {
	if (a > b) return a - b;
	else { return b - a; }
}
void initcheck() {
	for (int i = 0; i < 101; i++) {
		checkrow[i] = 0;
	}
}
void lookr() {
	for (int i = 0; i < N; i++) {
		initcheck();
		init = loadmap[i][0];
		check = true;
		for (int j = 1; j < N; j++) {
			if (init == loadmap[i][j]) { init = loadmap[i][j]; continue; }
			if (gap(init, loadmap[i][j]) == 1) { //����1����
				if (init < loadmap[i][j]) { //���� ����(������ ū)
					if (j - L < 0) { check = false; break; }
					else {
						for (int k = 1; k <= L; k++) {
							if(checkrow[j-k]==true || loadmap[i][j - k] != init)
							 { check = false; break; }
						}
						for (int k = 1; k <= L; k++) {
							checkrow[j - k] = true;
						}
						if (check == false) break;
					}
				}
				else { //������ ���� ģ���� ����
					if(j+L>N) { check = false; break; }
					else{
						for (int k = 0; k < L; k++) {
							if (checkrow[j+k]==true||loadmap[i][j + k] != init-1)
							{ check = false; break; }
						}
						for (int k = 0; k < L; k++) {
							checkrow[j + k] = true;
						}
						if (check == false) break;
						j += L-1; //�տ��ٰ� ���θ� ������ ��� ������ �ʿ�
					}
				}
			}
			else {check = false; break;} //����1���� �̻�
		init = loadmap[i][j];
		}
		if (check == true) { result++;  }
	}
}
void looku() {
	for (int i = 0; i < N; i++) {
		initcheck();
		init = loadmap[0][i];
		check = true;
		for (int j = 1; j < N; j++) {
			if (init == loadmap[j][i]) { init = loadmap[j][i]; continue; }
			if (gap(init, loadmap[j][i]) == 1) { //����1����
				if (init < loadmap[j][i]) { //���� ����(������ ū)
					if (j - L < 0) { check = false; break; }
					else {
						for (int k = 1; k <= L; k++) {
							if (checkrow[j - k] == true || loadmap[j - k][i] != init)
							{
								check = false; break;
							}
						}
						for (int k = 1; k <= L; k++) {
							checkrow[j - k] = true;
						}
						if (check == false) break;
					}
				}
				else { //������ ���� ģ���� ����
					if (j + L > N) { check = false; break; }
					else {
						for (int k = 0; k < L; k++) {
							if (checkrow[j + k] == true || loadmap[j + k][i] != init - 1)
							{
								check = false; break;
							}
						}
						for (int k = 0; k < L; k++) {
							checkrow[j + k] = true;
						}
						if (check == false) break;
						j += L-1; //�տ��ٰ� ���θ� ������ ��� ������ �ʿ�
					}
				}
			}
			else { check = false; break; } //����1���� �̻�
			init = loadmap[j][i];
		}
		if (check == true) { result++;  }
	}
}

void checkingload() {
	lookr();
	looku();
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;
	inputs();
	checkingload();
	return 0;
}