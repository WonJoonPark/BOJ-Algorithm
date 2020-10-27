#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M, V; 
bool graph[1001][1001];
bool jum[1001];
queue<int> ff;
queue<int> ss;
void clear() {
	for (int i = 1; i <= N; i++) {
		jum[i] = 0;
	}
}
void dfs(int v) {
	cout << v << " ";
	jum[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1&&jum[i]!=1) {
			dfs(i);
		}
	}
}
void bfs() {
	while (1) {
		if (ff.size() == 0) { break; }
		int ffsize = ff.size();
		int tmpjum;
		for (int i = 0; i < ffsize; i++) {
			cout << ff.front() << " ";
			tmpjum = ff.front();
			for (int j = 1; j <= N; j++) {
				if (graph[tmpjum][j] == 1 && jum[j] != 1) {
					ff.push(j);
					jum[j] = 1;
				}
			}
			ff.pop();
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> V;
	int tmpx, tmpy;
	for(int i=0;i<M;i++){
		cin >> tmpx >> tmpy;
		graph[tmpx][tmpy] = 1;
		graph[tmpy][tmpx] = 1;
	}
	dfs(V);
	cout << '\n';
	clear();//방문기록 초기화
	ff.push(V);
	jum[V] = 1;
	bfs();
	return 0;
}