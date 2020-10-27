#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int S, X, Y;
int virusmap[201][201];
bool viruscheck[201][201];
int dx[4] = { 0,0,1,-1 }; //4���� Ž���� ����
int dy[4] = { 1,-1,0,0 };
struct vi { int x; int y; int num; }; //���̷��� ��ǥ�� number�� �����ϴ� ����ü
vector<vi> tmparr; //1�ʸ��� 4���� Ž���� �����ؾ��ϴ� �ĺ�?���̷������� ���� set

void inputs() { //�Է��Լ�
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
bool cmp(vi a, vi b) { //���̷��� ��ȣ �� ������ ���� ���Լ�
	if (a.num < b.num) return true;
	else return false;
}
void startinfection(int x, int y) { //4���� Ž��
	for (int i = 0; i < 4; i++) {
		if (x+dx[i]>=0&&x+dx[i]<N&&y+dy[i]>=0&&y+dy[i]<N&&viruscheck[x+dx[i]][y+dy[i]] == false) {
			virusmap[x + dx[i]][y + dy[i]] = virusmap[x][y];
			viruscheck[x + dx[i]][y + dy[i]] = true;
		}
	}
}
void makeascvirusset() { //���̷���map�� Ž���ؼ� ���̷����� set�� �־�д�
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
		if (virusmap[x-1][y-1] != 0) { cout << virusmap[x-1][y-1]; break; } //�̹� �����ϰ� �ִ� ���̷����� ������ �ű⿡ �ٸ� ���̷����� �ü� �����Ƿ� �ٷ� ���
		if (second == s) { cout << 0; break; } //�ð��� �¾Ҵµ� ���� if���� �� �ɷȴٴ� ���̹Ƿ� 0 ���
		tmparr.clear();
		makeascvirusset();
		sort(tmparr.begin(), tmparr.end(), cmp); //set�� �����Ѵ�(��������) ���� ���̷������� ������ �����ϹǷ�
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