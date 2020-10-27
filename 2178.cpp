#include<iostream>
#include<queue>
using namespace std;

int N, M;
bool map[101][101];
bool check[101][101];
int xarr[4] = { 0,1,0,-1 };
int yarr[4] = { 1,0,-1,0 };

struct kan {
	int x;
	int y;
};
queue<kan> arrr;
int countt;
bool ch;
void bfs() {
	while (1) {
		if (ch == true) { break; }
		int ksize = arrr.size();
		kan tmpkan;
		kan tmp2kan;
		for (int i = 0; i < ksize; i++) {
			tmpkan = arrr.front();
			if (tmpkan.x == N && tmpkan.y == M) { cout << countt << '\n'; ch = 1; break; }
			for (int j = 0; j < 4; j++) {
				if (tmpkan.x + xarr[j] >= 1 && tmpkan.x + xarr[j] <= N && tmpkan.y + yarr[j] >= 1 && tmpkan.y + yarr[j] <= M) {
					if (map[tmpkan.x + xarr[j]][tmpkan.y + yarr[j]] == 1 && check[tmpkan.x + xarr[j]][tmpkan.y + yarr[j]] != 1) {
						tmp2kan.x = tmpkan.x + xarr[j];
						tmp2kan.y = tmpkan.y + yarr[j];
						check[tmp2kan.x][tmp2kan.y] = 1;
						arrr.push(tmp2kan);
					}
				}
			}
			arrr.pop();
		}
		countt++;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	kan tmpk;
	tmpk.x = 1;
	tmpk.y = 1;
	arrr.push(tmpk);
	countt++;
	bfs();
	return 0;
}