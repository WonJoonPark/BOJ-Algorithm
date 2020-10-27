#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int N;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	vector<int> inputarr(N,0);
	vector<int> resultarr(N,-1);
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		inputarr[i]=tmp;
		for (int j = i - 1; j >= 0; j--) {
			if (inputarr[j] >= tmp) { resultarr[i] = j; break; }
		}
	}
	for (int i = 0; i < N; i++) {
		cout << resultarr[i]+1 << " ";
	}
	cout << '\n';
	return 0;
}