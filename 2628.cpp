#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> cutting[2]; //0은 가로 1은 세로
int maxresult = -1;
int w, h;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> w >> h >> n;
	int tmp1, tmp2;
	cutting[0].push_back(0); cutting[0].push_back(w);
	cutting[1].push_back(0); cutting[1].push_back(h);
	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2;
		if (tmp1 == 0) {
			cutting[1].push_back(tmp2);
		}
		else {
			cutting[0].push_back(tmp2);
		}
	}
	sort(cutting[0].begin(), cutting[0].end());
	sort(cutting[1].begin(), cutting[1].end());

	for (int i = 0; i < cutting[0].size() - 1; i++) {
		for (int j = 0; j < cutting[1].size() - 1; j++) {
			if( (cutting[0][i] - cutting[0][i + 1])*(cutting[1][j] - cutting[1][j + 1]) > maxresult){
				maxresult = (cutting[0][i] - cutting[0][i + 1])*(cutting[1][j] - cutting[1][j + 1]);
			}
		}
	}
	cout << maxresult << "\n";
	return 0;
}