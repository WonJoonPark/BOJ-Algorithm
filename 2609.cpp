#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int GCD(int n1, int n2) {
	if (n2==0) return n1;
	return GCD(n2, n1%n2);
}
int LCM(int n1, int n2) {
	return n1 * n2 / (GCD(n1, n2));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num1, num2;
	cin >> num1 >> num2;
	cout << GCD(num1, num2) <<"\n"<<LCM(num1,num2)<<"\n";

	return 0;
}