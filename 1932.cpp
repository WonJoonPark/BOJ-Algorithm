#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int maximum(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	vector<int> tmparr[2];
	tmparr[1].push_back(num2+num1);
	tmparr[1].push_back(num3+num1);
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> num1;
			if (i % 2 == 0) {
				if (j == 0) {
					tmparr[0].push_back(tmparr[1][0] + num1); //끝
				}
				else if (j == i) {
					tmparr[0].push_back(tmparr[1][j-1] + num1); //마지막
				}
				else {
					tmparr[0].push_back(maximum(tmparr[1][j]+num1, tmparr[1][j - 1]+num1)); //중간은 큰수
				}
			}
			else {
				if (j == 0) {
					tmparr[1].push_back(tmparr[0][0] + num1); //끝
				}
				else if (j == i) {
					tmparr[1].push_back(tmparr[0][j-1] + num1); //마지막
				}
				else {
					tmparr[1].push_back(maximum(tmparr[0][j]+num1, tmparr[0][j - 1]+num1)); //중간은 큰수
				}
			}
		}
		if (i % 2 == 0) {tmparr[1].clear();}
		else {tmparr[0].clear();}
	}
	if (n % 2 == 0) {
		sort(tmparr[1].begin(), tmparr[1].end(), greater<int>());
		cout << tmparr[1][0] << '\n';
	}
	else {
		sort(tmparr[0].begin(), tmparr[0].end(),greater<int> ());
		cout << tmparr[0][0] << '\n';
	}
	return 0;}