#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 987654321

int n, m;
int CityToCity[101][101];

void inputs() { //�Է��Լ�
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) { //�ʱ�ȭ
			if (i == j) continue;
			CityToCity[i][j]=INF;
		}
	}
	int start, end, cost;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;
		if (CityToCity[start][end] > cost) {
			CityToCity[start][end] = cost;
		}
	}
}

void Searchmin() {
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			for (int c = 1; c <= n; c++) {
				if (CityToCity[b][a] != INF && CityToCity[a][c] != INF) { //���ļ� �� �� �ִ� ���
					CityToCity[b][c] = min(CityToCity[b][c], (CityToCity[b][a] + CityToCity[a][c]));
				}
			}
		}
	}
}
void outputs() { //����Լ�
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (CityToCity[i][j] == INF||i==j)  cout << 0 << " "; 
			else cout << CityToCity[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	Searchmin();
	outputs();
	return 0;
}