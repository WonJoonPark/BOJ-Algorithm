#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

queue<int> tmpqueue;
vector<int> edge[300001]; //간선정보저장
bool visited[300001]; //방문정보 저장
int N, M, K, X;
int loadlength;

void inputedge() { //간선정보를 저장
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		edge[x].push_back(y);
	}
}

void resultoutput() { //오름차순 정렬 (큐에서 벡터로 옴겨서)
	vector<int> resultsave;
	while (tmpqueue.empty()!=true) {
		resultsave.push_back(tmpqueue.front());
		tmpqueue.pop();
	}
	sort(resultsave.begin(), resultsave.end());
	for (int i = 0; i < resultsave.size(); i++) {
		cout << resultsave[i] << "\n";
	}
}

void bfs(int X) {
	tmpqueue.push(X);
	visited[X] = true;
	while (1) {
		if (tmpqueue.empty()) { cout << -1 << "\n"; break; }
		if (loadlength == K) { resultoutput(); break; }
		int qsize = tmpqueue.size();
		while(qsize--){
			int startnode = tmpqueue.front();
			for (int i = 0; i < edge[startnode].size(); i++) {
				if (visited[edge[startnode][i]] == false) {
					tmpqueue.push(edge[startnode][i]);
					visited[edge[startnode][i]] = true;
				}
			}
			tmpqueue.pop();
		}
		loadlength++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> X;
	inputedge();
	bfs(X);

	return 0;
}