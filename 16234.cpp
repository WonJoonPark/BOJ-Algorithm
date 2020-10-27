#include<iostream>
#include<vector>
using namespace std;

int N, L, R;
int ground[51][51];
int visited[51][51];//방문여부 체크
int dx[4] = { 0,0,-1,1 }; //4방향 탐색
int dy[4] = { 1,-1,0,0 };
int peoplesum = 0; //구역의 인구수 합
int nationcount = 0; // 구역의 수
int resultcount; //몇번의 인구이동
bool finish = false; //인구이동이 한번이라도 일어났는지를 체크하기 위한
vector<pair<int, int>> node; //연결된 구역들의 위치를 저장해두기 위한 벡터
pair<int, int> tmp; //임시벡터
 
void inputs() { //입력함수
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ground[i][j];
		}
	}
}
int gapabs(int num1, int num2) { //인구수 차이를 리턴
	if (num1 > num2) return (num1 - num2);
	else return (num2 - num1);
}
void searchmove(int i,int j) { //dfs 수행부
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		if (i + dx[k] >= 0 && i + dx[k] < N&&j + dy[k] >= 0 && j + dy[k] < N&&visited[i+dx[k]][j+dy[k]]==false) {//방문하지 않았고, 지도 내부
			if (gapabs(ground[i][j], ground[i + dx[k]][j + dy[k]]) >= L && gapabs(ground[i][j], ground[i + dx[k]][j + dy[k]]) <= R) { //L이상 R이하인 경우만
				finish = true; //한번이라도 인구수 이동이 이동이 일어난 경우 ---> 종료조건을 위한...!!
				nationcount += 1;
				peoplesum += ground[i + dx[k]][j + dy[k]];
				tmp.first = i+dx[k]; tmp.second = j+dy[k];
				node.push_back(tmp);
				searchmove(i + dx[k], j + dy[k]); //dfs수행
			}
		}
	}
}
void initvisited() { //방문배열을 초기화 (인구이동 발생 후 초기화해주어야 함)
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
	while (1) { //한번의 인구이동마다 while 내부 수행
		finish = false;
		initvisited();//방문배열 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == false) {
					node.clear();
					nationcount = 1;
					peoplesum = ground[i][j];
					tmp.first = i; tmp.second = j;
					node.push_back(tmp); //나중에 인구수 조정을 해줘야 하므로 x,y좌표를 벡터에 넣어놓는다.
					searchmove(i, j);//dfs 수행
					if(finish==true){
						for (int i = 0; i < node.size(); i++) { //총 구역의 인구수/구역의수 를 각각 x,y,를 저장해놓았던 구역에 넣어준다.
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