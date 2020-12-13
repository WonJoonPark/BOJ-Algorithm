#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int N;
int x, y, d, g;
bool visit[102][102];
int resultcount;
int dy[4] = { 0,-1,0,1 };// 동북서남(0,1,2,3)
int dx[4] = { 1,0,-1,0 };
int dragon[1024];
void setvisit() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visit[i][j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	setvisit();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		dragon[0] = d;
		visit[y][x] = true;
		//드래곤커브 방향 구하기
		for (int j = 1; j <= g; j++) { //세대별로
			int reverseindex = pow(2, j - 1) - 1;
			for (int k = pow(2, j - 1); k < pow(2, j); k++) {
				dragon[k] = (dragon[reverseindex] + 1) % 4;
				reverseindex--;
			}
		}
		for (int j = 0; j < pow(2, g); j++) {//방문처리
				x += dx[dragon[j]]; y += dy[dragon[j]];
				visit[y][x] = true;
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (visit[i][j] == true && visit[i + 1][j] == true && visit[i][j + 1] == true && visit[i + 1][j + 1] == true)
				resultcount++;
		}
	}
	cout << resultcount << "\n";
	return 0;
}