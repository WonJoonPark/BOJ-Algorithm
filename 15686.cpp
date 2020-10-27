#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int map[51][51];
vector<pair<int, int>> chikenstore; //전체 치킨집을 저장할 좌표 집합
vector<pair<int, int>> chosenstore; //선택된 치킨집을 저장할 좌표 집합(M개)
vector<pair<int, int>> home; //집의 위치를 저장할 좌표 집합 (x,y) 
vector<int> result; //결과

void InputMap() { //입력받는 함수
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				pair<int, int> tmp;
				tmp.first = i; tmp.second = j;
				chikenstore.push_back(tmp);
			}
			else if (map[i][j] == 1) {
				pair<int, int> tmp;
				tmp.first = i; tmp.second = j;
				home.push_back(tmp);
			}
		}
	}
}

int abs(int num1, int num2) { //절대값 반환
	if (num1 - num2 > 0) { return num1 - num2; }
	else { return num2 - num1; }
}

int loadsum(int x1, int y1, int x2, int y2) { //거리 계산
	return abs(x1, x2) + abs(y1, y2);
}

void caculatechickenload() { //도시의 치킨거리를 계산
	int sum = 0;
	for (int i = 0; i < home.size(); i++) { //집마다
		int min = 3000;
		for (int j = 0; j < chosenstore.size(); j++) { //치킨집에 대하여 거리계산(가장 가까운 치킨집=치킨거리)
			if (min > loadsum(home[i].first, home[i].second, chosenstore[j].first, chosenstore[j].second)) {
				min = loadsum(home[i].first, home[i].second, chosenstore[j].first, chosenstore[j].second);
			}
		}
		sum += min;
	}
	result.push_back(sum);
}

void Mchickenstore(int index) {
	if (chosenstore.size() == M) { // M개를 골랐다면 치킨거리계산 시작
		caculatechickenload();
		return;
	}
	for (int i = index; i < chikenstore.size(); i++) { //조합 경우의 수
		chosenstore.push_back(chikenstore[i]);
		Mchickenstore(i + 1);
		chosenstore.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	InputMap();
	Mchickenstore(0);
	sort(result.begin(), result.end()); //가장 최소 도시치킨거리 출력
	cout << result[0] << "\n";
	
	return 0;
}