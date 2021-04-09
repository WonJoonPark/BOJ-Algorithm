#include<bits/stdc++.h>
using namespace std;

int n, p, e;
pair<int, int> nxy[21]; //first~second 까지 범위
vector<pair<int,int>> tmpv;
int dollsum = 0;
bool suc = false;
void makecase(int index,int cnt) {
	if (suc == true) return;
	if (cnt == p) {
		if (e == dollsum) {
			for (int i = 1; i <= n; i++) {
				bool tmpcheck = false;
				for (int j = 0; j < tmpv.size(); j++) {
					if (tmpv[j].second == i) {
						cout << tmpv[j].first << " ";
						tmpcheck = true;
						break;
					}
				}
				if (tmpcheck == false) { cout << 0 << " "; }
}
			suc = true;
		}
		return;
	}
	for (int i = index; i <= n; i++) {
		for (int j = nxy[i].first; j <= nxy[i].second; j++) {
			tmpv.push_back({ j,i });
			dollsum += j;
			makecase(i + 1,cnt+1);
			tmpv.pop_back();
			dollsum -= j;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> p >>e;
	for (int i = 1; i <= n; i++) {
		cin >> nxy[i].first >> nxy[i].second;
	}
	makecase(1,0);
	if (suc == false) cout << -1;
	return 0;
}