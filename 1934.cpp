#include<iostream>
using namespace std;

int T;
int A,B;

int gcd(int n1, int n2) {
	if (n1%n2 == 0) return n2;
	return gcd(n2, n1%n2);
}
int lcm(int n1, int n2) {
	return (n1 * n2) / (gcd(n1, n2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	while (T--) {
		cin >> A >> B;
		cout << lcm(A, B) << "\n";
	}
	return 0;
}