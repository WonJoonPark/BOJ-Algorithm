#include<bits/stdc++.h>
using namespace std;

int n, k;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tmpq; // <걸린시간, 위치>
bool visited[100001];


void findsecond() {
	while (1) {
		int tx = tmpq.top().second;
		int tc = tmpq.top().first;
		tmpq.pop();
		if (tx == k) { cout << tc; return; } //못만나는 일은 없다.
		if (tx * 2 < 100001 && !visited[tx * 2]) {
			tmpq.push({ tc,tx * 2 });
			visited[tx * 2] = true;
		}
		if (tx + 1 < 100001 && !visited[tx + 1]) {
			tmpq.push({ tc + 1,tx + 1 });
			visited[tx + 1] = true;
		}
		if (tx - 1 >= 0 && !visited[tx - 1]) {
			tmpq.push({ tc + 1,tx - 1 });
			visited[tx - 1] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if (n >= k) { cout << n - k; }
	else {
		tmpq.push({ 0,n });
		visited[0] = true;
		findsecond();
	}
	return 0;
}