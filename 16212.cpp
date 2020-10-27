#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> arr;
	int tmp;
	int L;
	cin >> L;
	while (L--) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	int N;
	cin >> N;
	int max = 1000;
	int min = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > N) {
			if (arr[i] < max) { max = arr[i]; }
	}
		else if (arr[i] == N) { cout << 0 << '\n'; return 0; }
		else if (arr[i] < N) {
			if (arr[i] > min) { min = arr[i]; }
		}
	}
	 cout << (N-min)*(max-N)-1<< '\n'; 
		return 0;
}