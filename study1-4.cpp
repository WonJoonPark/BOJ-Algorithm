#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool student[31];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int snum = 28;
	int tmp;
	while (snum--) {
		cin >> tmp;
		student[tmp] = true;
	}
	for (int i = 1; i < 31; i++) {
		if (student[i] == false) cout << i << "\n";
	}


	return 0;
}