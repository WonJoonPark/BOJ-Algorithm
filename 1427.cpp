#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> result;

	while (1) {
		if (n == 0) { break; }
		result.push_back(n % 10);
		n /= 10;
	}
	sort(result.begin(), result.end(), greater<int>() );
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	cout << '\n';
	return 0;
}