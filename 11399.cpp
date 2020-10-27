#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	vector<int> pi;
	int tmp;

	cin >> n;
	while (n--) {
		cin >> tmp;
		pi.push_back(tmp);
	}
	sort(pi.begin(), pi.end());
	int sum = pi[0];
	for (int i = 1; i < pi.size(); i++) {
		pi[i] = pi[i - 1] + pi[i];
		sum += pi[i];
	}
	cout << sum << '\n';
	return 0;
}