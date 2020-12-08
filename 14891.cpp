#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

char topni[4][8];
int K;
int resultscore;

void inputs() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> topni[i][j];
		}
	}
}


void rotate(int index, int dir) { //0,1,2,3
	vector<pair<bool,int>> turn(4); //first= 회전할지 말지, second=방향

	for (int i = 0; i < 4; i++) { //초기화
		turn[i].first = false; turn[i].second = 0;
	}
	turn[index].first = true; turn[index].second = dir;
	//왼쪽확인
	char current=topni[index][6];
	int direction = dir;

	for (int i = index - 1; i >= 0; i--) {
		if (current != topni[i][2]) {
			turn[i].first = true; turn[i].second = (-1)*direction; //반대방향
			current = topni[i][6]; direction *= (-1);
		}
		else break; //이게 회전을 안한다면 그 옆은 볼필요 x
	}
	//오른쪽확인
	direction = dir;
	current = topni[index][2];
	for (int i = index + 1; i < 4; i++) {
		if(current!=topni[i][6]) {
			turn[i].first = true; turn[i].second = (-1)*direction;
			current = topni[i][2]; direction *= (-1);
		}
		else break; //이게 회전을 안한다면 그 옆은 볼필요 x
	}
	
	//회전
	for (int i = 0; i < 4; i++) {
		if (turn[i].first == true) { //회전한다면
			if (turn[i].second == 1) { //시계방향
		  		char tmp=topni[i][7];
				for (int j = 6; j >= 0; j--) topni[i][j + 1] = topni[i][j];
				topni[i][0] = tmp;
			}
			else { //반시계방향
				char tmp = topni[i][0];
				for (int j = 1; j <= 7; j++) topni[i][j - 1] = topni[i][j];
				topni[i][7] = tmp;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cin.tie(0);
	inputs();
	cin >> K;
	int index, dir;
	for (int i = 0; i < K; i++) {
		cin >> index >> dir;
		rotate(index-1, dir);
	}
	if (topni[0][0] == '1') resultscore += 1;

	if (topni[1][0] == '1') resultscore += 2;

	if (topni[2][0] == '1') resultscore += 4;

	if (topni[3][0] == '1') resultscore += 8;

	cout << resultscore << "\n";

	return 0;
}