#include<bits/stdc++.h>
using namespace std;

int tmpthree[2][3];
int tmpsum[2][7]; // 0~1(По) 2~4 (Сп) 5~6 (ПР)
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int x1, x2, x3;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> x2 >> x3;
		tmpsum[0][0] = tmpthree[0][0] + x1;
		tmpsum[0][1] = tmpthree[0][1] + x1;
		tmpsum[0][2] = tmpthree[0][0] + x2;
		tmpsum[0][3] = tmpthree[0][1] + x2;
		tmpsum[0][4] = tmpthree[0][2] + x2;
		tmpsum[0][5] = tmpthree[0][1] + x3;
		tmpsum[0][6] = tmpthree[0][2] + x3;
		tmpthree[0][0] = max(tmpsum[0][0], tmpsum[0][1]);
		tmpthree[0][1] = max(max(tmpsum[0][2], tmpsum[0][3]), tmpsum[0][4]);
		tmpthree[0][2] = max(tmpsum[0][5], tmpsum[0][6]);

		tmpsum[1][0] = tmpthree[1][0] + x1;
		tmpsum[1][1] = tmpthree[1][1] + x1;
		tmpsum[1][2] = tmpthree[1][0] + x2;
		tmpsum[1][3] = tmpthree[1][1] + x2;
		tmpsum[1][4] = tmpthree[1][2] + x2;
		tmpsum[1][5] = tmpthree[1][1] + x3;
		tmpsum[1][6] = tmpthree[1][2] + x3;
		tmpthree[1][0] = min(tmpsum[1][0], tmpsum[1][1]);
		tmpthree[1][1] = min(min(tmpsum[1][2], tmpsum[1][3]), tmpsum[1][4]);
		tmpthree[1][2] = min(tmpsum[1][5], tmpsum[1][6]);
	}
	int maxv = max(max(tmpthree[0][0], tmpthree[0][1]), tmpthree[0][2]);
	int minv = min(min(tmpthree[1][0], tmpthree[1][1]), tmpthree[1][2]);

	cout << maxv<<" "<<minv;
	return 0;
}