#include<bits/stdc++.h>
using namespace std;

char field[12][6];
int resultcount = 0;

int dxgaro[2] = { 0,0 };
int dtgaro[2] = { 1,-1 };
int dxsero[2] = { 1,-1 };
int dysero[2] = { 0,0 };

void inputs() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> field[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (field[i][j] != '.') {

			}
		}
	}



	return 0;
}