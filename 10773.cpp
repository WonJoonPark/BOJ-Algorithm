#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	vector<int> arr;
	int num=0;
	int result = 0;
	while (T--) {
		cin >> num;
		if (num == 0) {
			arr.pop_back();
		}
		else {
			arr.push_back(num);
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		result += arr[i];
	}
	cout << result << '\n';
	return 0;
}