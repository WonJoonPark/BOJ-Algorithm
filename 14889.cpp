#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int manpower[21][21];
int N;
vector<int> start, link;
int startsumscore;
int linksumscore;
int result_min_score=2147483647;
int abs(int a) { //Ȥ�� ���̰� ������ �ɰ�� ����� ��ȯ���� ���밪
	if (a < 0) a = a * -1;
	return a;
}
void inputset() {
	cin >> N; // 4�̻� 20 ���� (�׷��� ũ�� ������ �̴�.)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> manpower[i][j];
		}
	}
}

void dfs(int index){
	if (index== N+1) {
		if (start.size() == N/2 && link.size() == N/2) {
			startsumscore = 0;//�ʱ�ȭ
			linksumscore = 0;
			// �� ��쿡 ���� ���� ������ ���ش�
			for (int i = 0; i < N / 2; i++) {
				for (int j = i+1; j < N / 2; j++) {
					if (i == j) continue;
					startsumscore += manpower[start[i]][start[j]] + manpower[start[j]][start[i]];
					linksumscore += manpower[link[i]][link[j]] + manpower[link[j]][link[i]];
				}
			}
			if (result_min_score > abs(startsumscore - linksumscore)) {
				result_min_score = abs(startsumscore - linksumscore);
			}
		}
		return; // dfs ��������
}
	start.push_back(index);
	dfs(index + 1);
	start.pop_back();

	link.push_back(index);
	dfs(index + 1);
	link.pop_back();
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	inputset();
	dfs(1);
	cout << result_min_score << '\n';
	return 0;
}