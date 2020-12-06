#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> Narr;
int tmp;
bool exist = 0;

void find(int head,int tail,int num) {
	if (head > tail) return;
	int mid = (head + tail) / 2;
	if (Narr[mid] == num) exist = true;
	if (Narr[mid] > num) {
		find(head, mid-1, num);
	}
	else {
		find(mid+1, tail, num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp; Narr.push_back(tmp);
	}
	cin >> M;
	vector<int> Marr(M);
	for (int j = 0; j < M; j++) {
		cin >> Marr[j];
	}
	sort(Narr.begin(), Narr.end()); 

	//Á¤·Ä
	for (int i = 0; i < M; i++) {
		exist = 0;
		find(0,N-1,Marr[i]);
		if (exist == 1) { cout << 1 << "\n"; }
		else cout << 0 << "\n";
	}
	return 0;
}