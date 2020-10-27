#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int countt = 0;
vector<int> resultarr;
int countjip;
int map[26][26];
bool check[26][26];
int xarr[4] = { 1,0,-1,0 }; //ÁÂÇ¥ÀÌµ¿
int yarr[4] = { 0,1,0,-1 };// ÁÂ,¿ì,À§,¾Æ·¡
void dfs(int x, int y) {
	countjip++;
	check[x][y] = 1; 
	for (int k = 0; k < 4; k++) {
		if (x+xarr[k]>=0&&y+yarr[k]>=0&&x+xarr[k]<N&&y+yarr[k]<N) {
			if (map[x + xarr[k]][y+ yarr[k]] == 1 && check[x + xarr[k]][y + yarr[k]] != 1) {
				dfs(x + xarr[k], y + yarr[k]);
			}
		}
	}
}
int main() {
	cin >> N;
	char tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && check[i][j] != 1) {
				countt++;
				countjip = 0;
				dfs(i, j);
				resultarr.push_back(countjip);
			}
		}
	}
	cout << countt << '\n';
	sort(resultarr.begin(), resultarr.end());
	for (int i = 0; i < countt; i++) {
		cout << resultarr[i] << '\n';
	}
	return 0;
}