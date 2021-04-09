#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int n,m;
int f1, f2;
int resultcount = 0;
vector<int> sangf[501]; // 리스트 매달기
bool visit[501];

void makecase(int fnum) {
	for (int i = 0; i < sangf[fnum].size(); i++) {
		int ff = sangf[fnum][i];
		visit[ff] = true; //이친구는 이미 초대했다

	}
	if (fnum == 1) { //1번이 상범
		for (int i = 0; i < sangf[1].size(); i++) {
			int ff = sangf[fnum][i];
			makecase(ff);
		}
	}
}
void countsangf() {
	for (int i = 2; i <= n; i++) {
		if (visit[i]) resultcount++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; //학번은 1~N
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> f1 >>f2;
		sangf[f1].push_back(f2);
		sangf[f2].push_back(f1);
	}
	makecase(1); //상범은 1
	countsangf();
	cout << resultcount << "\n";
	return 0;
}