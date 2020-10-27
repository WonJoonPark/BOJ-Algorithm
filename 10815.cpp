#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int Narr[500001];
int Marr[500001];

void inputs() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Narr[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> Marr[i];
	}
}
void bs(int start,int end,int searchnum) {
	int mid = (start + end) / 2;
	if (Narr[mid] == searchnum) { cout << 1 << " "; return; }
	if (mid >= end) { cout << 0 << " "; return; }
	if (Narr[mid] > searchnum) { bs(start, mid-1, searchnum); }
	if (Narr[mid] < searchnum) { bs(mid+1, end, searchnum); }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	sort(Narr, Narr+N);
	for (int i = 0; i < M; i++) {
		bs(0, N - 1, Marr[i]);
	}
	return 0;
}