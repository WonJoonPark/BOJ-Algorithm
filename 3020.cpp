#include<bits/stdc++.h>
using namespace std;

int n, h,tmph;
int barrier[500001];
int seoksoon[500001];
int jongyu[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> tmph;
		if (i % 2 == 0) {
			seoksoon[tmph]++;
		}
		else {
			jongyu[tmph]++;
		}
	}
	int tmp = seoksoon[h];
	for (int i = h; i > 0; i--) {
		barrier[i] = tmp;
		tmp += seoksoon[i - 1];
	}

	tmp = jongyu[h];
	for (int i = h; i > 0; i--) {
		barrier[h+1 - i] += tmp;
		tmp += jongyu[i - 1];
	}
	 // 1 ~ h ±¸°£
	sort(barrier + 1, barrier + h+1);
	int fv = barrier[1];
	int vcount = 1;
	for (int i = 2; i <= h; i++) {
		if (fv != barrier[i]) break;
		vcount++;
	}
	cout << fv << " " << vcount;

	return 0;
}