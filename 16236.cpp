#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int sea[21][21];
bool visited[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N;

void inputs() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sea[i][j];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();




	return 0;
}