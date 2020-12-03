#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

char hosu[1501][1501];
bool visit[1501][1501];
int R, C;
int lx, ly,lx2,ly2;
int days;
int dx[4] = { 0,0,1,-1 }; //µ¿¼­³²ºÏ 4¹æÇâ Å½»ö
int dy[4] = { 1,-1,0,0 };
queue<pair<int,int>> waterqueue;
queue<pair<int, int>> icequeue;
pair<int, int> h;
bool check;

void inputs() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> hosu[i][j];
			if (hosu[i][j] == 'L') {
				if (check == false) { lx = i; ly = j; check = true; }
				else { lx2 = i; ly2 = j; }
			}
		}
	}
}
void bfs() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	bfs();
	cout << days << "\n";
	return 0;
}