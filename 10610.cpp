#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string intarr;
	cin >> intarr;
	long long sum = 0;
	bool checkzero = false;
	for (int i = 0; i < intarr.size(); i++)
	{
	sum += (intarr[i] - '0');
	if ((intarr[i] - '0')==0) { checkzero = true; } //0�� �ִ��� üũ(�ϳ��� �־����)
	}

	if (sum % 3!=0 || checkzero==false) {	cout << -1 << "\n";} //�ڸ����� ���� 3�ǹ��
	else{
		sort(intarr.begin(), intarr.end(), greater<char> ());
		cout << intarr << '\n';}
	return 0;
}