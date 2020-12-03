#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct pizza {
	int x, y, height;
};

int n, m;
pizza pizzabox[1001][1001];
pizza copybox1[1001][1001];
pizza copybox2[1001][1001];
bool maxcheck[1001][1001];
long long resultcount;
bool compare(pizza a, pizza b) {
	if (a.height > b.height) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pizzabox[i][j].height;
			pizzabox[i][j].x = i; pizzabox[i][j].y = j; // 원래 위치 기록용
			copybox1[i][j] = pizzabox[i][j];
			copybox2[j][i] = pizzabox[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		sort(copybox1[i], copybox1[i] + m, compare);
		maxcheck[copybox1[i][0].x][copybox1[i][0].y] = true;
	}
	for (int i = 0; i < m; i++) {
		sort(copybox2[i], copybox2[i] + n, compare);
		maxcheck[copybox2[i][0].x][copybox2[i][0].y] = true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maxcheck[i][j] == false) { resultcount += pizzabox[i][j].height; }
		}
	}
	cout << resultcount << "\n";
	return 0;
}