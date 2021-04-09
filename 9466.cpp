#include<bits/stdc++.h>
using namespace std;

int students[100001];
bool checkvisit[100001];
bool alreadycycle[100001];
int n, T;
int teamcount = 0;

void dfs(int ti) {
	checkvisit[ti] = true;
	int nextti = students[ti];
	if (!checkvisit[nextti]) dfs(nextti); //방문
	if (checkvisit[nextti] && !alreadycycle[nextti]) { //방문했는데 사이클을 이루지 않은 경우
		for (int i = nextti; i != ti; i = students[i]) {
			teamcount++;
		}
		teamcount++; // ti
	}
	alreadycycle[ti] = true; // 하나의 집합 (그중 사이클이 있는지)
}

void visitclear() {
	for (int i = 1; i <= n; i++) {
		checkvisit[i] = 0; alreadycycle[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		visitclear();
		teamcount = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> students[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!checkvisit[i]) //방문하지 않았다면
				dfs(i);
		}
		cout << n - teamcount << "\n";
	}
	return 0;
}