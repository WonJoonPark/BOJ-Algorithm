#include<bits/stdc++.h>
using namespace std;

pair<int,int> score[8]; //first=index, second=score

bool compare(pair<int, int> &s1, pair<int, int> &s2) {
	if (s1.second > s2.second) return true;
	else return false;
}
bool compare2(pair<int, int>& s1, pair<int, int>& s2) {
	if (s1.first < s2.first) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tmp;
	int resultsum = 0;
	for (int i = 0; i < 8; i++) {
		cin >> tmp;
		score[i].first = i+1; score[i].second = tmp;
	}
	sort(score, score + 8,compare);
	sort(score, score + 5, compare2);
	for (int i = 0; i < 5; i++) {
		resultsum += score[i].second;
	}
	cout << resultsum << "\n";
	for (int i = 0; i < 5; i++) {
		cout << score[i].first << " ";
	}


	return 0;
}