#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int K,r,s;
int doublearr[51][51]; //�� 2���� ��� (��ȭ x)
int caculdoublearr[51][51]; //case�� ������� �̾Ƴ��� ���� �迭
int copydoublearr[51][51]; //�̵��� ���� ���� �����س��� �ӽù迭
bool check[51][51];
bool selected[7];
vector<int> resultmin;

struct rcs {
	int r,c,s;
};
vector<rcs> command; //�Է¹������
vector<rcs> casecommand; // �� ����Ǽ� (�ùķ��̼� ����)

void input() { // �Է¹޴� �Լ�		
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> doublearr[i][j];
		}
	}
	rcs tmp;
	for (int i = 0; i < K; i++) {
		cin >> tmp.r >> tmp.c >> tmp.s;
		command.push_back(tmp);
	}
}
void copyarr() { // �����迭�� �״�� �ΰ� �����ؼ� ��� (�� �׽�Ʈ���̽����� ����ϹǷ�)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			copydoublearr[i][j] = doublearr[i][j];
			caculdoublearr[i][j] = doublearr[i][j];
		}
	}
}
void initcheck() { // �湮�迭 �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			check[i][j] = false;
		}
	}
}
void copycal() { //�ѹ�ȸ���� �迭�� ����� ���� �迭�� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			copydoublearr[i][j] = caculdoublearr[i][j];
		}
	}
}
void turnarr(int r, int c, int s) { //ȸ���� ����
	int x = r - s;
	int y = c - s;
	int tmpcount = 0;
	int totalcount = 8 * s; //�����ؾ��ϴ� Ƚ�� �� ������
	char dir = 'R';
	initcheck();
	while (1) {
		if (totalcount == tmpcount) { //�ٱ��ѹ��� -> ���� ������ ��
			x += 1; y += 1; s -= 1; totalcount = 8 * s;
			tmpcount = 0;
		}
		if (dir == 'R') {
			if (check[x][y+1] == true) { copycal(); break;
			}
			caculdoublearr[x][y + 1] = copydoublearr[x][y];
			tmpcount++;
			check[x][y] = true;
			y += 1;
			if (y == c + s) { dir = 'D'; }
		}
		else if (dir == 'D') {
			caculdoublearr[x + 1][y] = copydoublearr[x][y];
			tmpcount++;
			check[x][y] = true;
			x += 1;
			if (x == r + s) { dir = 'L'; }
		}
		else if (dir == 'L') {
			caculdoublearr[x][y - 1] = copydoublearr[x][y];
			tmpcount++;
			check[x][y] = true;
			y -= 1;
			if (y == c - s) { dir = 'U'; }
		}
		else {
			caculdoublearr[x - 1][y] = copydoublearr[x][y];
			tmpcount++;
			check[x][y] = true;
			x -= 1;
			if (x == r - s) { dir = 'R'; }
		}
	}
}
int getmin() { //�迭�� �ּҰ��� �̾Ƴ��� �Լ�
	int mini = 5001;
	for (int i = 1; i <= N; i++) {
		int tmpsum = 0;
		for (int j = 1; j <= M; j++) {
			tmpsum += caculdoublearr[i][j];
		}
		if (tmpsum < mini) { mini = tmpsum; }
	}
	return mini;
}
void relocating() { //����� ���� (ȸ�����)
	copyarr();
	for (int i = 0; i < K; i++) {
		turnarr(casecommand[i].r, casecommand[i].c, casecommand[i].s);
	}
	resultmin.push_back(getmin());
}
void simulation(int n) { //���� ����� �� ����
	if (n == K) {
		relocating(); 
		return;
	}
	for (int i = 0; i < command.size(); i++) {
		if (selected[i] == true) continue;
		selected[i] = true;
		casecommand.push_back(command[i]);
		simulation(n+1);
		casecommand.pop_back();
		selected[i] = false;
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	simulation(0);
	sort(resultmin.begin(), resultmin.end());
	cout << resultmin[0];
	return 0;
}