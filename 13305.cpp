#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<long long> load(N-1);
	vector<long long> price(N);
	
	for (int i = 0; i < N-1; i++) {
		cin >> load[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}
	long long minoilprice = price[0];
	long long minresult = price[0]*load[0];
	for (int i = 1; i < N - 1; i++) {
		if (price[i] < minoilprice) {
			minoilprice = price[i];
		}
		minresult += (minoilprice*load[i]);		
	}
	cout << minresult << "\n";
	return 0;
}