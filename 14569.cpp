#include<bits/stdc++.h>
using namespace std;

vector<int> classtime[1001];
vector<int> studentempty[10001];
int n, m;
int k;
int tmpint;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		while (k--) {
			cin >> tmpint;
			classtime[i].emplace_back(tmpint);
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> k;
		while (k--) {
			cin >> tmpint;
			studentempty[i].push_back(tmpint);
		}
	}

	for (int i = 1; i <= m; i++) { //한명씩
		int resultcount = 0;
		for (int j = 1; j <= n; j++) { //한 과목씩 살펴본다
			int tmpcount = 0;
			for (int k = 0; k < classtime[j].size(); k++) {
				for (int z = 0; z < studentempty[i].size(); z++) {
					if (classtime[j][k] == studentempty[i][z]) {
						tmpcount++; break;
					}
				}
			}
			if (tmpcount == classtime[j].size()) resultcount++;
		}
		cout << resultcount << "\n";
	}
	return 0;
}