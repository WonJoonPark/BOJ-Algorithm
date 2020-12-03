#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
//4,000,000,000,000 에 가까운 최대?

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	long long resultsum=0;
	for (long long i = 1; i < N; i++) { //int 왜 안됨
		resultsum += (N + 1)*i;
	}
	cout << resultsum;
	return 0;
}