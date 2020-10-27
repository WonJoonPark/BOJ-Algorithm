#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int xarr[8] = { 2,2,-2,-2,1,-1,1,-1 };
int yarr[8] = { 1,-1,1,-1,2,2,-2,-2 };

string knight;

int main() {
	cin >> knight;
	int y = knight[1] - 48;
	int x = knight[0] - 96; //ex-> a1

	int count = 0;

	for (int i = 0; i < 8; i++) {
		if (((x + xarr[i]) > 0 && (x + xarr[i]) < 9) && ((y + yarr[i]) > 0 && (y + yarr[i]) < 9)) { //이동한 곳이 체스판 내 라면 경우의 수 하나 추가
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}