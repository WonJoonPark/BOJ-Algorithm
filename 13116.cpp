#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int tc;
int num1, num2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> tc;
	while (tc--) {
		int result = -1;
		cin >> num1 >> num2;
		if (num1 == 1 || num2 == 1) { cout << 10 << "\n"; continue; }
		vector<int> arr1;
		vector<int> arr2;
		while (1) {
			arr1.push_back(num1);
			if (num1 == 1) break;
			num1 /= 2;
		}
		while (1) {
			arr2.push_back(num2);
			if (num2 == 1) break;
			num2 /= 2;
		}
		//Ãâ·ÂºÎ
		int index1 = arr1.size() - 1;
		int index2 = arr2.size() - 1;
		while (1) {
			if (arr1[index1] != arr2[index2]) {
				result = arr1[index1 + 1];
				break;
			}
			else { index1--; index2 -= 1; }
		}
		cout << 10*result << "\n";
	}

	return 0;
}