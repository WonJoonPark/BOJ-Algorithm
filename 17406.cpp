#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int K,r,s;
int doublearr[51][51]; //본 2차원 배멸 (변화 x)
int caculdoublearr[51][51]; //case별 결과값을 뽑아내기 위한 배열
int copydoublearr[51][51]; //이동을 위해 값을 복사해놓을 임시배열
bool check[51][51];
bool selected[7];
vector<int> resultmin;

struct rcs {
	int r,c,s;
};
vector<rcs> command; //입력받은명령
vector<rcs> casecommand; // 각 경우의수 (시뮬레이션 돌릴)

void input() { // 입력받는 함수		
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
void copyarr() { // 원본배열은 그대로 두고 복사해서 사용 (각 테스트케이스마다 써야하므로)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			copydoublearr[i][j] = doublearr[i][j];
			caculdoublearr[i][j] = doublearr[i][j];
		}
	}
}
void initcheck() { // 방문배열 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			check[i][j] = false;
		}
	}
}
void copycal() { //한번회전한 배열을 계산을 위한 배열에 복사
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			copydoublearr[i][j] = caculdoublearr[i][j];
		}
	}
}
void turnarr(int r, int c, int s) { //회전을 구현
	int x = r - s;
	int y = c - s;
	int tmpcount = 0;
	int totalcount = 8 * s; //연산해야하는 횟수 한 바퀴에
	char dir = 'R';
	initcheck();
	while (1) {
		if (totalcount == tmpcount) { //바깥한바퀴 -> 안쪽 바퀴로 들어감
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
int getmin() { //배열의 최소값을 뽑아내는 함수
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
void relocating() { //명령을 수행 (회전명령)
	copyarr();
	for (int i = 0; i < K; i++) {
		turnarr(casecommand[i].r, casecommand[i].c, casecommand[i].s);
	}
	resultmin.push_back(getmin());
}
void simulation(int n) { //순열 경우의 수 생성
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