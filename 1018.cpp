#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int N, M;
char chessmap[51][51];
int minresult = 65;
int tmpresult;

void checkmap(int x, int y) {
	tmpresult = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) { 
			//시작점 블랙
			if ((x + i + y + j) % 2 == 0) {
				if (chessmap[x + i][y + j] == 'W') tmpresult++;
			}
			else {
				if (chessmap[x + i][y + j] == 'B') tmpresult++;
			}
		}
	}
	if (tmpresult < minresult) minresult = tmpresult;
	tmpresult = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//시작점 화이트
			if ((x + i + y + j) % 2 == 0) {
				if (chessmap[x + i][y + j] == 'B') tmpresult++;
			}
			else {
				if (chessmap[x + i][y + j] == 'W') tmpresult++;
			}
		}
	}
	if (tmpresult < minresult) minresult = tmpresult;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chessmap[i][j];
		}
	}
	for (int i = 0; i <= (N - 8); i++) {
		for (int j = 0; j <= (M - 8); j++) {
			checkmap(i, j);
		}
	}
	cout << minresult << "\n";
	return 0;
}