#include<iostream>
#include<queue>
using namespace std;

bool visit[202][202];
int map[202][202];
int resultcount = 1;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

struct xy {
	int x, y;
};
xy tmpxy;
queue<xy> tmpqueue;

void bfssearch(xy tt,int N,int M) {
	int tx, ty,tsize;
	tmpqueue.push(tt);
	while (1) {
		resultcount++;
		tsize = tmpqueue.size();
		for (int i = 0; i < tsize; i++) {
			tx = tmpqueue.front().x;
			ty = tmpqueue.front().y;
			tmpqueue.pop();
			for (int j = 0; j < 4; j++) {
				if (map[tx + dx[j]][ty + dy[j]] == 1 && visit[tx + dx[j]][ty + dy[j]] == false) {
					if (tx + dx[j] == N && ty + dy[j] == M) { return; }
					tmpxy.x = tx + dx[j]; tmpxy.y = ty + dy[j];
					tmpqueue.push(tmpxy);
				}
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
}
	tmpxy.x = 1;
	tmpxy.y = 1;
	visit[1][1] = true;
	bfssearch(tmpxy,N,M);
	cout << resultcount<<endl;

	return 0;
}
