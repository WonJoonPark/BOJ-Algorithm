#include<bits/stdc++.h>
using namespace std;

int n,m,k;
bool sharkdie[401];
vector<int> sharkdir;
pair<int, int> sharks[401]; //���� ������ ��ġ (x,y)
vector<pair<int, int>> sea[21][21]; //first= ����ȣ, second= ���� k
int dirinfo[401][4][4];
int tmpint;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
//��.�Ʒ�,����,������
void inputs() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmpint;
			if (tmpint != 0) {
				sharks[tmpint].first = i; sharks[tmpint].second = j;
			}
		}
	}
	sharkdir.push_back(-1); // �ε��� ���߱� ��
	for (int i = 0; i < m; i++) {
		cin >> tmpint; sharkdir.push_back(tmpint-1); 
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> tmpint;
				dirinfo[i][j][k]=tmpint-1;
			}
		}
	}
}
bool boundcheck(int x, int y) {
	return (x >= 0 && y >= 0 && x < n&& y < n);
}
bool checksharks() {
	for (int i = 2; i <= m; i++) {
		if (sharkdie[i] == false) return false;
	}
	return true; //1�� ��� ���� �� �Ѱܳ�
}
int main() {
	inputs();
	int resultsecond=0;
	while (1) {
		if (resultsecond > 1000) { cout << -1; break; }
		if (checksharks()) { cout << resultsecond; break; }


		//���� k ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!sea[i][j].empty()) {
					sea[i][j][0].second--;
					if (sea[i][j][0].second == 0) {
						sea[i][j].clear();
					}
}
			}
		}

		//���� �Ѹ���
		for (int i = 1; i <= m; i++) {
			if (sharkdie[i] == false) { //�Ѱܳ��� �ʾҴٸ� ���� �Ѹ���.
				sea[sharks[i].first][sharks[i].second].clear();
				sea[sharks[i].first][sharks[i].second].push_back({ i,k });
			}
		}

		//�̵��ϱ�
		for (int i = 1; i <= m; i++) { //��� �Ѹ����� ����.
			if (sharkdie[i] == true) continue;
			bool suc = false;
			// ������ ���� ĭ�� �ִ��� ��������.
			for (int j = 0; j < 4; j++) {
				int nextx = sharks[i].first + dx[dirinfo[i][sharkdir[i]][j]];
				int nexty = sharks[i].second + dy[dirinfo[i][sharkdir[i]][j]];
				if (boundcheck(nextx, nexty) && sea[nextx][nexty].empty()) { //������ ���� ĭ
					sharks[i].first = nextx;
					sharks[i].second = nexty;
					suc = true;
					sharkdir[i] = dirinfo[i][sharkdir[i]][j]; //�̵��� ������ �����ִ� ������ �ȴ�.
					break;
				}
			}
			
			if (suc == false) {
				for (int j = 0; j < 4; j++) {
					int nextx = sharks[i].first + dx[dirinfo[i][sharkdir[i]][j]];
					int nexty = sharks[i].second + dy[dirinfo[i][sharkdir[i]][j]];
					if (boundcheck(nextx, nexty) && sea[nextx][nexty][0].first == i) { //�ڽ��� ������ �ִ� ĭ
						sharks[i].first = nextx;
						sharks[i].second = nexty;
						suc = true;
						sharkdir[i] = dirinfo[i][sharkdir[i]][j]; //�̵��� ������ �����ִ� ������ �ȴ�.
						break;
					}
				}
			}
		}



		// ��ġ�� ��� �ѾƳ���
		for (int i = 1; i <= m; i++) {
			if (sharkdie[i] == true) continue;
			for (int j = i + 1; j <= m; j++) {
				if (sharkdie[j] == true) continue;
				if (sharks[i].first == sharks[j].first && sharks[i].second == sharks[j].second) { // ������ �� �����
					sharkdie[j] = true; // �Ѱܳ��� (��ȣ�� �ʴ� ����)
				}
			}
		}
		resultsecond++;
	}
	return 0;
}