#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// 값이 [left_value,right_value]인 데이터의 개수를 반환하는 함수
int countByRange(vector<int>& v, int leftvalue, int rightvalue) {
	vector<int>::iterator rightindex = upper_bound(v.begin(), v.end(), rightvalue);
	vector<int>::iterator leftindex = lower_bound(v.begin(), v.end(), leftvalue);
	return rightindex - leftindex;
}

int main() {
	int n,x1,x2;
	cin >> n >> x1>>x2;
	vector<int> numarr(n);
	for (int i = 0; i < n; i++) {
		cin >> numarr[i];
	}
	vector<int>::iterator rightindex = upper_bound(numarr.begin(), numarr.end(), x1);
	vector<int>::iterator leftindex = lower_bound(numarr.begin(), numarr.end(), x2);
	cout << rightindex-leftindex;

	return 0;
}