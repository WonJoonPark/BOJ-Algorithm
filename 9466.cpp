#include<bits/stdc++.h>
using namespace std;

int students[100001];
bool checkvisit[100001];
bool alreadycycle[100001];
int n, T;
int teamcount = 0;

void dfs(int ti) {
	checkvisit[ti] = true;
	int nextti = students[ti];
	if (!checkvisit[nextti]) dfs(nextti); //�湮
	if (checkvisit[nextti] && !alreadycycle[nextti]) { //�湮�ߴµ� ����Ŭ�� �̷��� ���� ���
		for (int i = nextti; i != ti; i = students[i]) {
			teamcount++;
		}
		teamcount++; // ti
	}
	alreadycycle[ti] = true; // �ϳ��� ���� (���� ����Ŭ�� �ִ���)
}

void visitclear() {
	for (int i = 1; i <= n; i++) {
		checkvisit[i] = 0; alreadycycle[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		visitclear();
		teamcount = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> students[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!checkvisit[i]) //�湮���� �ʾҴٸ�
				dfs(i);
		}
		cout << n - teamcount << "\n";
	}
	return 0;
}