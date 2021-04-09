#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int n, w, h;
int ground[16][13];
int maxoutput = 1000;
bool boundcheck(int x, int y) {
	if (x >= 1 && x <= h && y >= 1 && y <= w) return true;
	else return false;
}
void removeall(int x, int y) {
	if (ground[x][y] == 0) return;
	if (ground[x][y] == 1) { ground[x][y] = 0; return; }
	int len = ground[x][y];
	ground[x][y] = 0; //지우기
	//가로지우기 세로지우기
	for (int i = x - (len - 1); i <= x + (len - 1); i++) {
		if (boundcheck(i, y)) {
			removeall(i, y);
		}
	}
	for (int i = y - (len - 1); i <= y + (len - 1); i++) {
		if (boundcheck(x, i)) {
			removeall(x, i);
		}
	}
}

void removeground(int c) { //제일 위에 벽돌 고르기
	for (int i = 1; i <= h; i++) {
		if (ground[i][c] != 0) {
			removeall(i, c);
			break;
		}
	}
	/*cout << "\n";
	for (int i = 1; i<= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << ground[i][j] << " ";
		}
		cout << "\n";
	}*/
}
int numcheck() {
	int t = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (ground[i][j] != 0) t++;
		}
	}
	return t;
}
void gobelow() {
	for (int i = 1; i <= w; i++) {
		vector<int> tmpset;
		for (int j = h; j >= 1; j--) {
			if (ground[j][i] != 0) {
				tmpset.push_back(ground[j][i]);
			}
		}
		int index = h;
		for (int j = 0; j < tmpset.size(); j++) {
			ground[index][i] = tmpset[j];
			index--;
		}
		for (int j = index; j >= 1; j--) {
			ground[j][i] = 0;
		}
	}
}

void makecase(int cnt) {
	if (cnt == n) {
		//벽돌개수 max값
		maxoutput = min(maxoutput, numcheck());
		return;
	}
	int tmpground[16][13];
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			tmpground[i][j] = ground[i][j];
		}
	}

	for (int i = 1; i <= w; i++) {
		//부수기
		removeground(i);
		//벽돌 밑으로 떨어뜨리기
		gobelow();
		makecase(cnt + 1);	
		//복원
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				ground[i][j] = tmpground[i][j];
			}
		}
	}		

}
void initground() {
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> ground[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for(int i=1;i<=T;i++){
		maxoutput = 1000;
		cin >> n >> w >> h;
		initground();
		makecase(0);
		cout << "#" << i << " " << maxoutput<<"\n";
	}


	return 0;
}