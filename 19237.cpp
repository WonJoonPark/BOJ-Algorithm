#include<bits/stdc++.h>
using namespace std;

int n,m,k;
bool sharkdie[401];
vector<int> sharkdir;
pair<int, int> sharks[401]; //현재 상어들의 위치 (x,y)
vector<pair<int, int>> sea[21][21]; //first= 상어번호, second= 남은 k
int dirinfo[401][4][4];
int tmpint;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
//위.아래,왼쪽,오른쪽
void inputs() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmpint;
			if (tmpint != 0) {
				sharks[tmpint].first = i; sharks[tmpint].second = j;
			}
		}
	}
	sharkdir.push_back(-1); // 인덱스 맞추기 용
	for (int i = 0; i < m; i++) {
		cin >> tmpint; sharkdir.push_back(tmpint-1); 
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> tmpint;
				dirinfo[i][j][k]=tmpint-1;
			}
		}
	}
}
bool boundcheck(int x, int y) {
	return (x >= 0 && y >= 0 && x < n&& y < n);
}
bool checksharks() {
	for (int i = 2; i <= m; i++) {
		if (sharkdie[i] == false) return false;
	}
	return true; //1번 상어 빼고 다 쫓겨남
}
int main() {
	inputs();
	int resultsecond=0;
	while (1) {
		if (resultsecond > 1000) { cout << -1; break; }
		if (checksharks()) { cout << resultsecond; break; }


		//냄새 k 감소
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!sea[i][j].empty()) {
					sea[i][j][0].second--;
					if (sea[i][j][0].second == 0) {
						sea[i][j].clear();
					}
}
			}
		}

		//냄새 뿌리기
		for (int i = 1; i <= m; i++) {
			if (sharkdie[i] == false) { //쫓겨나지 않았다면 냄새 뿌린다.
				sea[sharks[i].first][sharks[i].second].clear();
				sea[sharks[i].first][sharks[i].second].push_back({ i,k });
			}
		}

		//이동하기
		for (int i = 1; i <= m; i++) { //상어 한마리씩 본다.
			if (sharkdie[i] == true) continue;
			bool suc = false;
			// 냄새가 없는 칸이 있는지 먼저본다.
			for (int j = 0; j < 4; j++) {
				int nextx = sharks[i].first + dx[dirinfo[i][sharkdir[i]][j]];
				int nexty = sharks[i].second + dy[dirinfo[i][sharkdir[i]][j]];
				if (boundcheck(nextx, nexty) && sea[nextx][nexty].empty()) { //냄새가 없는 칸
					sharks[i].first = nextx;
					sharks[i].second = nexty;
					suc = true;
					sharkdir[i] = dirinfo[i][sharkdir[i]][j]; //이동한 방향이 보고있는 방향이 된다.
					break;
				}
			}
			
			if (suc == false) {
				for (int j = 0; j < 4; j++) {
					int nextx = sharks[i].first + dx[dirinfo[i][sharkdir[i]][j]];
					int nexty = sharks[i].second + dy[dirinfo[i][sharkdir[i]][j]];
					if (boundcheck(nextx, nexty) && sea[nextx][nexty][0].first == i) { //자신의 냄새가 있는 칸
						sharks[i].first = nextx;
						sharks[i].second = nexty;
						suc = true;
						sharkdir[i] = dirinfo[i][sharkdir[i]][j]; //이동한 방향이 보고있는 방향이 된다.
						break;
					}
				}
			}
		}



		// 겹치는 상어 쫓아내기
		for (int i = 1; i <= m; i++) {
			if (sharkdie[i] == true) continue;
			for (int j = i + 1; j <= m; j++) {
				if (sharkdie[j] == true) continue;
				if (sharks[i].first == sharks[j].first && sharks[i].second == sharks[j].second) { // 겹쳐진 상어가 생기면
					sharkdie[j] = true; // 쫓겨난다 (번호가 늦는 놈이)
				}
			}
		}
		resultsecond++;
	}
	return 0;
}