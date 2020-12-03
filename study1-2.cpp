#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	int num1, num2;
	for (int i = 1; i <= T; i++) {
		cin >> num1 >> num2;
		cout << "Case #" << i << ": "
			<< num1 << " + " << num2 << " = " << num1 + num2 << "\n";
	}


	return 0;
}