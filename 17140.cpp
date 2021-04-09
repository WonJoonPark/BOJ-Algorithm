#include<bits/stdc++.h>
using namespace std;

int r, c, k;
int ground[101][101];
int hang = 3; //현재 행의 수
int yull = 3; //현재 열의 수
struct xx {
	int xnum;
	int totalcount;
};


void inputs() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ground[i][j];
		}
	}
}
bool compare(xx &t1, xx &t2) {
	if (t1.totalcount < t2.totalcount) return true;
	if (t1.totalcount == t2.totalcount) {
		if (t1.xnum < t2.xnum) return true;
		else return false;
	}
	else return false;
}

void Rcal() {
	int maxyull = 0;
	vector<int> tmpcount; //각 행의 수를 저장해두었다가 max-tmpcount[i] 만큼 0으로채우려고
	for (int i = 0; i < hang; i++) { //모든 행에 대하여
		int tmpyull = yull;
		vector<xx> xarr;
		for (int j = 0; j < tmpyull; j++) {
			if (ground[i][j] == 0) continue; //0은 그냥 넘어감
			bool c = false;
			for (int k = 0; k < xarr.size(); k++) { // 이미 있는지 확인
				if (ground[i][j] == xarr[k].xnum) {
					xarr[k].totalcount++; c = true; break;
				}
			}
			if (c == false) { //위에서 안걸러 졌으면
				xarr.push_back({ ground[i][j],1 });
			}
		}
		sort(xarr.begin(), xarr.end(), compare); //정렬
		tmpyull = xarr.size() * 2; // 새로운 열의 사이즈가 됨
		for (int j = 0; j < tmpyull; j++) {
			ground[i][j] = xarr[j / 2].xnum;
			ground[i][j + 1] = xarr[j / 2].totalcount;
			j++;
		}
		tmpcount.push_back(tmpyull);
		if (tmpyull > maxyull) { maxyull = tmpyull; }
	}
	 yull = maxyull;
	 for (int i = 0; i < tmpcount.size(); i++) { //나머지 부분 0으로 채우기
		 for (int j = yull - 1; j >= 0; j--) {
			 if (tmpcount[i] - 1 < j) {
				 ground[i][j] = 0;
			 }
			 else break;
		 }
	 }
}
void Ccal() {
	int maxhang = 0;
	vector<int> tmpcount;
	for (int i = 0; i < yull; i++) {
		int tmphang = hang;
		vector<xx> xarr;
		for (int j = 0; j < tmphang; j++) {
			if (ground[j][i] == 0) continue;
			bool c = false;
			for (int k = 0; k < xarr.size(); k++) {
				if (ground[j][i] == xarr[k].xnum) {
					xarr[k].totalcount++; c = true; break;
				}
			}
			if (c == false) {
				xarr.push_back({ ground[j][i],1 });
			}
		}
		sort(xarr.begin(), xarr.end(), compare); //정렬
		tmphang = xarr.size() * 2;
		for (int j = 0; j < tmphang; j++) {
			ground[j][i] = xarr[j / 2].xnum;
			ground[j + 1][i] = xarr[j / 2].totalcount;
			j++;
		}
		tmpcount.push_back(tmphang);
		if (tmphang > maxhang) { maxhang = tmphang; }
	}
	hang = maxhang;
	for (int i = 0; i < tmpcount.size(); i++) {
		for (int j = hang - 1; j >= 0; j--) {
			if (tmpcount[i] - 1 < j) {
				ground[j][i] = 0;
			}
			else break;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int second = 0;
	inputs();
	while (1) {
		if (ground[r-1][c-1] == k) { cout << second << "\n"; return 0; }
		if (second > 100) { cout << -1 << "\n"; return 0; }
		if (hang >= yull) {
			Rcal();
		}
		else {
			Ccal();
		}
		second++;
	}
	return 0;
}