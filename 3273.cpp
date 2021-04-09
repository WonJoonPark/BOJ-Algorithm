#include<bits/stdc++.h>
using namespace std;

int n;
int x;
int narr[100001];
int resultcount = 0;

bool binarysearch(int val,int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (narr[mid]+val == x) return true;
		if (narr[mid] + val < x) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> narr[i];
	}
	cin >> x;
	sort(narr, narr + n);
	for (int i = 0; i < n; i++) {
		if (binarysearch(narr[i], i+1, n - 1)) resultcount++;
	}
	cout << resultcount;
	return 0;
}