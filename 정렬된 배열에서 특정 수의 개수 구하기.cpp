#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// ���� [left_value,right_value]�� �������� ������ ��ȯ�ϴ� �Լ�
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