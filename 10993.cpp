#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
char starmap[2048][2048];

int gety(int n) {
	int fi = 2;
	for (int i = 0; i < n; i++) {
		fi *= 2;
	}
	return (fi - 3);
}
int getx(int n) {
	int fi = 2;
	for (int i = 0; i < n - 1; i++) {
		fi *= 2;
	}
	return (fi - 1);
}

void makestar(int cnt,int startx,int starty) {
	if (cnt == 0) {
		return;
	}
	int cx = getx(cnt);
	int cy = gety(cnt);
	if (cnt % 2 == 0) { //Â¦¼öÀÏ¶§ ¿ª»ï°¢Çü
		for (int i = startx; i < startx+cx; i++) {
			for (int j = starty; j <starty+ cy / 2 + 1; j++) {
				if (i == startx) starmap[i][j] = '*';
				else if (j == starty+(i-startx)) starmap[i][j] = '*';
				else starmap[i][j] = ' ';
			}
		}
		for (int i = startx; i < startx+cx; i++) {
			for (int j = starty+cy / 2+1; j < starty+cy; j++) {
				if (i == startx) starmap[i][j] = '*';
				else if (j == starty+cy - 1 - (i-startx)) starmap[i][j] = '*';
				else starmap[i][j] = ' ';
			}
		}
		makestar(cnt - 1, startx +1, starty + cy / 4+1);
	}
	else { //È¦¼ö
		for (int i = startx; i <startx+cx; i++) {
			for (int j = starty; j <starty+ cy / 2 + 1; j++) {
				if (i == startx+cx-1) starmap[i][j] = '*';
				else if (j == starty+(cy / 2) - (i-startx)) starmap[i][j] = '*';
				else starmap[i][j] = ' ';
			}
		}
		for (int i = startx; i <startx+cx; i++) {
			for (int j =starty+ cy / 2+1; j <starty+ cy; j++) {
				if (i ==startx+ cx - 1) starmap[i][j] = '*';
				else if (j == starty+(cy / 2) + (i-startx)) starmap[i][j] = '*';
				else starmap[i][j] = ' ';
			}
		}
		makestar(cnt - 1, startx + cx / 2, starty + cy / 4+1);
	}
}
void printstar(int n) {
	int x = getx(n);
	int y = gety(n);
	if (n % 2 == 1) { // È¦¼ö
		for (int i = 0; i < x; i++) {
			for (int j = 0; j <= y/2+i; j++) {
				cout << starmap[i][j];
			}
			cout << "\n";
		}
	}
	else { //Â¦¼ö
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y - i; j++) {
				cout << starmap[i][j];
			}
			cout << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n;
	makestar(n, 0, 0);

	printstar(n);

	return 0;
}