#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> input(N,0);
	int max = 0;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end(), greater<int> ());//�������� ����
	for (int i = 1; i <= N; i++) {
		tmp = input[i-1]*i; // ���� �������� ���� *i
		if (tmp > max) {
			max = tmp;
		}
	}
	cout << max << '\n';
	return 0;
}