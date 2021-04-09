#include<bits/stdc++.h>
using namespace std;

int T;
vector<int> lottonum;
vector<int> numarr;
int n;

void makecase(int cnt,int index) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lottonum[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = index; i < n; i++) {
		lottonum.push_back(numarr[i]);
		makecase(cnt + 1, i + 1);
		lottonum.pop_back();
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tmpn;
	while(1){
		numarr.clear(); lottonum.clear();
		cin >> n;
		if(n==0) return 0;
		for (int j = 0; j < n; j++) {
			cin >> tmpn;
			numarr.push_back(tmpn);
		}
		sort(numarr.begin(), numarr.end());
		makecase(0,0);
		cout << "\n";
	}

	return 0;
}