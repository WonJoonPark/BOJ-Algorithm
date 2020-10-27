#include<iostream>
using namespace std;

int GCD(int n1, int n2) {
	if (n1%n2 == 0) { return n2; } //종료조건
	else return GCD(n2, n1%n2);
};

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	if (n1 > n2) {
		int tmp;
		tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
	cout<<GCD(n1, n2)<<"\n";

	return 0;
}