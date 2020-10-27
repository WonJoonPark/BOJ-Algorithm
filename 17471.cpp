#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool check[11]; //방문한 노드인지 확인
int groupindex[11]; //CASE별 각 구역이 어떤 선거구에 포함되어있는지 확인
vector<int> edges[11]; //연결된 간선 정보 저장
int peoplecount[11]; //각 구역별 인구수 저장변수
int tmp;
int N;
vector<int> votecamp1; //선거구1에 해당하는 구역을 담을 벡터
vector<int> resultmin;//각 CASE별 인구 수 차이를 담아놓을 변수

void input() {//입력받는 함수
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> peoplecount[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int n; cin >> n;
			edges[i].push_back(n);
		}
	}

}
int getsum(vector<int> arr) { //인구수 합 구하는 함수
	int s = 0;
	for (int i = 0; i < arr.size(); i++) {
		s += peoplecount[arr[i]];
	}
	return s;
}
void resetcheck() { //초기화함수
	for (int i = 0; i < 11; i++) {
		check[i] = false;
	}
}
int gap(int num1, int num2) { //단순히 차이를 리턴하는 함수
	if (num1 > num2) { return (num1 - num2); }
	else { return (num2 - num1); }
}
void dfs(int index,int g) { //DFS수행
	check[index] = true;
	for (int i = 0; i < edges[index].size(); i++) {
		if (check[edges[index][i]]==false&&groupindex[edges[index][i]] == g) {
			//방문하지 않았고, 나와 같은 선거구 인 경우 탐색을 수행
			dfs(edges[index][i],g);
		}
	}
	return;
}
bool all() { //모두 방문했는지 체크를 위한 함수
	for (int i = 1; i <= N;i++) {
		if (check[i] == false) return false;
	}
	return true;
}
void groupindexreset() { //초기화 함수
	for (int i = 0; i < 11; i++) {
		groupindex[i] = 1;
	}
}
void checkvotecamp() {
	if (votecamp1.size() == N) { return; }
	vector<int> votecamp2; //선거구2를 담을 변수
	groupindexreset(); //각 지역이 어떤 선거구에 속했는지를 담을 변수 초기화
	for (int i = 1; i <= N; i++) { //1에 속하지 않은 지역은 2에 넣기
		bool c = false;
		for (int j = 0; j < votecamp1.size(); j++) {
			if (votecamp1[j] == i) { c = true; break; }
		}
		if (c == false) { votecamp2.push_back(i);
		groupindex[i] = 2;
		}
	}
	resetcheck();
	dfs(votecamp1[0],1); //선거구의 지역이 모두 연결되어있는지 체크를 위해 DFS
	dfs(votecamp2[0],2);
	if (all() == true) {
		int first = getsum(votecamp1);
		int second = getsum(votecamp2);
		resultmin.push_back(gap(first, second));
	}

}
void makecase(int num) { //순열CASE(수가 정해지지 않은)
	if (num > N) { return; }
	for (int i = num; i <= N; i++) {
		votecamp1.push_back(i);
		checkvotecamp();
		makecase(i + 1);
		votecamp1.pop_back();
	}
}
int main() {
	// 1 ~ N 의 구역
	input(); //입력
	makecase(1); //케이스 만들자
	sort(resultmin.begin(), resultmin.end()); //최소값 출력 부
	if (resultmin.empty()) { cout << -1; return 0; }
	cout << resultmin[0];
	return 0;
}