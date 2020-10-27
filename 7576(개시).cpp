#include<iostream>
#include<queue>
using namespace std;

int M, N;
int tomatomap[1001][1001];
int xarr[4] = { -1,0,1,0 };
int yarr[4] = { 0,1,0,-1 };
int resultcount;
int wholetomato;
int tmptomatocount;
struct xy {
	int x;
	int y;
};
queue<xy> tmpq;
void bfs() {
	while (1) {
		if (tmptomatocount == wholetomato) {
			cout << resultcount << '\n';
			break;
		}
		if (tmpq.empty()==true) {
			cout << -1 << '\n';
			break;
		}
		int qsize = tmpq.size();
		xy tt, tt2;
		for (int i = 0; i < qsize; i++) {
			tt = tmpq.front();
			for (int j = 0; j < 4; j++) {
				if (tt.x + xarr[j] >= 0 && tt.x + xarr[j] < N&&tt.y + yarr[j] >= 0 && tt.y + yarr[j] < M) {
					if (tomatomap[tt.x + xarr[j]][tt.y + yarr[j]] == 0) {
						tomatomap[tt.x + xarr[j]][tt.y + yarr[j]] = 1;
						tt2.x = tt.x + xarr[j];
						tt2.y = tt.y + yarr[j];
						tmptomatocount++;
						tmpq.push(tt2);
					}
				}
			}
			tmpq.pop();
		}
		resultcount++;//날짜 하루씩
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N;
	xy tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomatomap[i][j];
			if (tomatomap[i][j] != -1) {
				wholetomato++; //총 토마토의 개수
			}
			if (tomatomap[i][j] == 1) {
				tmp.x = i;
				tmp.y = j;
				tmpq.push(tmp);
				tmptomatocount++;	//현재 익은 토마토 개수		
			}	
		}
}// 0 익지않음 -1 토마토없음 1은 익은 토마토
	if (tmptomatocount == wholetomato) { cout << 0 << '\n'; return 0; }
	bfs();
	return 0;
}