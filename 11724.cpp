#include<iostream>
#include<vector>
using namespace std;

int N, M;
bool check[1001];
vector<int> connectedinfo[1001];
int resultcount = 0;
bool newcount=0;
void dfs(int index) {
	if (connectedinfo[index].size() == 0) { return; }
	if (check[index] == 1) { return; }//이미 방문한 노드면 끝
	check[index] = 1;//방문했음을 체크
	for (int i = 0; i < connectedinfo[index].size(); i++) {
		dfs(connectedinfo[index][i]);
	}
	newcount = 1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	int tmp1, tmp2;
	while (M--) {
		cin >> tmp1 >> tmp2;
		connectedinfo[tmp1].push_back(tmp2);
		connectedinfo[tmp2].push_back(tmp1);
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) {
			resultcount++;
			dfs(i);
		}
	}
	cout << resultcount << '\n';
	return 0;
}