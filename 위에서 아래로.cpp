#include<iostream>
#include<algorithm>
using namespace std;

void swap(int* num1, int* num2) {
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

int main() {
	int numarr[501];
	int N;
	cin >> N;
	int tmpi;
	for (int i = 0; i < N; i++) {
		cin >> numarr[i];
		tmpi = i;
		for (int j = tmpi-1; j >= 0; j--) {
			if (numarr[tmpi] <= numarr[j]) { break; }
			else { swap(numarr[tmpi], numarr[j]);
			tmpi = j;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout<< numarr[i] << "\n";
}
	return 0;
}