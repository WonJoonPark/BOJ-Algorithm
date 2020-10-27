#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int xarr[8]={ -1, 0, 1, 0,-1,0,1,0 };
int yarr[8]={ 0, 1, 0, -1,0,1,0,-1 };

int map[52][52];
int clean_count = 0;
int N, M;
int r, c;
int direction; // 0(合率),1(悼率),2(巢率),3(辑率)
void set() {
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			map[i][j] == 0;
		}
	}
}
vector<int> dx0;
vector<int> dy0;
void setdirect() {
	for (int i = 0; i < 4; i++) {
		dx0.push_back(xarr[4 - direction + i]);
		dy0.push_back(yarr[4 - direction + i]);
	}
}
void dfs(int x, int y) {
	map[x][y] = 2;//没家甫 沁促.
	clean_count++;
	for (int i = 0; i < 4; i++) {
		if (map[x + dx0[i]][y + dy0[i]] == 0) {
			dfs(x + dx0[i], y + dy0[i]);
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	cin >> r >> c >> direction;
	set();
	setdirect();
	for (int i = 0; i < 4; i++) {
		cout << dx0[i] << ' ';
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	

	return 0;
}