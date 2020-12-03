#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T;
bool compare(int a, int b) {
	if (a > b) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		int N;
		int result;
		cin >> N;
		vector<int> namoo(N);
		for (int i = 0; i < N; i++) {
			cin >> namoo[i];
		}
		sort(namoo.begin(), namoo.end(),compare);
		result = max(namoo[0] - namoo[1], namoo[0] - namoo[2]);
		for (int i = 3; i < N; i += 2) {
			if ((namoo[i - 2] - namoo[i]) > result) result = namoo[i - 2] - namoo[i];
		}
		for (int i = 4; i < N; i += 2) {
			if((namoo[i-2]-namoo[i])>result) result = namoo[i - 2] - namoo[i];
		}
		cout << max(result, namoo[N - 2] - namoo[N - 1])<<"\n";
	}
	return 0;
}