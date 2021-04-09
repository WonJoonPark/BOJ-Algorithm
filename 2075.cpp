#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> minheap;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			minheap.push(x);
		}
		if (i != 0) {
			while (minheap.size() > n) {
				minheap.pop();
			}
		}
	}
	cout << minheap.top();
	return 0;
}