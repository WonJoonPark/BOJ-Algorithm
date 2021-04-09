#include<bits/stdc++.h>
using namespace std;

int T, n;
char target, dir;
char prestatus[6] = { 'r','o','g','b','y','w' };
char cube[6][9];
//0(��), 1(��), 2(��), 3(��), 4(�Ʒ�), 5(��)

// U (��), D (�Ʒ�), F(��)
// B (��), L (��), R (����)

void initcube() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) 
			cube[i][j] = prestatus[i];
	}
}
void frontrotate(char tar,char d) {
	int t;
	if (tar == 'F') t = 0;
	else if (tar == 'B') t = 1;
	else if (tar == 'L') t = 2;
	else if (tar == 'R') t = 3;
	else if (tar == 'D') t = 4;
	else t = 5;

	char tmpsave[3] = { cube[t][0],cube[t][1],cube[t][2] };
	if (d == '+') { //�ð���� 
		cube[t][2] = cube[t][0]; cube[t][1] = cube[t][3]; cube[t][0] = cube[t][6];
		cube[t][3] = cube[t][7]; cube[t][6] = cube[t][8]; cube[t][7] = cube[t][5]; cube[t][8] = tmpsave[2];
		cube[t][5] = tmpsave[1];
	}
	else { //�ݽð����
		cube[t][0] = cube[t][2]; cube[t][1] = cube[t][5]; cube[t][2] = cube[t][8];
		cube[t][5] = cube[t][7]; cube[t][8] = cube[t][6]; cube[t][7] = cube[t][3]; cube[t][6] = tmpsave[0];
		cube[t][3] = tmpsave[1];
	}
}
void siderotate(char tar, char d) {
	int t;
	if (tar == 'F') t = 0;
	else if (tar == 'B') t = 1;
	else if (tar == 'L') t = 2;
	else if (tar == 'R') t = 3;
	else if (tar == 'D') t = 4;
	else t = 5;

	if (t == 0 && d == '+') { // �ո��� �ð����
		char tmpsave[3] = { cube[5][6],cube[5][7],cube[5][8] };
		cube[5][8] = cube[2][2]; cube[5][7] = cube[2][5]; cube[5][6] = cube[2][8];
		cube[2][2] = cube[4][8]; cube[2][5] = cube[4][7]; cube[2][8] = cube[4][6];
		cube[4][8] = cube[3][6]; cube[4][7] = cube[3][3]; cube[4][6] = cube[3][0];
		cube[3][6] = tmpsave[2]; cube[3][3] = tmpsave[1]; cube[3][0] = tmpsave[0];
	}
	else if (t == 0 && d == '-') { //�ո��� �ݽð�
		char tmpsave[3] = { cube[5][6],cube[5][7],cube[5][8] };
		cube[5][6] = cube[3][0]; cube[5][7] = cube[3][3]; cube[5][8] = cube[3][6];
		cube[3][0] = cube[4][6]; cube[3][3] = cube[4][7]; cube[3][6] = cube[4][8];
		cube[4][6] = cube[2][8]; cube[4][7] = cube[2][5]; cube[4][8] = cube[2][2];
		cube[2][8] = tmpsave[0]; cube[2][5] = tmpsave[1]; cube[2][2] = tmpsave[2];
	}	
	else if (t == 1 && d == '+') { //�޸��� �ð�
		char tmpsave[3] = { cube[5][0],cube[5][1],cube[5][2] };
		cube[5][0] = cube[3][2]; cube[5][1] = cube[3][5]; cube[5][2] = cube[3][8];
		cube[3][2] = cube[4][0]; cube[3][5] = cube[4][1]; cube[3][8] = cube[4][2];
		cube[4][0] = cube[2][6]; cube[4][1] = cube[2][3]; cube[4][2] = cube[2][0];
		cube[2][6] = tmpsave[0]; cube[2][3] = tmpsave[1]; cube[2][0] = tmpsave[2];
	}
	else if (t == 1 && d == '-') { //�޸��� �ݽð�
		char tmpsave[3] = { cube[5][0],cube[5][1],cube[5][2] };
		cube[5][2] = cube[2][0]; cube[5][1] = cube[2][3]; cube[5][0] = cube[2][6];
		cube[2][0] = cube[4][2]; cube[2][3] = cube[4][1]; cube[2][6] = cube[4][0];
		cube[4][2] = cube[3][8]; cube[4][1] = cube[3][5]; cube[4][0] = cube[3][2];
		cube[3][8] = tmpsave[2]; cube[3][5] = tmpsave[1]; cube[3][2] = tmpsave[0];
	}
	else if (t == 2 && d == '+') { //���ʸ��� �ð����
		char tmpsave[3] = { cube[5][6],cube[5][3],cube[5][0] };
		cube[5][6] = cube[1][2]; cube[5][3] = cube[1][5]; cube[5][0] = cube[1][8];
		cube[1][2] = cube[4][2]; cube[1][5] = cube[4][5]; cube[1][8] = cube[4][8];
		cube[4][2] = cube[0][6]; cube[4][5] = cube[0][3]; cube[4][8] = cube[0][0];
		cube[0][6] = tmpsave[0]; cube[0][3] = tmpsave[1]; cube[0][0] = tmpsave[2];
	}
	else if (t == 2 && d == '-') { //���ʸ��� �ݽð����
		char tmpsave[3] = { cube[5][6],cube[5][3],cube[5][0] };
		cube[5][0] = cube[0][0]; cube[5][3] = cube[0][3]; cube[5][6] = cube[0][6];
		cube[0][0] = cube[4][8]; cube[0][3] = cube[4][5]; cube[0][6] = cube[4][2];
		cube[4][8] = cube[1][8]; cube[4][5] = cube[1][5]; cube[4][2] = cube[1][2];
		cube[1][8] = tmpsave[2]; cube[1][5] = tmpsave[1]; cube[1][2] = tmpsave[0];
	}
	else if (t == 3 && d == '+') { //�����ʸ��� �ð����
		char tmpsave[3] = { cube[5][2],cube[5][5],cube[5][8] };
		cube[5][2] = cube[0][2]; cube[5][5] = cube[0][5]; cube[5][8] = cube[0][8];
		cube[0][2] = cube[4][6]; cube[0][5] = cube[4][3]; cube[0][8] = cube[4][0];
		cube[4][6] = cube[1][6]; cube[4][3] = cube[1][3]; cube[4][0] = cube[1][0];
		cube[1][6] = tmpsave[0]; cube[1][3] = tmpsave[1]; cube[1][0] = tmpsave[2];
	}
	else if (t == 3 && d == '-') {//�����ʸ��� �ݽð����
		char tmpsave[3] = { cube[5][2],cube[5][5],cube[5][8] };
		cube[5][8] = cube[1][0]; cube[5][5] = cube[1][3]; cube[5][2] = cube[1][6];
		cube[1][0] = cube[4][0]; cube[1][3] = cube[4][3]; cube[1][6] = cube[4][6];
		cube[4][0] = cube[0][8]; cube[4][3] = cube[0][5]; cube[4][6] = cube[0][2];
		cube[0][8] = tmpsave[2]; cube[0][5] = tmpsave[1]; cube[0][2] = tmpsave[1];
	}
	else if (t == 4 && d == '+') { // �ظ��� �ð����
		char tmpsave[3] = { cube[1][8],cube[1][7],cube[1][6] };
		cube[1][8] = cube[3][8]; cube[1][7] = cube[3][7]; cube[1][6] = cube[3][6];
		cube[3][8] = cube[0][8]; cube[3][7] = cube[0][7]; cube[3][6] = cube[0][6];
		cube[0][8] = cube[2][8]; cube[0][7] = cube[2][7]; cube[0][6] = cube[2][6];
		cube[2][8] = tmpsave[0]; cube[2][7] = tmpsave[1]; cube[2][6] = tmpsave[2];
	}
	else if (t == 4 && d == '-') { // �ظ��� �ݽð����
		char tmpsave[3] = { cube[1][8],cube[1][7],cube[1][6] };
		cube[1][6] = cube[2][6]; cube[1][7] = cube[2][7]; cube[1][8] = cube[2][8];
		cube[2][6] = cube[0][6]; cube[2][7] = cube[0][7]; cube[2][8] = cube[0][8];
		cube[0][6] = cube[3][6]; cube[0][7] = cube[3][7]; cube[0][8] = cube[3][8];
		cube[3][6] = tmpsave[2]; cube[3][7] = tmpsave[1]; cube[3][8] = tmpsave[0];
	}
	else if (t == 5 && d == '+') { //������ �ð��������
		char tmpsave[3] = { cube[1][2], cube[1][1],cube[1][0] };
		cube[1][0] = cube[2][0]; cube[1][1] = cube[2][1]; cube[1][2] = cube[2][2];
		cube[2][0] = cube[0][0]; cube[2][1] = cube[0][1]; cube[2][2] = cube[0][2];
		cube[0][0] = cube[3][0]; cube[0][1] = cube[3][1]; cube[0][2] = cube[3][2];
		cube[3][0] = tmpsave[2]; cube[3][1] = tmpsave[1]; cube[3][2] = tmpsave[0];
	}
	else if (t == 5 && d == '-') {
		char tmpsave[3] = { cube[1][2], cube[1][1],cube[1][0] };
		cube[1][2] = cube[3][2]; cube[1][1] = cube[3][1]; cube[1][0] = cube[3][0];
		cube[3][2] = cube[0][2]; cube[3][1] = cube[0][1]; cube[3][0] = cube[0][0];
		cube[0][2] = cube[2][2]; cube[0][1] = cube[2][1]; cube[0][0] = cube[2][0];
		cube[2][2] = tmpsave[0]; cube[2][1] = tmpsave[1]; cube[2][0] = tmpsave[2];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		initcube();
		for (int i = 0; i < n; i++) { //�ѹ��� ȸ��
			cin >> target >> dir;
			frontrotate(target, dir); //�ش�� ���ʿ����� ȸ��
			siderotate(target, dir); // �ش�� ���ʸ� �Ϻε��� �̵�
		}
		// ���� ���
		for (int i = 0; i < 9; i++) {
			if (i!=0 && i % 3 == 0) cout << "\n";
			cout << cube[5][i];
		}
		cout << "\n";
	}
	return 0;
}