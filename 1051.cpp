#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
char nemo[51][51]; //0~ n-1, 0 ~ m-1

int maxcnt = 0;

void inputs() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> nemo[i][j];
		}
	}
}
int samenemo(int x, int y, int c) {
	if (nemo[x][y] == nemo[x + c][y] && nemo[x][y] == nemo[x][y + c]
		&& nemo[x][y] == nemo[x + c][y + c]) return true;
	else return false;
}
void makecase(int cnt)
{
	for (int i = 0; i < N-cnt; i++) {
		for (int j = 0; j < M-cnt; j++) {
			if (samenemo(i, j,cnt)) {
				if (maxcnt < cnt) {
					maxcnt = cnt;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	if (N == 1 || M == 1) { cout << 1 << "\n"; return 0; }
	for (int i = 1; i < min(N, M); i++) {
		makecase(i); // 시작 index와 한 변의 길이
	}
	cout << (maxcnt+1)*(maxcnt+1) << "\n";

	return 0;
}