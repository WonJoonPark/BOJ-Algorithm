#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
bool playerordercheck[10];
int playerresult[51][10];
int playerorder[10];
bool location[4]; //1루 2루 3루 를 표시
int resultscore;
int maxscore;
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for(int j=1;j<=9;j++){
			cin >> playerresult[i][j];
		}
	}
}
void resetlocation() { //1,2,3루 초기화
	for (int i = 1; i <= 3; i++) {
		location[i] = false;
	}
	return;
}
void getscorecheck(int num) {
	for (int i = 3; i >= 1; i--) {
		if (location[i] == true) {
			if (i + num >= 4) { location[i] = false; resultscore++; }
			else { location[i] = false; location[i + num] = true; } //주자 이동
		}
	}
	if (num >= 4) { resultscore++; return; } //홈런인 경우
	else { location[num] = true; return; }
}
int gamestart() {
	resultscore = 0;
	int outcount = 0;
	int playerpointer = 1;
	for (int i = 1; i <= N; i++) { //N이닝동안 반복
		outcount = 0; //이닝별 아웃카운터 초기화
		while (1) { //주자 한명씩 확인
			if (outcount == 3) {
				resetlocation(); //나가있던 주자들 모두 들어옴.
				break;
			}
			if (playerresult[i][playerorder[playerpointer]] == 1) { //1루타
				getscorecheck(1);
			}
			else if (playerresult[i][playerorder[playerpointer]] == 2) {//2루타
				getscorecheck(2);
			}
			else if (playerresult[i][playerorder[playerpointer]] == 3) {//3루타
				getscorecheck(3);
			}
			else if (playerresult[i][playerorder[playerpointer]] == 4) {//4루타
				getscorecheck(4);
			}
			else { //아웃된 경우
				outcount++;
			}
			playerpointer++;
			if (playerpointer == 10) { playerpointer = 1; } //9번 주자까지 다 치면 다시 1번 주자
		}
	}
	return resultscore;
}
void P(int cnt) {
	if (cnt == 10) {
		int tmp = gamestart();
		if (maxscore < tmp) { //각 case가 확정되면 게임을 시작한다.
			maxscore = tmp;
		} 
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (playerordercheck[i] == true) continue;//아직 배정되지 않은 선수라면playerordercheck[i] = true;
		playerordercheck[i] = true;
		playerorder[i] = cnt;
		P(cnt + 1); //모든 순열case을 찾자
		playerordercheck[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	playerordercheck[4] = true; //4번타자는 1번으로 고정(문제조건) -이미 자리가 배정됨
	playerorder[4] = 1;
	P(2); //1명은 이미 자리 배정이 완료되었음으로... permutation(순열)
	      //순서를 고려해야함
	cout << maxscore << "\n";

	return 0;
}