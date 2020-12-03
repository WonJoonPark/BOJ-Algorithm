#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string binarys;
		int resultsum=0;
		int tmpvalue = 1;
		cin >> binarys;
		for (int j = 23; j >= 0; j--) {
			if (binarys[j] == '1') { resultsum += tmpvalue; }
			tmpvalue *= 2;
		}
		cout << resultsum << "\n";
	}
	return 0;
}