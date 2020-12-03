#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int T,N,K;
vector<int> candyset;
int childcount;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		candyset.clear();
		childcount = 0;
		cin >> N >> K;
		int tmpc;
		for (int i = 0; i < N; i++) {
			cin >> tmpc;
			candyset.push_back(tmpc);
		}
		for (int i = 0; i < candyset.size(); i++ ) {
			childcount += candyset[i] / K;
		}
		cout << childcount << "\n";
	}
	return 0;
}
