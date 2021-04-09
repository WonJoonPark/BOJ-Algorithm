#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, k;
int resultcount;
bool visit[100001];
queue<int> tmpq;
vector<int> tmpv;
int second = 1;
int nextn;
int qsize;
bool suc = false;
void checkrest() {
	while (qsize--) {
		nextn = tmpq.front(); tmpq.pop();
		if (nextn + 1 <= 100000 && nextn + 1 == k) resultcount++;
		if (nextn - 1 >= 0 && nextn - 1 == k) resultcount++;
		if (nextn * 2 <= 100000 && nextn * 2 == k) resultcount++;
	}
}

void bfs() {	
	while (1) {
		tmpv.clear();
		qsize = tmpq.size();
		while (qsize--) {
			nextn = tmpq.front();
			tmpq.pop();
			visit[nextn] = true;
			tmpv.push_back(nextn);
			
			//1Áõ°¡
			if (nextn + 1 <= 100000 && visit[nextn + 1] == false) {
				tmpq.push(nextn + 1);
				if (nextn+1 == k) {
					resultcount++;
					checkrest();
					return; }
			}

			if (nextn - 1 >= 0 && visit[nextn - 1] == false) {
				tmpq.push(nextn - 1);
				if (nextn-1 == k) {
					resultcount++;
					checkrest();
					return; }
			}

			if (nextn * 2 <= 100000 && visit[2 * nextn] == false) {
				tmpq.push(nextn * 2);
				if (nextn*2 == k) {
					resultcount++;
					checkrest();
					return; }
			}
		}
		second++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if (n >= k) {
		cout << n - k << "\n";
		cout << 1 << " ";
	}
	else {
		tmpq.push(n);
		visit[n] = true;
		bfs();
		cout << second << "\n" << resultcount << "\n";
	}
	return 0;
}