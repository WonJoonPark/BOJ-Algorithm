#include<iostream>
#include<vector>
using namespace std;

int main() {

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int r[4];
	r[0] = x;
	r[1] = h - y;
	r[2] = w - x;
	r[3] = y;
	int tmp = 1000;
	for (int i = 0; i < 4; i++) {
		if (r[i] < tmp) {
			tmp = r[i];
		}
	}
	cout << tmp << endl;
	return 0;
}
