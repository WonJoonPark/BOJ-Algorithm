#include<iostream>
#include<vector>
using namespace std;

int totalcount=0;
int housemap[17][17];
int N;
int x=1;
int y=2;
int dx[3] = { 0,1,1 }; //����,����,�밢���̵�
int dy[3] = { 1,0,1 };
int direction = 0; // ����,����,�밢�� ����
void startsearch(int x,int y,int d) {
	if (x > N || y > N) return; //��������(�̵���)
	if (x == N && y == N) { totalcount++; return; } //��������(����
	if (d == 0) {
		if (housemap[x + dx[0]][y + dy[0]] != 1) 
		startsearch(x + dx[0], y + dy[0], 0); //case 1
		if (housemap[x + dx[2]][y + dy[2]] != 1 && housemap[x + dx[1]][y + dy[1]] != 1 && housemap[x + dx[0]][y + dy[0]] != 1) 
		startsearch(x + dx[2], y + dy[2], 2); //case 2
	}
	else if (d == 1) {
		if (housemap[x + dx[1]][y + dy[1]] != 1) 
		startsearch(x + dx[1], y + dy[1], 1); //case 3
		if (housemap[x + dx[2]][y + dy[2]] != 1 && housemap[x + dx[1]][y + dy[1]] != 1 && housemap[x + dx[0]][y + dy[0]] != 1)
		startsearch(x + dx[2], y + dy[2], 2); //case 4
	}
	else {
		if (housemap[x + dx[0]][y + dy[0]] != 1)
		startsearch(x + dx[0], y + dy[0], 0); //case 5
		if (housemap[x + dx[1]][y + dy[1]] != 1) 
		startsearch(x + dx[1], y + dy[1], 1); //case 6
		if (housemap[x + dx[2]][y + dy[2]] != 1 && housemap[x + dx[1]][y + dy[1]] != 1 && housemap[x + dx[0]][y + dy[0]] != 1) 
		startsearch(x + dx[2], y + dy[2], 2); //case 7
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> housemap[i][j];
		}
	}
	if (housemap[N][N]!=1) { startsearch(x, y, direction); }
	cout << totalcount << "\n";
	return 0;
}