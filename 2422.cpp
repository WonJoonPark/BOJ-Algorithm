#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N;
int M;
int t1, t2;
// vector<pair<int, int>> worstice;
bool wi[201][201];
vector<int> icearr;
int pscase = 0;

/*bool psice() {
	for (int i = 0; i < worstice.size(); i++) {
		int tmp = 0;
		for (int j = 0; j < icearr.size(); j++) {
			if (icearr[j] == worstice[i].first || icearr[j] == worstice[i].second) {
				tmp++;
			}
			if (tmp == 2) return false;
			if (icearr[j] > worstice[i].second) break;
		}
	}
	return true;
}*/
bool ps() {
	if (wi[icearr[0]][icearr[1]] == true || wi[icearr[0]][icearr[2]] == true
		|| wi[icearr[1]][icearr[2]] == true) return false;
	else return true;
}

void makeice(int index,int cnt) {
	if (cnt == 3) {
		if (ps()) {
			pscase++;
		}
		return;
	}
	for (int i = index; i <= N; i++) {
		icearr.push_back(i);
		makeice(i+1,cnt + 1);
		icearr.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2;
		// worstcase.push_back({t1,t2});
		wi[t1][t2] = true;
		wi[t2][t1] = true;
	}
	makeice(1,0);

	cout << pscase << "\n";

	return 0;
}