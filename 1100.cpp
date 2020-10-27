#include<iostream>
using namespace std;

bool chessmap[8][8]; //index는 0~7
void mapset() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 1) {
				chessmap[i][j] = 1; // 검정색판 }
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	char tmpinput;
	mapset();
	int counting=0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> tmpinput;
			if (tmpinput == 'F'&&chessmap[i][j] == 0) {
				counting++;
			}
		}
	}
	cout << counting << '\n';
	return 0;
}