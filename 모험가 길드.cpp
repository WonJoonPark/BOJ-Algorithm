#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	int N, tmp;
	cin >> N;
	vector<int> advennum;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		advennum.push_back(tmp);
	}
	sort(advennum.begin(), advennum.end());
	int nowscared = 0;
	int countnum = 0;
	int result = 0;
	for (int i = 0; i < advennum.size();i++) {
		nowscared = advennum[i];
		countnum++;
		for (int j = i + 1; j < advennum.size(); j++) {
			if (countnum == nowscared) {
				i = j-1;
				result++; break;
			}
			if (nowscared < advennum[j]) {
				nowscared = advennum[j];
			}
			countnum++;
			i = j- 1;
		}
		countnum = 0;
	}
	cout << result << "\n";
	return 0;
}