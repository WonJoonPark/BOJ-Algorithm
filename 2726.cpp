#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int t;
int n;
int qarr[1005];

void initqueen() {
	int tmpq = 1;
	int index = 1;
	while (1) {
		if (index > 1000) break;
		qarr[index + 0] = tmpq;
		qarr[index + 1] = tmpq;
		qarr[index + 2] = tmpq + 1;
		tmpq += 2;
		index += 3;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	initqueen();
	cin >> t;
	while (t--) {
		cin >> n;
		int startx = n - qarr[n] + 1;
		int starty = 1;
		int tmpx = 1;
		cout << qarr[n] << "\n";
		int tsize = qarr[n];
		while (tsize--) {
			cout << startx << " " << starty << "\n";
			if (startx == starty) {
				tmpx++;
				startx += 1;
				starty = tmpx;
				continue;
			}
			startx += 1; starty += 2;
		}
	}
	return 0;
}