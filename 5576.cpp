#include<bits/stdc++.h>
using namespace std;

int warr[10];
int karr[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) cin >> warr[i];
	for (int i = 0; i < 10; i++) cin >> karr[i];
	sort(warr, warr + 10);
	sort(karr, karr + 10);
	int wsum = warr[9] + warr[8] + warr[7];
	int ksum = karr[9] + karr[8] + karr[7];
	cout << wsum << " " << ksum;
	return 0;
}