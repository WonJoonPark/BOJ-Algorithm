#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

int n, k;
queue<int> tmpq;
bool visit[100001];
int from[100001]; //어디서 온 놈인지르 표시해주자
vector<int> resultarr;

int second = 0;

int bfs() {
	while (1) {
		int qsize = tmpq.size();
		while (qsize--) {
			int nextn = tmpq.front();
			tmpq.pop();
			if (nextn == k) { return second; }
			//1증가
			if (nextn + 1 <= 100000&& visit[nextn + 1] == false) {
				resultarr.push_back(2 * nextn);
				tmpq.push(nextn+1);
				visit[nextn + 1] = true;
				from[nextn + 1] = nextn;
			}

			if (nextn - 1 >= 0 && visit[nextn - 1] == false ) {
				tmpq.push(nextn - 1);
				resultarr.push_back(nextn - 1);
				visit[nextn - 1] = true;
				from[nextn - 1] = nextn;
			}
			
			if (nextn * 2 <= 100000&& visit[2 * nextn] == false) {
				tmpq.push(nextn *2);
				resultarr.push_back(nextn *2);
				visit[2 * nextn] = true;
				from[2 * nextn]=nextn;
			}
		}
		second++;
	}
}
void findparent() {
	int tmpk = k;
	resultarr.clear();
	resultarr.push_back(tmpk);
	while (1) {
		if (from[tmpk] == n) { resultarr.push_back(n); break; }
		resultarr.push_back(from[tmpk]);
		tmpk = from[tmpk];
	}
	for (int i = resultarr.size() - 1; i >= 0; i--) {
		cout<<resultarr[i] << " ";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int second = 0;
	if (n == k) { cout << 0 << "\n"; cout << n; return 0; }
	if (n > k) {
		cout << n-k<<"\n";
		cout << n << " ";
		for (int i = 1; i < (n - k); i++) {
			cout << n - i << " ";
		}
		cout << k << " ";
	}
	else {
		tmpq.push(n);
		visit[n] = true;
		cout << bfs() << "\n";
		findparent();
	}
	return 0;
}