#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int N;
int score[101];
int minussum = 0;
int tmpmin;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> score[i];
	}
	for (int j = N - 1; j >= 1; j--) {
		while (score[j] <= score[j - 1]) {
			score[j - 1] -= 1;
			minussum++;
		}
	}
	cout << minussum << "\n";
	return 0;
}