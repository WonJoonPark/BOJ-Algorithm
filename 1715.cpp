#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> carddeck;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int card;
	for (int i = 0; i < N; i++) {
		cin >> card; carddeck.push(card);
	}
	int minsum = 0;
	int tmpcard1, tmpcard2;
	for (int i = 0; i < N-1; i++) {
		tmpcard1=carddeck.top();
		carddeck.pop();
		tmpcard2 = carddeck.top();
		carddeck.pop();
		minsum += (tmpcard1 + tmpcard2);
		tmpcard2 += tmpcard1;
		carddeck.push(tmpcard2);
	}
	cout << minsum;
	return 0;
}