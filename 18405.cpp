#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int S, X, Y;
int virusmap[201][201];
bool viruscheck[201][201];
int dx[4] = { 0,0,1,-1 }; //4방향 탐색을 위한
int dy[4] = { 1,-1,0,0 };
struct vi { int x; int y; int num; }; //바이러스 좌표와 number를 저장하는 구조체
vector<vi> tmparr; //1초마다 4방향 탐색을 진행해야하는 후보?바이러스들을 담은 set

void inputs() { //입력함수
	cin >> N >> K; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> virusmap[i][j];
			if (virusmap[i][j] != 0) {
				viruscheck[i][j] = true;
			}
		}
	}
	cin >> S >> X >> Y;

}
bool cmp(vi a, vi b) { //바이러스 번호 순 정렬을 위한 비교함수
	if (a.num < b.num) return true;
	else return false;
}
void startinfection(int x, int y) { //4방향 탐색
	for (int i = 0; i < 4; i++) {
		if (x+dx[i]>=0&&x+dx[i]<N&&y+dy[i]>=0&&y+dy[i]<N&&viruscheck[x+dx[i]][y+dy[i]] == false) {
			virusmap[x + dx[i]][y + dy[i]] = virusmap[x][y];
			viruscheck[x + dx[i]][y + dy[i]] = true;
		}
	}
}
void makeascvirusset() { //바이러스map을 탐색해서 바이러스를 set에 넣어둔다
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (virusmap[i][j] != 0) {
				vi tmp;
				tmp.x = i; tmp.y = j; tmp.num = virusmap[i][j];
				tmparr.push_back(tmp);
			}
		}
	}
}
void searchvirus(int s, int x, int y) {
	int second = 0;
	while (1) {
		if (virusmap[x-1][y-1] != 0) { cout << virusmap[x-1][y-1]; break; } //이미 번식하고 있는 바이러스가 있으면 거기에 다른 바이러스가 올수 없으므로 바로 출력
		if (second == s) { cout << 0; break; } //시간에 맞았는데 위에 if문에 안 걸렸다는 뜻이므로 0 출력
		tmparr.clear();
		makeascvirusset();
		sort(tmparr.begin(), tmparr.end(), cmp); //set을 정렬한다(오름차순) 낮은 바이러스부터 번식을 시작하므로
		for (int i = 0; i < tmparr.size(); i++) {
			startinfection(tmparr[i].x, tmparr[i].y);
		}
		second++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	searchvirus(S, X, Y);
	return 0;
}