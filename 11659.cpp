#include<bits/stdc++.h>
using namespace std;

int n,t;
int narr[100001]; //1~n까지의 합을 저장하자
int s, e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> t;
	int tmpsum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> narr[i];
		narr[i] = narr[i] + tmpsum;
		tmpsum = narr[i];
	}
	while (t--) {
		cin >> s >> e;
		cout << narr[e] - narr[s - 1] << "\n";
	}
	return 0;
}