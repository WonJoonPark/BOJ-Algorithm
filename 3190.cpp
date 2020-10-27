#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int map[101][101]; //����� �ִ��� ���θ� �˱� ����
int jirung[101][101];//�������� ������ġ
int directionjirung[101][101]; //������ ���� �����̰� �� ��ǥ���� �����ִ� ������ ���
int N;
int K;
int dx[4] = {0,1,0,-1}; //��������
int dy[4] = {1,0,-1,0};
int direction=0; //�����̰� �����ִ� ����(ó���� ���� �����ִ�.)
int gamesecond;
int L;
int headx, heady,tailx,taily;
queue<pair<int, char>> dq;

void setapple() {
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		map[x][y] = 1; //����� �����ϴ� ��ġ
	}
}
void setqueue() {
	pair<int, char> tmppair;
	for (int i = 0; i < L; i++) {
		cin >> tmppair.first >> tmppair.second;
		dq.push(tmppair);
	}
}

int main() {
	cin >> N >> K;
	setapple();
	cin >> L;
	setqueue();
	headx = 1; heady = 1; tailx = 1; taily = 1;
	jirung[1][1] = 1;
	while (1) {
		while (1) {
			if (dq.empty() == false && gamesecond == dq.front().first) {
				if (dq.front().second == 'L') { //���� ȸ��
					direction = (direction + 3) % 4;
				}
				else {//������ ȸ��
					direction = (direction + 1) % 4;
				}
				dq.pop();
			}
			else break;
		}
		gamesecond++;

		directionjirung[headx][heady] = direction; //���������� ������ ��ϸ��� !
		headx += dx[direction]; heady += dy[direction];
		if (headx <= 0 || heady <= 0 || headx > N || heady > N || jirung[headx][heady] == 1) {  break; } //�������� (map�� ���� 1~N)

		jirung[headx][heady] = 1; //�Ӹ��� ������ �� ǥ��
		if (map[headx][heady] == 1) { //����� �ִٸ�
			map[headx][heady] = 0; 
		}
		else {
			jirung[tailx][taily] = 0; //����� ���ٸ� ������ǥ ������
			int tmptailx = tailx;
			int tmptaily = taily;
			tailx = tailx + dx[directionjirung[tmptailx][tmptaily]]; //������ ��ġ ������Ʈ (�Ӹ��� �������� �� �������� ������Ʈ)
			taily = taily + dy[directionjirung[tmptailx][tmptaily]];
		}
	}
	cout << gamesecond << "\n";
			return 0;
}
