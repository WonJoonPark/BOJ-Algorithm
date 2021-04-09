#include<bits/stdc++.h>
using namespace std;

int n;
long long resultcount = 0;

vector<long long> A, B, C, D;
vector<long long> AB, CD;
int a, b, c, d;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		A.push_back(a); B.push_back(b); C.push_back(c); D.push_back(d);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}
	sort(CD.begin(), CD.end());

	for (int i = 0; i < AB.size(); i++) {

		long long lowindex = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		long long highindex = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();

		
		if (-AB[i] == CD[lowindex]) { //값이 같으면
			resultcount += (highindex - lowindex);
		}

	}

	cout << resultcount;
	return 0;
}