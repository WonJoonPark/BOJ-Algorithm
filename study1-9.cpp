#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
//4,000,000,000,000 �� ����� �ִ�?

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	long long resultsum=0;
	for (long long i = 1; i < N; i++) { //int �� �ȵ�
		resultsum += (N + 1)*i;
	}
	cout << resultsum;
	return 0;
}