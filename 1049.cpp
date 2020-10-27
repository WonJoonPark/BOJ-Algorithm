#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int setprice, oneprice;
	int min_setprice = 1001;
	int min_oneprice = 1001;
	for (int i = 0; i < M; i++) {
		cin >> setprice >> oneprice;
		if (min_setprice > setprice) { min_setprice = setprice; }
		if (min_oneprice > oneprice) { min_oneprice = oneprice; }
	}
	int result = 0;
	if (N < 6) { //6개 이하일 때
		result = min(min_setprice, min_oneprice*N);
	}
	else {
		if (N % 6 == 0) {
			result = min(min_setprice*(N / 6), min_oneprice*N);
		}
		else {
			result = min(min_setprice*(N / 6) + min_oneprice * (N % 6), min_oneprice*N);
			result = min(result, min_setprice*(N / 6 + 1));
		}
	}
	cout << result << endl;
	return 0;
}