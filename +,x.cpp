#include<iostream>
#include<string>
using namespace std;


int main() {
	string a;
	cin >> a;
	//a[i]-48

	int result = a[0]-48;

	for (int i = 1; i < a.length(); i++) {
		if (result == 0 || a[i] == 0 || a[i] == 1) {
			result += a[i]-48;
		}
		else { 
			result *= a[i]-48;
		}
	}
	cout << result << endl;

	return 0;
}