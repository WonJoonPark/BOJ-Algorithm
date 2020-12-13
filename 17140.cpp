#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int r, c, k;
int numarr[100][100]; //0~99 index는 1더해서 생각
pair<int,int> countarr[101]; //등장 횟수를 카운트 하기 위해 사용
int minresult=101;
char command[2] = { 'R','C' };

bool compare(pair<int, int> &l, pair<int, int> &r) {
	if (l.second < r.second) return true;
	else if (l.second == r.second) {
		if (l.first < r.first) return true;
		else return false;
	}
	else return false;
}
void inputs() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++)
			cin >> numarr[i][j];
}
void resetcountarr() {
	for (int i = 0; i < 101; i++)
	{
		countarr[i].first = 0;
		countarr[i].second = 0;
	}
}
void resethang(int a) {
	for (int b = 0; b < 100; b++) numarr[a][b] = 0;
}
void resetyull(int a) {
	for (int b = 0; b < 100; b++) numarr[b][a] = 0;
}
int hindex = 3;
int yindex = 3;

void sortingarr(char c) {
	if(c=='R'){
		
	}
	else {
	}
}

void checkcase(int cnt) {
	if (numarr[r-1][c-1] == k) {
		if (cnt < minresult) {
			minresult = cnt; return;
		}
	}
	if (cnt >= 100) { return; }
	for (int i = 0; i < 2; i++) {
		int tmph = hindex;
		int tmpy = yindex;
		sortingarr(command[i]);
		checkcase(cnt + 1);
		hindex = tmph;
		yindex = tmpy;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	checkcase(0);
	if (minresult==101) cout << -1 << "\n";
	else { cout << minresult << "\n"; }


	return 0;
}