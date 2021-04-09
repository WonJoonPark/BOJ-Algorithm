#include<bits/stdc++.h>
using namespace std;

int n, p;
int songscore;
int numarr[100];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> songscore >> p;
	for (int i = 0; i < n; i++) {
		cin >> numarr[i];
	}
	int  cnt = 0;
	int lank = 1;
	for (int i = 0; i < n; i++) {
		if (songscore < numarr[i]) lank++;
		else if (songscore == numarr[i]){
			cnt++; continue;
		}
		else break;
		cnt++;
	}
	if (cnt == p) {
		cout << -1; return 0;
	}
	if (n == 0) {
		cout << 1; return 0;
	}

	
	
	cout << lank;

	
	return 0;
}