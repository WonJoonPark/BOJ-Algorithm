#include<iostream>
#include<vector>
using namespace std;

int map[102][102];
bool beflooded[102][102]; // 물에 잠겼거나 이미 안전구역으로 포함된 지역 체크
int n;
int xarr[4] = { 0,1,0,-1 }; //4방향 탐색을 이한 배열
int yarr[4] = { 1,0,-1,0 };
int howmanywaterflooded = 0;
void mapset() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}
void dfs(int x,int y) {
	beflooded[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (x + xarr[i] > 0 && x + xarr[i] < n + 1 && y + yarr[i]>0 && y + yarr[i] < n + 1) {
			if (beflooded[x + xarr[i]][y + yarr[i]] == false) {
				dfs(x + xarr[i], y + yarr[i]);
			}
		}
	}
}
void floodedcheck(int waterhe) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] <= waterhe) { beflooded[i][j] = true;
			howmanywaterflooded++;
			}
		}
	}
}
void befloodedclear() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			beflooded[i][j] = 0;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	mapset();
	int waterheight = 0;
	int maxsafetyareanum = -1;
	while (1) {
		howmanywaterflooded=0;
		befloodedclear();
		int tmpsafetyarea = 0;
		floodedcheck(waterheight);
		if (howmanywaterflooded == (n * n)) { break; }
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (beflooded[i][j] == false) {
					dfs(i, j);
					tmpsafetyarea++; 
				}
			}
		}
		if (tmpsafetyarea > maxsafetyareanum) { maxsafetyareanum = tmpsafetyarea; }
		waterheight++;
	}
	cout << maxsafetyareanum << '\n';
	return 0;
}