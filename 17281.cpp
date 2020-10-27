#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
bool playerordercheck[10];
int playerresult[51][10];
int playerorder[10];
bool location[4]; //1�� 2�� 3�� �� ǥ��
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
void resetlocation() { //1,2,3�� �ʱ�ȭ
	for (int i = 1; i <= 3; i++) {
		location[i] = false;
	}
	return;
}
void getscorecheck(int num) {
	for (int i = 3; i >= 1; i--) {
		if (location[i] == true) {
			if (i + num >= 4) { location[i] = false; resultscore++; }
			else { location[i] = false; location[i + num] = true; } //���� �̵�
		}
	}
	if (num >= 4) { resultscore++; return; } //Ȩ���� ���
	else { location[num] = true; return; }
}
int gamestart() {
	resultscore = 0;
	int outcount = 0;
	int playerpointer = 1;
	for (int i = 1; i <= N; i++) { //N�̴׵��� �ݺ�
		outcount = 0; //�̴׺� �ƿ�ī���� �ʱ�ȭ
		while (1) { //���� �Ѹ� Ȯ��
			if (outcount == 3) {
				resetlocation(); //�����ִ� ���ڵ� ��� ����.
				break;
			}
			if (playerresult[i][playerorder[playerpointer]] == 1) { //1��Ÿ
				getscorecheck(1);
			}
			else if (playerresult[i][playerorder[playerpointer]] == 2) {//2��Ÿ
				getscorecheck(2);
			}
			else if (playerresult[i][playerorder[playerpointer]] == 3) {//3��Ÿ
				getscorecheck(3);
			}
			else if (playerresult[i][playerorder[playerpointer]] == 4) {//4��Ÿ
				getscorecheck(4);
			}
			else { //�ƿ��� ���
				outcount++;
			}
			playerpointer++;
			if (playerpointer == 10) { playerpointer = 1; } //9�� ���ڱ��� �� ġ�� �ٽ� 1�� ����
		}
	}
	return resultscore;
}
void P(int cnt) {
	if (cnt == 10) {
		int tmp = gamestart();
		if (maxscore < tmp) { //�� case�� Ȯ���Ǹ� ������ �����Ѵ�.
			maxscore = tmp;
		} 
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (playerordercheck[i] == true) continue;//���� �������� ���� �������playerordercheck[i] = true;
		playerordercheck[i] = true;
		playerorder[i] = cnt;
		P(cnt + 1); //��� ����case�� ã��
		playerordercheck[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	playerordercheck[4] = true; //4��Ÿ�ڴ� 1������ ����(��������) -�̹� �ڸ��� ������
	playerorder[4] = 1;
	P(2); //1���� �̹� �ڸ� ������ �Ϸ�Ǿ�������... permutation(����)
	      //������ ����ؾ���
	cout << maxscore << "\n";

	return 0;
}