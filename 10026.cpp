#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N;
char RGBmap1[101][101];
char RGBmap2[101][101]; //적록색맹을 위한
bool visit1[101][101];
bool visit2[101][101];
int dx[4] = { 0,0,1,-1};
int dy[4] = { 1,-1,0,0 };
int NotRGBcant;
int RGBcant;

void inputs() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>RGBmap1[i][j];
			if (RGBmap1[i][j] == 'R' || RGBmap1[i][j] == 'G') RGBmap2[i][j] = 'R';
			else RGBmap2[i][j] = 'B';
		}
	}
}
void dfs1(int x, int y,char c) {
	visit1[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < N &&y + dy[i] >= 0 && y + dy[i] < N) {
			if (visit1[x + dx[i]][y + dy[i]] == false && RGBmap1[x + dx[i]][y + dy[i]] == c) {
				dfs1(x + dx[i], y + dy[i], c);
			}
		}
	}
}
void dfs2(int x, int y, char c) {
	visit2[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < N &&y + dy[i] >= 0 && y + dy[i] < N) {
			if (visit2[x + dx[i]][y + dy[i]] == false && RGBmap2[x + dx[i]][y + dy[i]] == c) {
				dfs2(x + dx[i], y + dy[i], c);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit1[i][j] == false) { dfs1(i, j,RGBmap1[i][j]); NotRGBcant++; }
			if (visit2[i][j] == false) { dfs2(i, j, RGBmap2[i][j]); RGBcant++;}
		}
	}
	cout << NotRGBcant <<" "<< RGBcant<<"\n";
	

	return 0;
}