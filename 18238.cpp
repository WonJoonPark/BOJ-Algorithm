#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int resulttime = 0;
string inputs;
char currentchar='A';

void gettime(char in) {
	if (in >= currentchar) {
		resulttime += min((int)(in - currentchar), (int)((currentchar - 'A') + ('Z' - in)+1));
	}
	else {
		resulttime += min((int)(currentchar - in), (int)('Z' - currentchar + (in - 'A')+1));
	}
	currentchar = in;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> inputs;
	for (int i = 0; i < inputs.length(); i++) {
		gettime(inputs[i]);
	}
	cout << resulttime << "\n";

	return 0;
}