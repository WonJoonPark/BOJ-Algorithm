#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


//간선의 가중치가 모두 1이니 일단 bfs 두번사용
int n, m, x, k;
int startcity, arrivecity;
int map[101][101];
bool visit[101];
int startpoint=1;
int resultcount = 0;
queue<int> tmpqueue;

int bfs(int s, int d) {
	tmpqueue.push(s);
	while (1) {
		if (tmpqueue.empty() == true) { return 1; }
		int tmpsize = tmpqueue.size();
		while (tmpsize--) {
			int tmpcity = tmpqueue.front();
			if (tmpcity == d) { return 0; } //탐색종료조건
			visit[tmpcity] = true;
			tmpqueue.pop();
			for (int i = 1; i <= n; i++) {
				if (map[tmpcity][i] == 1&&visit[i]==false) {
					tmpqueue.push(i);
				}
			}
		}
		resultcount++;
	}
}
void resetvisit() {
	for (int i = 0; i < 101; i++) {
		visit[i] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> startcity >> arrivecity;
		map[startcity][arrivecity] = 1; //non-directed graph 이므로 양방향 표시
		map[arrivecity][startcity] = 1;
	}
	cin >> x >> k;
	int result=bfs(startpoint, k);
	if (result == 1) { cout << -1 << "\n"; return 0; }
	resetvisit();
	result=bfs(k, x);
	if (result == 1) { cout << -1 << "\n"; return 0; }
	cout << resultcount << "\n";

	return 0;
}