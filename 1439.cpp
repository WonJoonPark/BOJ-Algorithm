#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int count0;
int count1;
int resultcount;
int main() {


	string inputs;
	cin >> inputs;
	if (inputs[0] == '0') { count0++; }
	else { count1++; }

	int nows=inputs[0];

	for (int i = 1; i < inputs.length(); i++) {
		if (inputs[i] != nows) {
			if (inputs[i] == '0') { count0++; nows = inputs[i]; }
			else { count1++; nows = inputs[i]; }
		}
	}
	cout << min(count0, count1) << "\n";
	return 0;
}