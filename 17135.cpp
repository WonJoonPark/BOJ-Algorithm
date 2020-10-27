#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ground[17][17];
int copyground[17][17];
bool selected[17];
vector<pair<int, int>> archer;
int maxresult = -1;
int N, M;
int D;
int enemycount;
struct enemy { int x; int y; int d; };

bool cmp(enemy a, enemy b) {
	if (a.d < b.d) { return true; }
	else {
		if (a.d == b.d) {
			if (a.y < b.y) { return true; }
			else { return false; }
		}
		return false;
	}
}
void watchground() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ground[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void inputs() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ground[i][j];
			copyground[i][j] = ground[i][j];
		}
	}
}
void groundinit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ground[i][j] = copyground[i][j];
		}
	}
}
bool checkground() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ground[i][j] == 1) { return false; }
		}
	}
	return true;
}
int abs(int n1, int n2) {
	if (n1 > n2) { return n1 - n2; }
	else return n2 - n1;
}
int getdistance(int x, int y, int x2, int y2) {
	return (abs(x, x2) + abs(y, y2));
};
void enemymove() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (ground[i][j] == 1) {
				ground[i + 1][j] = 1; ground[i][j] = 0;
			}
		}
	}
}
void startgame() {
	while (1) {// 반복한번 = 1턴
		if (checkground() == true) { 
			if (maxresult < enemycount) { maxresult = enemycount; }
			return;
		}
		vector<enemy> eset[3];
		for (int i = 0; i < archer.size(); i++) {
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < M; b++) {
					if (ground[a][b] == 1) {
						if (getdistance(archer[i].first, archer[i].second, a, b) <= D) {
							enemy tmp; tmp.x = a; tmp.y = b; tmp.d = getdistance(archer[i].first, archer[i].second, a, b);
							eset[i].push_back(tmp); //1명의 궁수당 적이 들어있음 거리와 함께
						}
					}
				}
			}
			sort(eset[i].begin(), eset[i].end(), cmp);
		}
		//각각의 궁수에 대해서 0번쨰 인덱스의 적이 죽을 차례
		for (int i = 0; i < archer.size(); i++) {
			if (eset[i].empty() == true) continue; //사정거리내의 적이 없음
			if (ground[eset[i][0].x][eset[i][0].y] == 1) {
				ground[eset[i][0].x][eset[i][0].y] = 0; //적을 없앤다
				enemycount++;
			}
		}
		enemymove();
	}
}


void makecase(int index,int num) {
	if (num == 3) {
		enemycount = 0;
		groundinit();
		startgame(); return;
	}
	pair<int, int> tmp;
	tmp.first = N;
	for (int i = index; i < M; i++) {
		if (selected[i] == true  ) continue;
		tmp.second = i;
		archer.push_back(tmp);
		selected[i] = true;
		makecase(i,num + 1);
		archer.pop_back();
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	inputs();
	makecase(0,0);
	cout << maxresult;

	return 0;
}