#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int T;
int n;
long long fibo[1000];
vector<int> result;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	cin >> T;
	while (T--) {
		result.clear();
		cin >> n;
		fibo[0] = 0;
		fibo[1] = 1;
		int index = 2;
		while (1) {
			fibo[index] = fibo[index - 1] + fibo[index - 2];
			if (fibo[index] > n) break;
			index++;
		}
		for (int i = index-1; i >= 0; i--) {
			if (n >= fibo[i]) { 
				result.push_back(fibo[i]);
				n -= fibo[i];
			}
			if (n == 0) break;
		}
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}