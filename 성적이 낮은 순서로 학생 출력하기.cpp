#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std; 
struct student {
	string name;
	int score;
};
vector<student> scorebox[101];

int main() {
	int N;
	cin >> N;
	student tmps;
	int score[100001];
	for (int i = 0; i < N; i++) {
		cin >> tmps.name >> tmps.score;
		scorebox[tmps.score].push_back(tmps);
	}
	for (int i = 1; i < 101; i++) {
		for (int j = 0; j < scorebox[i].size(); j++) {
			cout << scorebox[i][j].name << " ";
		}
	}
	return 0;
}