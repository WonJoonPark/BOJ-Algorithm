#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int tetro[501][501];
int maxvalue = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[501][501];
int depth = 0;
int tmpsum;

void dfs(int x, int y) {
	if (depth == 4) {
		if (tmpsum > maxvalue) maxvalue = tmpsum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if (x2 >= 0 && x2 < N &&y2 >= 0 && y2 < M && visit[x2][y2]==false) {
			visit[x2][y2] = true;
			depth++;
			tmpsum += tetro[x2][y2];
			dfs(x2, y2);
			tmpsum -= tetro[x2][y2];
			depth--;
			visit[x2][y2] = false;
		}
	}
}

void cantdfs(int x, int y)
{
	int result = 0;
	if (x - 1 >= 0 && y + 2 < M) {// คว
		result = tetro[x][y] + tetro[x][y + 1] + tetro[x][y + 2] + tetro[x - 1][y + 1];
		if (result > maxvalue) maxvalue = result;
	}
	if (x + 1 < N &&y + 2 < M) { // คฬ
		result = tetro[x][y] + tetro[x][y + 1] + tetro[x][y + 2] + tetro[x + 1][y + 1];
		if (result > maxvalue) maxvalue = result;
	}
	if (x + 1 < N &&x - 1 >= 0 && y + 1 < M) { // คร
		result = tetro[x][y] + tetro[x][y + 1] + tetro[x - 1][y + 1] + tetro[x + 1][y + 1];
		if (result > maxvalue) maxvalue = result;
	}
	if (x + 2 < N &&y + 1 < M) {
		result = tetro[x][y] + tetro[x + 1][y] + tetro[x + 2][y] + tetro[x + 1][y + 1];
		if (result > maxvalue) maxvalue = result;
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tetro[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			depth = 1;
			tmpsum = tetro[i][j];
			visit[i][j] = true;
			dfs(i, j);
			visit[i][j] = false;
			cantdfs(i, j);
		}
	}
	cout << maxvalue << "\n";

	return 0;
}