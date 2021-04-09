#include<bits/stdc++.h>
using namespace std;

int n;
int narr[100001];
long long result;

int findvalue(int s, int low, int high) {
	while (low < high) {
		int mid = (low + high) / 2;
		if (narr[mid] * 0.9 <= narr[s]) {
			low = mid + 1;
		}
		else high = mid;
	}
	return high - 1; //upperbound
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> narr[i];
	}
	sort(narr, narr + n);
	narr[n] = 1e8 + 1;
	for (int i = 0; i < n; i++) {
		result += findvalue(i, i, n) - i; //이진탐색 수행
	}
	cout << result;
	return 0;
}