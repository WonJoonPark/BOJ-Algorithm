#include<bits/stdc++.h>
using namespace std;

int n, m, K;
int ground[11][11]; // 양분의 양
vector<int> treeageset[11][11]; //나이 기준 정렬
int s2d2[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int tmpv[1001];
int presize[11][11]; 

void inputs() {
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ground[i][j] = 5;
			cin >> s2d2[i][j];
		}
	}
	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		treeageset[x][y].push_back(z);
	}
}
bool boundcheck(int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	for (int i = 0; i < K; i++) { //1년

		//봄
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (treeageset[j][k].empty()) continue;
				int tmpground = ground[j][k];
				ground[j][k] = 0;
				sort(treeageset[j][k].begin(), treeageset[j][k].end());
				int vsize = treeageset[j][k].size();
				for (int a = 0; a < vsize; a++) {
					if (tmpground >= treeageset[j][k][a]) {
						tmpground -= treeageset[j][k][a];
						treeageset[j][k][a]++;
					}
					else {
						for (int b = vsize - 1; b >= a; b--) {
							ground[j][k] += treeageset[j][k][b] / 2;
							treeageset[j][k].pop_back();
						}
						break;
					}
				}
				ground[j][k] += tmpground; //남은 양분+죽은나무의 양분
			}
		}

	for (int j = 1; j <= n; j++) { 
		for (int k = 1; k <= n; k++) {
			presize[j][k] = treeageset[j][k].size();
		}
	}
	//가을 번식
	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= n; k++) {
			for (int a = 0; a < presize[j][k]; a++) {
				if (treeageset[j][k][a] % 5 == 0) {
					for (int b = 0; b < 8; b++) {
						int nextx = j + dx[b];
						int nexty = k + dy[b];
						if (boundcheck(nextx, nexty)) {
							treeageset[nextx][nexty].push_back(1);
						}
					}
				}
			}
			ground[j][k] += s2d2[j][k]; //양분 보급
		}
	}
}
	int resultsum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			resultsum += treeageset[i][j].size();
		}
	}
	cout << resultsum;
	return 0;
}