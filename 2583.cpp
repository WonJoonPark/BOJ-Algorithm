#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[102][102]; // 2->사각형,1->이미 지나간곳,0->갈수있는곳
int xarr[4] = { -1,0,1,0 }; //4방향 탐색을 위하여
int yarr[4] = { 0,-1,0,1 };
int M, N, K;
vector<int> area;
int areanum;
void squaresetting(int x1, int y1, int x2, int y2) {
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			map[j][i] = 2; //사각형이 있는곳
		}
	}
}
void dfs(int x, int y) {
	map[x][y] = 1; //지나간곳으로 표시
	areanum++; // 지역별 넓이를 계산하기 위하여 
	for (int i = 0; i < 4; i++) {
		if (x + xarr[i] >= 0 && y + yarr[i] >= 0 && x + xarr[i] < N&& y + yarr[i] < M) {
			if (map[x + xarr[i]][y + yarr[i]] == 0) {
				dfs(x + xarr[i], y + yarr[i]);
			}
		}
	}
}
bool cmp(int a, int b) {
	if (a < b) return true;
	else return false;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> M >> N >> K;
	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		squaresetting(x1, y1, x2, y2);
	}
	int areacount = 0;
	for (int i = 0;i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 0) {
				 areanum = 0;
				areacount++;
				dfs(j, i);
				area.push_back(areanum);
			}
		}
	}
	sort(area.begin(), area.end(), cmp);
	cout << areacount << '\n';
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}
	cout << '\n';
	return 0;
}