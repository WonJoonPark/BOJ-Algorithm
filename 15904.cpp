#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string inputs;
char ucpc[5] = "UCPC"; //0,1,2,3

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, inputs);
	int index = 0;
	for (int i = 0; i < inputs.size(); i++) {
		if (index == 4) break;
		if (inputs[i] == ucpc[index]) index++;
	}
	if (index == 4) cout << "I love UCPC" << "\n";
	else cout << "I hate UCPC" << "\n";
	return 0;
}