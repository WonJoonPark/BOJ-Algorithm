#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int testscore;
	cin >> testscore;

	if(testscore>=90) {cout << "A" << '\n';}
	else if (testscore >= 80) { cout << 'B' << '\n'; }
	else if (testscore >= 70) { cout << 'C' << "\n"; }
	else if (testscore >= 60) { cout << "D" << '\n'; }
	else { cout << "F" << '\n'; }
	return 0;
}