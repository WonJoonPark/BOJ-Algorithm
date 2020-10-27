#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int map[10][10];
int colorpaperset[6];
int minimumpapaer = 101;
void doattach(int, int, int);

void inputsetting() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i < 6; i++) {
		colorpaperset[i] = 5;
	}
}
bool canattach(int x, int y, int r) {
	if (x + r > 10 || y + r > 10) { return false; }
	for (int i = x; i < x+r; i++) {
		for (int j = y; j < y+r; j++) {
			if (map[i][j] == 0) return false;
		}
	}
	return true;
}
void setmap(int x, int y, int r) {
	for (int i = x; i < x + r; i++) {
		for (int j = y; j < y + r; j++) {
			map[i][j] =0;
		}
	}
}
void unsetmap(int x, int y, int r) {
	for (int i = x; i < x + r; i++) {
		for (int j = y; j < y + r; j++) {
			map[i][j] = 1;
		}
	}
}

void attach(int x, int y, int r) {
	int tmpx, tmpy;
	bool c = false;
	for (int i = x; i < 10; i++) { //1인 부분을 탐색
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 0) {
				if (i == 9 && j == 9) { minimumpapaer = min(minimumpapaer, r); return; }
				// 재귀를 통해 여기까지 왔다는 것 자체가 이미 1을 다 0으로 바꾸고 도착했다는 것
				continue;}
			tmpx = i; tmpy = j; c = true; break;
		}
		if (c == true) break;
	}
	doattach(tmpx, tmpy, r);
}
void doattach(int x, int y, int r) {//붙이기를 시도한다.
	for (int k = 5; k > 0; k--) {
		if (canattach(x, y, k) == true && colorpaperset[k] > 0) {
			setmap(x, y, k);
			colorpaperset[k]--;
			attach(x, y, r + 1); //재귀를 통해 다시 탐색을 수행
			colorpaperset[k]++; //다른 종이에 대해서도 수행을 해봐야하므로
			unsetmap(x, y, k); //원상 복구
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputsetting();
	attach(0, 0, 0);
	if (minimumpapaer == 101) { cout << -1; }
	else { cout << minimumpapaer; }
	return 0;
}