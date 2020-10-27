#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct xy {int x;int y;};
int arrx[4] = { 1,0,-1,0 };
int arry[4] = { 0,1,0,-1 };
int N, M;
int map[10][10];
int mapstored[10][10];
queue<xy> tmpq; //bfs 수행을 위한 큐
vector<xy> tmpv; //벽을 세울수 있는 공간을 넣어 놓을 것
int maxresult = 0; //출력할 안전 영역의 최대크기
int virusnum = 0;
int wallnum = 3; //3개를 무조건 세울것이므로

void setting() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = 1;
			mapstored[i][j] = 1;
		}
	}
}
int tmpx, tmpy;
xy tmp;
void bfs() {
	while (1) {
		if (tmpq.empty() == true) { break; }
		for (int i = 0; i < tmpq.size(); i++) {
			tmpx = (tmpq.front()).x;
			tmpy = (tmpq.front()).y;
			tmpq.pop();
			for (int j = 0; j < 4; j++) {
				if (map[tmpx + arrx[j]][tmpy + arry[j]] == 0) {
					map[tmpx + arrx[j]][tmpy + arry[j]] = 2; //바이러스 감염
					virusnum++;
					tmp.x = tmpx + arrx[j];
					tmp.y = tmpy + arry[j];
					tmpq.push(tmp); //큐에 삽입
				}
			}
		}
	}
}
void setmap() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = mapstored[i][j];
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	setting();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			mapstored[i][j] = map[i][j];
			if (map[i][j] == 2) { tmp.x = i; tmp.y = j; 
			tmpq.push(tmp); 
			virusnum++;
			}
			if (map[i][j] == 0) {
			tmp.x = i; tmp.y = j;
			tmpv.push_back(tmp); //벽이 세워질 수 있는 자리들
			}
			if (map[i][j] == 1) {
			wallnum++;
			}
		}
	}
	int virusstored = virusnum;
	int tmpmax = 0;
	queue<xy> qstored = tmpq;
	for (int i = 0; i < tmpv.size() - 2; i++) {
		map[tmpv[i].x][tmpv[i].y] = 1;
		for (int j = i + 1; j < tmpv.size() - 1; j++) {
			map[tmpv[j].x][tmpv[j].y] = 1;
			for(int k=j+1;k<tmpv.size();k++){
				map[tmpv[k].x][tmpv[k].y] = 1;
				virusnum = virusstored;
				tmpmax = 0;
				tmpq = qstored;
				bfs();
				tmpmax = (N*M) - wallnum - virusnum;
				if (maxresult < tmpmax) {
					maxresult = tmpmax;
				}
				setmap();
				map[tmpv[j].x][tmpv[j].y] = 1;
				map[tmpv[i].x][tmpv[i].y] = 1;
			}
			map[tmpv[j].x][tmpv[j].y] = 0;
		}
		map[tmpv[i].x][tmpv[i].y] = 0;
	}
	cout << maxresult << '\n';
	return 0;
}
