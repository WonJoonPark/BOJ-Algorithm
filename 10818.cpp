#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int min = 1000000;
	int max = -1000000;
	while (N--) {
		int tmpinput;
		cin >> tmpinput;
		if (tmpinput > max) { max = tmpinput; }
		if (min > tmpinput) { min = tmpinput; }
	}
	cout << min << " " << max << '\n';
	return 0;
}