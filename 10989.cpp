#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int arr[10001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int num;
	while (N--)
	{
		cin >> num;
		arr[num]++;
	}
	for (int i = 1; i < 10001; i++) {
		if (arr[i] != 0) {
			while (1) {
				if (arr[i] == 0) { break; }
				cout << i << '\n';
				arr[i]--;
			}
		}
	}
	return 0;
}