#include<bits/stdc++.h>
using namespace std;

int n;
int maxresult = 0;
int numarr[101];
bool visited[101];
bool alreadycycle[101];
vector<int> resultarr;

void inputs() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numarr[i];
	}
}
void dfs(int x) {
	visited[x] = true;
	int nextx = numarr[x];
	if (visited[nextx] == false) {
		dfs(nextx);
	}
	else if (alreadycycle[nextx] == false) { //온만큼 돌아가면서 사이클을 계산
		resultarr.push_back(x);
		maxresult++;
		int tmp = nextx;
		while (1) {
			if (tmp == x) break;
			maxresult++;
			resultarr.push_back(tmp);
			tmp = numarr[tmp];
		}
	}
	alreadycycle[x] = true; //이미 사이클안에 들어가 있음.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	for (int i = 1; i <= n; i++) {//탐색
		if (visited[i] == false) {
			dfs(i);
		}
	}
	cout << maxresult << "\n";
	sort(resultarr.begin(), resultarr.end());
	for (int i = 0; i < resultarr.size(); i++) {
		cout << resultarr[i] << "\n";
	}

	return 0;
}