#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int N;
long long tipsum;
int tiparr[100000];

bool compare(int a, int b) {
	if (a > b) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tiparr[i];
	}
	sort(tiparr, tiparr + N, compare);
	for (int i = 0; i < N; i++) {
		if ((tiparr[i] + 1 - (i + 1)) <= 0) break;
		tipsum += tiparr[i]+1 - (i + 1);
	}
	cout << tipsum << "\n";
	return 0;
}