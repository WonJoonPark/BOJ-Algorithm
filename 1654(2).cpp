#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long N;
int K;
vector<long long> lanarr;

long long numcheck(long long t) {
	long long tmpreturn=0;
	for (int i = 0; i < lanarr.size(); i++) {
		tmpreturn += lanarr[i] / t;
	}
	return tmpreturn;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> K >> N;
	long long tmp;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		lanarr.push_back(tmp);
	}
	sort(lanarr.begin(), lanarr.end(), greater<long long>() );
	long long bottom = 1;
	long long top = lanarr[0];
	long long mid;
	while (top>=bottom) {
		mid = (bottom + top) / 2;
		if (numcheck(mid) < N) {
			top = mid-1;
		}
		else if (numcheck(mid) >= N) {
			bottom = mid+1;
		}
	}
	cout << top << '\n';
	return 0;
}