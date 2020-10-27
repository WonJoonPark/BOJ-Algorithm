#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define sipman 100000

vector<int> arr[200001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int x, y;
	while (N--) {
		cin >> x >> y;
     	arr[x + sipman].push_back(y + sipman);
	}
	for (int i = 0; i < 200001; i++) {
		if (arr[i].size() == 1) { cout << i - sipman << " " << arr[i][0] - sipman << '\n'; }
		else {
			sort(arr[i].begin(), arr[i].end());
			for (int j = 0; j < arr[i].size(); j++) {
				cout << i - sipman << " " << arr[i][j] - sipman << '\n';
			}
		}
	}
	return 0;
}
