#include<iostream>
#include<vector>
using namespace std;

int N, L, R;
int ground[51][51];
int visited[51][51];//�湮���� üũ
int dx[4] = { 0,0,-1,1 }; //4���� Ž��
int dy[4] = { 1,-1,0,0 };
int peoplesum = 0; //������ �α��� ��
int nationcount = 0; // ������ ��
int resultcount; //����� �α��̵�
bool finish = false; //�α��̵��� �ѹ��̶� �Ͼ������ üũ�ϱ� ����
vector<pair<int, int>> node; //����� �������� ��ġ�� �����صα� ���� ����
pair<int, int> tmp; //�ӽú���
 
void inputs() { //�Է��Լ�
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ground[i][j];
		}
	}
}
int gapabs(int num1, int num2) { //�α��� ���̸� ����
	if (num1 > num2) return (num1 - num2);
	else return (num2 - num1);
}
void searchmove(int i,int j) { //dfs �����
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		if (i + dx[k] >= 0 && i + dx[k] < N&&j + dy[k] >= 0 && j + dy[k] < N&&visited[i+dx[k]][j+dy[k]]==false) {//�湮���� �ʾҰ�, ���� ����
			if (gapabs(ground[i][j], ground[i + dx[k]][j + dy[k]]) >= L && gapabs(ground[i][j], ground[i + dx[k]][j + dy[k]]) <= R) { //L�̻� R������ ��츸
				finish = true; //�ѹ��̶� �α��� �̵��� �̵��� �Ͼ ��� ---> ���������� ����...!!
				nationcount += 1;
				peoplesum += ground[i + dx[k]][j + dy[k]];
				tmp.first = i+dx[k]; tmp.second = j+dy[k];
				node.push_back(tmp);
				searchmove(i + dx[k], j + dy[k]); //dfs����
			}
		}
	}
}
void initvisited() { //�湮�迭�� �ʱ�ȭ (�α��̵� �߻� �� �ʱ�ȭ���־�� ��)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	while (1) { //�ѹ��� �α��̵����� while ���� ����
		finish = false;
		initvisited();//�湮�迭 �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == false) {
					node.clear();
					nationcount = 1;
					peoplesum = ground[i][j];
					tmp.first = i; tmp.second = j;
					node.push_back(tmp); //���߿� �α��� ������ ����� �ϹǷ� x,y��ǥ�� ���Ϳ� �־���´�.
					searchmove(i, j);//dfs ����
					if(finish==true){
						for (int i = 0; i < node.size(); i++) { //�� ������ �α���/�����Ǽ� �� ���� x,y,�� �����س��Ҵ� ������ �־��ش�.
							ground[node[i].first][node[i].second] = peoplesum / nationcount;
					}
				}
				}
			}
		}
		if (finish == false) { cout << resultcount; break; }
		else { resultcount++; }
	}
	return 0;
}