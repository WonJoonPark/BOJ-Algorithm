#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, r; // 정점, 수색범위, 간선
int ground[101][101]; //간선정보 저장
int item[101];
int dist[101];
bool visited[101];
int n1, n2, l;
int maxresult = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tmpq; //거리

void inputs() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ground[i][j] = INF;
		}
	}
	for (int i = 1; i <= r; i++) {
		cin >> n1 >> n2 >> l;
		ground[n1][n2] = l;
		ground[n2][n1] = l;
	}
}

int ds(int starti) {
	int getitem = 0;
	tmpq.push({ 0,starti }); //dist
	dist[starti] = 0;
	while (!tmpq.empty()) {
		int ti = tmpq.top().second;
		int td = tmpq.top().first;
		tmpq.pop();
		visited[ti] = true;
		getitem += item[ti];
		for (int i = 1; i <= n; i++) {
			if (ground[ti][i] != INF && visited[i] == false) { //방문하지 않았고
				if (td + ground[ti][i] <= m&&td+ground[ti][i]<dist[i]) {
					tmpq.push({ td + ground[ti][i],i });
					dist[i] = td + ground[ti][i];
				}
			}
		}
	}
	return getitem;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	for (int i = 1; i <= n; i++) { //1~n 지역에 낙하할 수 있다.
		for (int j = 1; j <= n; j++) { //초기화
			visited[j] = false; dist[i] = INF;
		}
		int tmpmax = ds(i);
		maxresult = max(tmpmax, maxresult);
	}
	cout << maxresult;
	return 0;
}