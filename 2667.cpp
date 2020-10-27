#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dangi=0;
int count1;
int n;
vector<vector<int>> map;
vector<vector<int>> check;
vector<int> jip;
vector<int> tmp;
vector<int> tmpcheck;
bool dan = false;
void dfs(int a,int b) {
	check[a][b] = 1;
	count1++;
	if (a + 1 < n && map[a + 1][b] == 1 && check[a + 1][b] == 0) { dfs(a + 1, b); dan = true;}
	if (b + 1 < n && map[a][b + 1] == 1 && check[a][b + 1] == 0) { dfs(a, b + 1); dan = true;}
	if (a - 1 >= 0 && map[a - 1][b] == 1 && check[a - 1][b] == 0) { dfs(a - 1, b); dan = true;}
	if (b - 1 >= 0 && map[a][b - 1] == 1 && check[a][b - 1] == 0) { dfs(a, b - 1); dan = true;}
	return;
}
void divide(int t){
	for (int i = 0; i < n; i++) {
		tmp.push_back(t % 10);
		t /= 10;
}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	int tmpnum;
	for (int i = 0; i < n; i++) {
		cin >> tmpnum;
		divide(tmpnum);
		map.push_back(tmp);
		tmp.clear();
		for (int j = 0; j < n; j++) {
			tmpcheck.push_back(0);
		}
		check.push_back(tmpcheck);
		tmpcheck.clear();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1&&check[i][j]==0) {
				dfs(i, j);
				if (dan == true) { dangi++; 
				dan = false;
				jip.push_back(count1);
				}
				count1 = 0;
			}
		}
	}
	sort(jip.begin(), jip.end());
	cout << dangi << '\n';
	for (int i = 0; i <dangi; i++) {
		cout << jip[i] << '\n';
	}
	return 0;
}