#include<bits/stdc++.h>
using namespace std;
int R, C,M;
struct shark {
	int speed, dir, ssize,num;
};
vector<shark> sea[102][102];
vector<pair<int, int>> sharkvec; // ������ ��ġ ����
bool sharkdie[10001]; // ��� ��Ҵ��� ���� ����
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int sharksum;

void inputs() {
	cin >> R >> C>>M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		sharkvec.push_back({ r,c });
		sea[r][c].push_back({ s,d - 1,z,i });
	}
}
void getshark(int f) {
	for (int i = 1; i <= R; i++) {
		if (!sea[i][f].empty()) {
			sharksum += sea[i][f][0].ssize; //����
			sharkdie[sea[i][f][0].num] = true;
			sea[i][f].pop_back();
			return;
		}
	}
	return;
}

void moveshark() {
	vector<shark> tmpsea[102][102];
	for (int i = 0; i < M; i++) {
		if (sharkdie[i]) continue; //�׾����� ��������

		int x = sharkvec[i].first; int y = sharkvec[i].second;
		int tmps, tmpd, tmpz;
			tmps = sea[x][y][0].speed;
			tmpz = sea[x][y][0].ssize; //ũ��
			tmpd = sea[x][y][0].dir;


		int fixexmovecount;
		if (tmpd <= 1) { // �����̵�
			fixexmovecount = tmps%(2*(R - 1));
			for (int a = 0; a < fixexmovecount; a++) {
				if (x == R) { tmpd = 0; }
				if (x == 1) { tmpd = 1; }
				x += dx[tmpd];
			}
		}
		else { //�����̵�
			fixexmovecount = tmps%(2*(C - 1));
			for (int a = 0; a < fixexmovecount; a++) {
				if (y == C) { tmpd = 3; }
				if (y == 1) { tmpd = 2; }
				y += dy[tmpd];
			}
		}
		sharkvec[i].first = x; sharkvec[i].second = y;
		if(tmpsea[x][y].empty()) tmpsea[x][y].push_back({ tmps,tmpd,tmpz,i }); //�ƹ��� ������ �׳� ����
		else { //�ٸ� �� ������ ū���� �������� ��ƸԴ´�
			if (tmpsea[x][y][0].ssize < tmpz) {
				sharkdie[tmpsea[x][y][0].num] = true; // ������ �ִ��� ��Ƹ���
				tmpsea[x][y].pop_back();
				tmpsea[x][y].push_back({ tmps,tmpd,tmpz,i });
			}
			else { //������������ ��Ƹ���
				sharkdie[i] = true;
			}
		}
	}
	for (int t = 1; t <= R; t++) {
		for (int k = 1; k <= C; k++) {
			sea[t][k] = tmpsea[t][k];
		}
	}
	return;
}
/*void watchshark() {
	cout << "\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (sea[i][j].empty()) cout << 0 << " ";
			else cout << sea[i][j][0].num+1 << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	for (int fm = 1; fm <= C; fm++) { // ���ò��� ��ġ (1�ʴ�)
		getshark(fm);
		moveshark();
	}
	cout << sharksum;


	return 0;
}