#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> nolisten;
string tmp;
vector<string> noseelisten;
bool bnsearch(int front, int rear, string tmp) {
	if (front > rear) { return false; }
	else {
		int mid = (front + rear) / 2;
		if (nolisten[mid] == tmp) {
			return true;
		}
		else if (nolisten[mid] > tmp) { return bnsearch(front, mid - 1, tmp); }
		else { return bnsearch(mid + 1, rear, tmp); }
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		nolisten.push_back(tmp);
	}
	sort(nolisten.begin(), nolisten.end());
	int resultcount = 0;
	for (int j = 0; j < M; j++) {
		cin >> tmp;
		if (bnsearch(0, N, tmp) == true) {
			noseelisten.push_back(tmp);
			resultcount++;
		}
	}
	cout << resultcount << '\n';
	sort(noseelisten.begin(), noseelisten.end());
	for (int i = 0; i < noseelisten.size(); i++) {
		cout << noseelisten[i] << '\n';
	}
	return 0;
}