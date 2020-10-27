#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 1e9 

//간선의 가중치가 모두 1이니 일단 bfs 두번사용
int n, m, x, k;
int startcity, arrivecity;
int map[101][101];
bool visit[101];
int startpoint = 1;
int resultcount = 0;



int main() {
	cin >> n >> m;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			map[i][j] = INF; //무한대로 초기화
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> startcity >> arrivecity;
		map[startcity][arrivecity] = 1; //non-directed graph 이므로 양방향 표시
		map[arrivecity][startcity] = 1;
	}
	cin >> x >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				map[i][k] = min(map[i][k], map[i][j] + map[j][k]);
			}
		}
	}
	resultcount = map[startpoint][k] + map[k][x];
	if (resultcount >= INF) { cout << -1 << "\n"; }
	else { cout << resultcount << "\n"; }

	return 0;
}