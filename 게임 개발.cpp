#include<iostream>
using namespace std;

int map[51][51]; // 0->����,1->�ٴ�,2->�̹� �湮�� ��
int n, m;
int cd[4] = { 0,1,2,3 };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cx, cy,ccd;
bool check = false;
int tmp;

void getmap(int n,int m) {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			map[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}
bool checkmap() {
	check = false;
	for (int i = 0; i < 4; i++) {
		if (map[cx + dx[i]][cy + dy[i]] == 0) {
			check = true; break;
		}
	}
	if (check == false && map[cx + dx[(ccd + 2) % 4]][cy + dy[(ccd + 2) % 4]]==1) { //4���� �� �� �� ���� ���̰� ���ʵ� �ٴ�ĭ�� ���
		return false;
	}
	cx = cx + dx[(ccd + 2) % 4];
	cy = cy + dy[(ccd + 2) % 4];
	return true;
}

int main() {
	cin >> n >> m;
	cin >> cx >> cy >> ccd;
	getmap(n,m);
	int resultcount = 1;
	map[cx][cy] = 2;
	while (1) { //�湮�� �� ǥ��
		if (checkmap() == false) break; //Ž�� ���� ����
		if (map[cx + dx[(ccd + 3) % 4]][cy + dy[(ccd + 3) % 4]] == 0) {
			ccd = (ccd + 3) % 4; //������ȯ
			cx = cx + dx[(ccd + 3) % 4]; //�� �������� ��ĭ ����
			cy = cy + dy[(ccd + 3) % 4]; //�� �������� ��ĭ ����
			map[cx][cy] = 2;
			resultcount++;
		}
		else {
			ccd = (ccd + 3) % 4; //������ȯ
		}
	}
	cout << resultcount << "\n";
	return 0;
}