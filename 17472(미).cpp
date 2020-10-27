#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct bridge {
	int fisland, seisland;
	int len;
};

int selected[101]; //������ ����
int dx[4] = { 0,0,1,-1 }; //4���� Ž�� dfs
int dy[4] = { 1,-1,0,0 };
int N, M;
int ground[11][11];
bool visited[11][11];
int islandnum = 1;
int minresult = 101;
vector<bridge> psset;
vector<bridge> simulset;

void inputs() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ground[i][j];
		}
	}
}
void dfs(int x, int y) {
	visited[x][y] = true; //�湮ó��
	ground[x][y] = islandnum; //�� ��ȣ �ű�� 1~
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i]<0 || y + dy[i] >= M) continue;
		if (ground[x + dx[i]][y + dy[i]] == 1&&visited[x+dx[i]][y+dy[i]]==false) {
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

void namingisland() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ground[i][j] == 1&&visited[i][j]==false) {
				dfs(i, j);
				islandnum++;
			}
		}
	}
}

void watch() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ground[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void possiblebridgeset() {
	for (int i = 0; i < N; i++) { //���ι���Ž��
		for (int j = 0; j < M; j++) {
			if (ground[i][j] != 0 &&j<M-2) {
				if(ground[i][j+1]==0){
					for (int k = j + 2; k < M; k++) {
						if (ground[i][k] != 0) { // �ٸ��� �߰�
							bridge tmp;
							tmp.fisland = ground[i][j]; //��� ����
							tmp.seisland= ground[i][k]; //��� ���� �����ϴ� �ٸ�
							tmp.len = k-j-1; //
							psset.push_back(tmp);
							j = k; break; //�ٸ� ���� ��ŭ Ž�� ��ǥ�� jump
						}
					}
				}
			}
		}
	}
	//���ι���Ž��
	for (int i = 0; i < N; i++) { //���ι���Ž��
		for (int j = 0; j < M; j++) {
			if (ground[j][i] != 0 && j < M - 2) {
				if (ground[j+1][i] == 0) {
					for (int k = j + 2; k < M; k++) {
						if (ground[k][i] != 0) { // �ٸ��� �߰�
							bridge tmp;
							tmp.fisland = ground[j][i]; //��� ����
							tmp.seisland = ground[k][i]; //��� ���� �����ϴ� �ٸ�
							tmp.len = k - j - 1; //
							psset.push_back(tmp);
							j = k; break; //�ٸ� ���� ��ŭ Ž�� ��ǥ�� jump
						}
					}
				}
			}
		}
	}
}
void resetcone() {
	for (int i = 0; i < 101; i++) {
		cone[i] = false;
	}
}
void startsimul() { //3���� �ٸ��� ��� ���� ���� �ϴ��� üũ�ؾ��Ѵ�.
	vector<int> connected[101];
	bool cone[101];
	resetcone();
	for (int i = 0; i < simulset.size(); i++) {
		connected[simulset[i].fisland].push_back(simulset[i].seisland); //���� ���� ǥ��
		connected[simulset[i].seisland].push_back(simulset[i].fisland);
	}
	cone[1] == true; //1�� ������ ����
	int startisland = connected[1][0];
	while (1) {
		if (connected[startisland].empty() == true) {
			//�� �湮 �ߴ��� Ȯ���ϰ� !
			break;
		}
		for (int i = 0; i < connected[startisland].size(); i++) {

		}
	}
}
void makeset(int idx,int n) {
	if (n == (islandnum-1)) { //�ּ� �ʿ��� �ٸ�
		minresult = 101;
		startsimul();
		return;
	}
	for (int i = idx; i < psset.size(); i++) {
		if (selected[i] == 1) continue;
		simulset.push_back(psset[i]);
		n++;
		selected[i] = 1;
		makeset(idx + 1, n);
		selected[i] = 0;
		n--;
		simulset.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	inputs();
	namingisland(); //�� ��ȣ �ű��
	possiblebridgeset();
	watch();
	for (int i = 0; i < psset.size(); i++) {
		cout << psset[i].fisland << " " << psset[i].seisland <<" "<< psset[i].len << endl;
	}
	makeset(0,0);

	return 0;
}