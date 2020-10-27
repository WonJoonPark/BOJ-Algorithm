#include<iostream>
using namespace std;

int howmanyzero(int input) {
	int returnvalue = 1;
	while (1) {
		input /= 10;
		if (input == 0) break;
		returnvalue++;
	}
	return returnvalue;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int resultmodeten = 0;
	for (int i = 1; i <= N; i++) {
		resultmodeten += howmanyzero(i);
	}
	cout << resultmodeten << '\n';
	return 0;
}