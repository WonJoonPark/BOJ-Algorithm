#include<iostream>
#include<vector>
using namespace std;

//모든 가능한 경우의 수를 출력하자
int card[7] = { 1,2,3,4,5,6,7 };
int callcnt;
void swap(int index1, int index2) {
	int tmp = card[index1];
	card[index1] = card[index2];
	card[index2] = tmp;
}
void permutation(int size) {
	if (size == 1) {
		for (int i = 0; i < 7; i++) {
			cout << card[i] << ' ';
		}
		cout << '\n';
		callcnt++;
		return;
	}
	for (int i = 0; i < size; i++) {
		swap(i, size - 1);
		permutation(size - 1);
		swap(i, size - 1);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	permutation(7);
	cout << callcnt << '\n';

	return 0;
}