#include<iostream>
#include<vector>
using namespace std;

vector<int> Tosortarr;
int shiftVacRec(int n,int c) {
	int return_new_location;
	if (n == 0) { return_new_location = n; }// 비교를 하다가 첫번째 index까지 온겨우 그 자리가 들어갈 새로운자리
	else if (Tosortarr[n - 1] < Tosortarr[n]) {
		return_new_location = n; //앞사람이 나보다 작은사람 --> 여기가 내가 들어갈 자리
	}
	else {
		Tosortarr[n] = Tosortarr[n - 1];  // //나보다 큰사람을 현재 내위치로 옮김
		Tosortarr[n - 1] = c;
		return_new_location = shiftVacRec( n - 1,Tosortarr[n-1]); //그리고 재귀적으로 다시 그 앞사람과 비교
	}
	return return_new_location;
}

void Insertion_sort( int n){
	for (int i = 0; i < n; i++) {
		int currentnum = Tosortarr[i];
		int newlocation;
		newlocation = shiftVacRec(i,currentnum);
		Tosortarr[newlocation] = currentnum; //새로 들어갈 자리를 찾았음 !
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