#include<bits/stdc++.h>
using namespace std;

int n;
double w;
vector<int> treeedge[500001];
int leafnodecount;

void inputs() {
	cin >> n >> w;
	int tmp1, tmp2;
	for (int i = 0; i < n-1; i++) {
		cin >> tmp1 >> tmp2;
		treeedge[tmp1].push_back(tmp2);
		treeedge[tmp2].push_back(tmp1);
	}
}
void findleaf() {
	for (int i = 2; i <= n; i++) {
		if (treeedge[i].size() == 1) { leafnodecount++; }
		//루트노드 빼고 간선이 1개만 연결된 것이 리프노드
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	findleaf();
	cout.precision(11);
	cout << (w / leafnodecount);
	return 0;
}