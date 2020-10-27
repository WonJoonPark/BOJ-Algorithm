#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int icebox[1002][1002];
bool visit[1002][1002];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int resultcount = 0;

void boxset() {
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 1002; j++) {
			icebox[i][j] = 1;
		}
	}
}
void dfssearch(int i, int j) {
	visit[i][j] = true;
	for (int k = 0; k < 4; k++) {
		if (icebox[i + dx[k]][j + dy[k]] == 0 && visit[i + dx[k]][j + dy[k]] == false) {
			dfssearch(i + dx[k], j + dy[k]);
		}
	}
}

int main() {
	int N, M;
	boxset();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &icebox[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (icebox[i][j]==0 && visit[i][j]== false)
			{
				resultcount++; dfssearch(i, j); }
		}
	}
	cout << resultcount << "\n";
	return 0;
}