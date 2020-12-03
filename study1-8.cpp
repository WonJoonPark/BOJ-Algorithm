#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
long long resultsum;
vector<int> filearr;
int clustersize;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp; filearr.push_back(tmp);
	}
	cin >> clustersize;
	for (int i = 0; i < filearr.size(); i++) {
		if(filearr[i]==0) continue;
		int tmpcount;
		if (filearr[i] % clustersize == 0) { tmpcount = filearr[i] / clustersize; }
		else tmpcount = filearr[i] / clustersize + 1;
		resultsum += tmpcount * clustersize;
	}
	cout << resultsum;
	return 0;
}