#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string inputA;
	string inputB;

	cin >> inputA >> inputB;

	int max = 0;
	int tmpmax = 0;
	for (int i = 0; i <= inputB.length() - inputA.length(); i++) {
		for (int j = 0; j < inputA.length(); j++) {
			if (inputA[j] == inputB[i + j]) { tmpmax++; }
		}
		if (tmpmax > max) {
			max = tmpmax;
		}
		tmpmax = 0;
	}
	cout << inputA.length() - max << '\n';
}