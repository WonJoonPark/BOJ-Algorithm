#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long sum = 1;
	long long tmpmulti=1;
	while (1) {
		if (n <= sum) {
			cout << tmpmulti << '\n';
			break;
		}
		sum += 6 * tmpmulti;
		tmpmulti++;
	}
	return 0;
}
