#include<bits/stdc++.h>
using namespace std;

int T;
int n;
bool cansee[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if ((i==0&&j==0)||cansee[i][j] == true) continue;
			int x = 2;
			while (x*i <= 1000 && x*j <= 1000) {
				cansee[x*i][x*j] = true;
				x++;
			}
		}
	}

	while (T--) {
		cin >> n;
		int resultcount = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (cansee[i][j] == false) resultcount++;
			}
		}
		cout << resultcount-1 << "\n"; //(0,0)Àº Á¦¿Ü?
	}
	return 0;
}