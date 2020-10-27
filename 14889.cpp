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
int abs(int a) { //혹시 차이가 음수가 될경우 양수로 전환위해 절대값
	if (a < 0) a = a * -1;
	return a;
}
void inputset() {
	cin >> N; // 4이상 20 이하 (그렇게 크지 않은수 이다.)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> manpower[i][j];
		}
	}
}

void dfs(int index){
	if (index== N+1) {
		if (start.size() == N/2 && link.size() == N/2) {
			startsumscore = 0;//초기화
			linksumscore = 0;
			// 이 경우에 팀별 점수 연산을 해준다
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
		return; // dfs 종료조건
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