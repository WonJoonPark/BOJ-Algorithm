#include<bits/stdc++.h>
using namespace std;

int N, K;

int ground[14][14];
vector<pair<int,int>> chess[14][14]; //���̴� ������ ǥ���ϱ� ���� �Ǿ�=�ǾƷ� (��ȣ, �̵�����)
vector<pair<int, int>> horse; //�׸��� �ƴ�����;;��

int dx[4] = { 0,0,-1,1 }; //1234
int dy[4] = { 1,-1,0,0 };

void inputs() {
	cin >> N >> K;
	for (int i = 0; i <= N + 1; i++) { //�׵θ��� �Ķ��� ���
		ground[0][i] = 2;
		ground[i][0] = 2;
		ground[N + 1][i] = 2;
		ground[i][N + 1] = 2;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> ground[i][j];
		}
	}
	horse.push_back({ -1,-1 }); //index ���߱� ��

	int x, y, z;
	for (int i = 1; i <= K; i++) {
		cin >> x >> y >> z;
		chess[x][y].push_back({ i, z-1 });
		horse.push_back({ x,y }); //���� ��ġ ǥ��
	}
}
bool checkexit() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (chess[i][j].size() >= 4) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	int turncount = 0;
	while (1) {

		turncount++;
		//1�������� �̵�
		for (int i = 1; i <= K; i++) {
			int tx = horse[i].first; int ty = horse[i].second; // �� ���� ��ġ
			for (int j = 0; j < chess[tx][ty].size(); j++) {
				if (chess[tx][ty][j].first == i) { //�׿��ִ� ���� ��ġ�� �˾Ҵ�.

					int tmpdir = chess[tx][ty][j].second; //�̵�����
					int nextx = tx + dx[tmpdir]; int nexty = ty + dy[tmpdir];


					if (ground[nextx][nexty] == 0) { //���
						int erasecount = 0;
						for (int k = j; k < chess[tx][ty].size(); k++) {
							chess[nextx][nexty].push_back(chess[tx][ty][k]);
							horse[chess[tx][ty][k].first] = { nextx,nexty }; //���� ��ġ�� �ٲ�� �˷���� �Ѵ�.
							erasecount++;
						}
						while (erasecount--) { //�̵������� ����
							chess[tx][ty].pop_back(); 
						}
						break;
					}

					else if (ground[nextx][nexty] == 1) { //����
						int erasecount = 0;
						for (int k = chess[tx][ty].size() - 1; k >= j; k--) {
							chess[nextx][nexty].push_back(chess[tx][ty][k]);
							horse[chess[tx][ty][k].first] = { nextx,nexty };
							erasecount++;
						}
						while (erasecount--) {
							chess[tx][ty].pop_back();
						}
						break;
					}
					else { //�Ķ�
						//�̵����� �ݴ��

						if (tmpdir == 0) tmpdir = 1;
						else if (tmpdir == 1) tmpdir = 0;
						else if (tmpdir == 2) tmpdir = 3;
						else tmpdir = 2;

						chess[tx][ty][j].second = tmpdir;

						if (ground[tx + dx[tmpdir]][ty + dy[tmpdir]] == 2) { //�ݴ뵵 �Ķ���
							break;
						}
						else {
							j--;
						}// �ѹ� �� �ݺ�
					}
				}
			}
			//���� �̹Ƿ� !
			if (checkexit()) { cout << turncount; return 0; }
		}
		if (turncount > 1000) { cout << -1; return 0; }
	}
}