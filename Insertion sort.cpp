#include<iostream>
#include<vector>
using namespace std;

vector<int> Tosortarr;
int shiftVacRec(int n,int c) {
	int return_new_location;
	if (n == 0) { return_new_location = n; }// �񱳸� �ϴٰ� ù��° index���� �°ܿ� �� �ڸ��� �� ���ο��ڸ�
	else if (Tosortarr[n - 1] < Tosortarr[n]) {
		return_new_location = n; //�ջ���� ������ ������� --> ���Ⱑ ���� �� �ڸ�
	}
	else {
		Tosortarr[n] = Tosortarr[n - 1];  // //������ ū����� ���� ����ġ�� �ű�
		Tosortarr[n - 1] = c;
		return_new_location = shiftVacRec( n - 1,Tosortarr[n-1]); //�׸��� ��������� �ٽ� �� �ջ���� ��
	}
	return return_new_location;
}

void Insertion_sort( int n){
	for (int i = 0; i < n; i++) {
		int currentnum = Tosortarr[i];
		int newlocation;
		newlocation = shiftVacRec(i,currentnum);
		Tosortarr[newlocation] = currentnum; //���� �� �ڸ��� ã���� !
	}
	return;
}

int main() {
	int tmp;

	while (cin >> tmp) {
		Tosortarr.push_back(tmp);
	}
	Insertion_sort(Tosortarr.size());
	for (int i = 0; i < Tosortarr.size(); i++) {
		cout << Tosortarr[i] << " ";
	}
	cout << "\n";
	return 0;
}