#include<bits/stdc++.h>
using namespace std;

int N, M, T; // ������, ���Ǵ� ��, T�� ȸ����Ų��.
int circle[51][51]; // ���° ��/ ���° ��
bool visited[51][51]; //bfs�� ���� 
queue<pair<int, int>> tmpq;
int xi, di, ki;
int xdk[51][3];
bool checkexist = false;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
double tmpsum, tmpn;
bool neighbor = false;

//��ȣ�� xi�� ����� ������ di����(0-�ð�,1-�ݽð�) kiĭ ��ŭ ȸ��
void inputs() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> circle[i][j];
		}
	}
	for (int i = 1; i <= T; i++) {
		cin >> xdk[i][0] >> xdk[i][1] >> xdk[i][2];
	}
}
bool boundcheck(int x) {
	return (x >= 1 && x <= N); //���� ����
}
void rotate(int r) {
	for (int k = 0; k < xdk[r][2]; k++) {
		for (int i = 1; i <= N; i++) {
			if (i % xdk[r][0] != 0) continue; // xi�� ����� ���Ǹ� ȸ��

			int tmpnum;
			if (xdk[r][1] == 0) { // �ð����
				tmpnum = circle[i][M];
				for (int j = M; j >= 2; j--) {
					circle[i][j] = circle[i][j - 1];
				}
				circle[i][1] = tmpnum;
			}
			else { //�ݽð����
				tmpnum = circle[i][1];
				for (int j = 1; j < M; j++) {
					circle[i][j] = circle[i][j + 1];
				}
				circle[i][M] = tmpnum;
			}
		}
	}
}
void initvisit() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = false;
		}
	}
}
void bfs(int x, int y) {
	visited[x][y] = true;
	tmpq.push({x,y});
	while (!tmpq.empty()) {
		int qsize = tmpq.size();
		while (qsize--) {
			int nextx = tmpq.front().first;
			int nexty = tmpq.front().second;
			tmpq.pop();
			for (int i = 0; i < 4; i++) {
				int tx = nextx + dx[i]; int ty = nexty + dy[i];
				if (ty == 0) ty = M; //circular
				if (ty == M + 1) ty = 1;
				
				if (boundcheck(tx) && !visited[tx][ty] && circle[tx][ty] == circle[x][y]) {
					tmpq.push({ tx,ty });
					visited[tx][ty] = true;
					neighbor = true;
					circle[tx][ty] = 0; //�����
					checkexist = true;
				}
			}
		}
	}
	if (neighbor == true) {
		circle[x][y] = 0; 
	} //�ϳ��� �����ϸ� ���⵵ ����� (������)
}
void getsum() {
	tmpsum = 0; tmpn = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (circle[i][j] != 0) {
				tmpsum += circle[i][j];
				tmpn++;
			}
		}
	}
}
/*void watchcircle() {
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << circle[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs(); //���� ����
	for(int a=1;a<=T;a++) {
		rotate(a); //ȸ��
		getsum(); // ��ü ������ ���� �׵��� ��
		if (tmpn == 0) { cout << 0; return 0; }
		initvisit();
		checkexist = false; // �����ϸ鼭 ���� ���� �ϳ��� �����ϴ��� üũ
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				neighbor = false; //�̿��� �ϳ��� ������ �����ǰ� �ƴϸ� �������� ����
				if (circle[i][j] != 0 && visited[i][j] == false) {
					bfs(i, j);
				} // ����
			}
		}
		if (checkexist == false) { //������ ���� �������� ���� ��
			double avg = tmpsum / tmpn;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (circle[i][j] == 0) continue;

					if (circle[i][j] > avg) {
						circle[i][j]--; continue;
					}
					else if (circle[i][j] < avg) {
						circle[i][j]++; continue;
					}
				}
			}
		}
	}
	int resultsum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			resultsum += circle[i][j];
		}
	}
	cout << resultsum;
	return 0;
}