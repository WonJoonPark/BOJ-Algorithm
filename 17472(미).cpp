#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct bridge {
	int fisland, seisland;
	int len;
};

int selected[101]; //조합을 위한
int dx[4] = { 0,0,1,-1 }; //4방향 탐색 dfs
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
	visited[x][y] = true; //방문처리
	ground[x][y] = islandnum; //섬 번호 매기기 1~
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
	for (int i = 0; i < N; i++) { //가로방향탐색
		for (int j = 0; j < M; j++) {
			if (ground[i][j] != 0 &&j<M-2) {
				if(ground[i][j+1]==0){
					for (int k = j + 2; k < M; k++) {
						if (ground[i][k] != 0) { // 다른섬 발견
							bridge tmp;
							tmp.fisland = ground[i][j]; //몇번 섬과
							tmp.seisland= ground[i][k]; //몇번 섬을 연결하는 다리
							tmp.len = k-j-1; //
							psset.push_back(tmp);
							j = k; break; //다리 놓은 만큼 탐색 좌표를 jump
						}
					}
				}
			}
		}
	}
	//세로방향탐색
	for (int i = 0; i < N; i++) { //가로방향탐색
		for (int j = 0; j < M; j++) {
			if (ground[j][i] != 0 && j < M - 2) {
				if (ground[j+1][i] == 0) {
					for (int k = j + 2; k < M; k++) {
						if (ground[k][i] != 0) { // 다른섬 발견
							bridge tmp;
							tmp.fisland = ground[j][i]; //몇번 섬과
							tmp.seisland = ground[k][i]; //몇번 섬을 연결하는 다리
							tmp.len = k - j - 1; //
							psset.push_back(tmp);
							j = k; break; //다리 놓은 만큼 탐색 좌표를 jump
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
void startsimul() { //3개의 다리가 모든 섬을 연결 하는지 체크해야한다.
	vector<int> connected[101];
	bool cone[101];
	resetcone();
	for (int i = 0; i < simulset.size(); i++) {
		connected[simulset[i].fisland].push_back(simulset[i].seisland); //간선 연결 표시
		connected[simulset[i].seisland].push_back(simulset[i].fisland);
	}
	cone[1] == true; //1번 섬부터 시작
	int startisland = connected[1][0];
	while (1) {
		if (connected[startisland].empty() == true) {
			//다 방문 했는지 확인하고 !
			break;
		}
		for (int i = 0; i < connected[startisland].size(); i++) {

		}
	}
}
void makeset(int idx,int n) {
	if (n == (islandnum-1)) { //최소 필요한 다리
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
	namingisland(); //섬 번호 매기기
	possiblebridgeset();
	watch();
	for (int i = 0; i < psset.size(); i++) {
		cout << psset[i].fisland << " " << psset[i].seisland <<" "<< psset[i].len << endl;
	}
	makeset(0,0);

	return 0;
}