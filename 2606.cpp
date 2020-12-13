#include<iostream>
#include<algorithm>
using namespace std;

int c;
int connected[101][101];
bool visited[101];
int n,tmp1,tmp2;
int resultcount = 0; //1번 컴퓨터

void dfs(int num) {
	visited[num] = true;
	resultcount++;
	for (int i = 1; i <= c; i++) {
		if (connected[num][i] == 1 && visited[i] == false)
			dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c; //1~c
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2;
		connected[tmp1][tmp2] = 1;
		connected[tmp2][tmp1] = 1;
	}

	dfs(1);

	cout << resultcount-1 << "\n"; //1번 컴퓨터는 빼야한다.
	return 0;
}