#include<bits/stdc++.h>
using namespace std;

// 시작노드 0, 도착점 노드 21
int route[4][33];
int score[33]; // 점수계산을 위한 노드
int maxresult;
int inputnum[10];
pair<int, int> ob[4]; //4개의말 (현재위치, 타고있는 방향)

void inputs() {
	for (int i = 0; i < 10; i++) {
		cin >> inputnum[i];
	}
}
void setscore() {
	for (int i = 1; i <= 20; i++) {
		score[i] = 2 * i;
	}
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[25] = 25; score[30] = 26; score[29] = 27;
	score[28] = 28; score[26] = 22; score[27] = 24;
	score[31] = 30; score[32] = 35; score[21] = 0;
}
void makegraph() {
	for (int i = 0; i < 21; i++) {
		route[0][i] = i + 1;
	}
	route[0][21] = 21;
	route[1][5] = 22; route[1][22] = 23; route[1][23] = 24;
	route[1][24] = 25; route[1][25] = 31; route[1][31] = 32;
	route[1][32] = 20; route[1][20] = 21; route[1][21] = 21;
	route[2][10] = 26; route[2][26] = 27; route[2][27] = 25;
	route[2][25] = 31; route[2][31] = 32; route[2][32] = 20;
	route[2][20] = 21; route[2][21] = 21;
	route[3][15] = 28; route[3][28] = 29; route[3][29] = 30;
	route[3][30] = 25; route[3][25] = 31; route[3][31] = 32;
	route[3][32] = 20; route[3][20] = 21; route[3][21] = 21;
}
bool existcheck(int s,int index) {
	if (s == 21) return false;
	for (int i = 0; i < 4; i++) {
		if (i == index) continue;
		if (ob[i].first == 21) continue;
		if (ob[i].first == s) return true;
	}
	return false;
}
void makecase(int cnt,int resultsum) {
	if (cnt == 10) {
		maxresult = max(resultsum, maxresult);
		return;
	}
	int thisnum = inputnum[cnt];
	for (int i = 0; i < 4; i++) {
		if (ob[i].first == 21) continue; //이미 도착점에 있는 말
		int prevnum = ob[i].first;
		int prevdir = ob[i].second;
		for (int j = 0; j < thisnum; j++) {
			ob[i].first = route[prevdir][ob[i].first];
		}
		if (ob[i].first == 5) ob[i].second = 1;
		if (ob[i].first == 10) ob[i].second = 2;
		if (ob[i].first == 15) ob[i].second = 3;

		if (!existcheck(ob[i].first,i)) {
			makecase(cnt + 1, resultsum + score[ob[i].first]);
		}
		ob[i].first = prevnum;
		ob[i].second = prevdir;

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	setscore();
	makegraph();
	makecase(0,0);
	cout << maxresult;
	return 0;
}