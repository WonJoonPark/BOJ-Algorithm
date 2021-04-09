#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> endtime; //끝나는 시간 기준
vector<pair<int, int>> classtime;
int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int si, ti;
	for (int i = 0; i < n; i++) {
		cin >> si >> ti;
		classtime.emplace_back(make_pair(si, ti));
	}
	sort(classtime.begin(), classtime.end()); // 시작시간 기준으로 정렬
	endtime.emplace(classtime[0].second);
	for (int i = 1; i < n; i++) {
		if (classtime[i].first >= endtime.top()) { //강의실이 필요x
			endtime.pop();
			endtime.emplace(classtime[i].second);
		}
		else endtime.emplace(classtime[i].second);
	}
	cout << endtime.size();
	return 0;
}