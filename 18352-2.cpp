#include<bits/stdc++.h>
using namespace std;

int n, m, k, x;
vector<int> citoci[300001];
bool visited[300001];
queue<int> tmpq;
int x1, x2;

void bfs() {
	int dis = 0;
	while (1) {
		if (tmpq.empty()) {
			cout << -1; return;
		}
		if(dis==k){
			vector<int> outputv;
			while (!tmpq.empty()) {
				outputv.push_back(tmpq.front());
				tmpq.pop();
			}
			sort(outputv.begin(), outputv.end());
			int s = outputv.size();
			for (int i = 0; i < s; i++) {
				cout << outputv[i] << "\n";
			}
			return;
		}
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front();
			tmpq.pop();
			int vsize = citoci[nextx].size();
			for (int i = 0; i < vsize; i++) {
				if (visited[citoci[nextx][i]] == false) {
					tmpq.push(citoci[nextx][i]);
					visited[citoci[nextx][i]] = true;
				}
			}
		}
		dis++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> x2;
		citoci[x1].push_back(x2);
	}
	tmpq.push(x);
	visited[x] = true;
	bfs();

	return 0;
}