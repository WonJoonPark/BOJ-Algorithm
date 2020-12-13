#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, M, H;
char sadari[31][11];
int a, b;
int minresult=4; //3 이하; 그 이상은 -1;
bool suc = false;

void inputs() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		sadari[a][b] = 'R';
		sadari[a][b + 1] = 'L';
	}
}
bool checkingright() {
	for (int i = 1; i <= N; i++) {
		int resultcount = i;
		for (int j = 1; j <= H; j++){
			if (sadari[j][i] == 'R') i++;
			else if(sadari[j][i]=='L') i--;
			else continue;
		}
		if (resultcount != i) return false;
		i = resultcount;
	}
	return true;
}
void findline(int x,int cnt) {
	if (cnt > 3) { return; } 
	if (checkingright() == true) {
		if (minresult > cnt) { minresult = cnt; }
		suc = true;
		return;
	}; //성공
	for (int a = x; a < N; a++) {
		for (int b = 0; b <= H; b++) {// for(int b=y;b<=H;b++) xxxxxxxxxx!
			if (sadari[b][a] != 0 || sadari[b][a+1]!=0) continue; //이미 연결되어있음
			else {
				sadari[b][a] = 'R';
				sadari[b][a + 1] = 'L';

				findline(a,cnt + 1);  //findline(a,b+1,cnt+1) xxxxxxxx!

				sadari[b][a + 1] = 0;
				sadari[b][a] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	findline(1,0);
	if (suc == false) { cout << -1 << "\n"; }
	else cout << minresult << "\n";
	return 0;
}