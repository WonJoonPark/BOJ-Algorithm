#include<bits/stdc++.h>
using namespace std;

int r, c, k;
int ground[101][101];
int hang = 3; //���� ���� ��
int yull = 3; //���� ���� ��
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
	vector<int> tmpcount; //�� ���� ���� �����صξ��ٰ� max-tmpcount[i] ��ŭ 0����ä�����
	for (int i = 0; i < hang; i++) { //��� �࿡ ���Ͽ�
		int tmpyull = yull;
		vector<xx> xarr;
		for (int j = 0; j < tmpyull; j++) {
			if (ground[i][j] == 0) continue; //0�� �׳� �Ѿ
			bool c = false;
			for (int k = 0; k < xarr.size(); k++) { // �̹� �ִ��� Ȯ��
				if (ground[i][j] == xarr[k].xnum) {
					xarr[k].totalcount++; c = true; break;
				}
			}
			if (c == false) { //������ �Ȱɷ� ������
				xarr.push_back({ ground[i][j],1 });
			}
		}
		sort(xarr.begin(), xarr.end(), compare); //����
		tmpyull = xarr.size() * 2; // ���ο� ���� ����� ��
		for (int j = 0; j < tmpyull; j++) {
			ground[i][j] = xarr[j / 2].xnum;
			ground[i][j + 1] = xarr[j / 2].totalcount;
			j++;
		}
		tmpcount.push_back(tmpyull);
		if (tmpyull > maxyull) { maxyull = tmpyull; }
	}
	 yull = maxyull;
	 for (int i = 0; i < tmpcount.size(); i++) { //������ �κ� 0���� ä���
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
		sort(xarr.begin(), xarr.end(), compare); //����
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