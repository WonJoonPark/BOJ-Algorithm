#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool desc(int num1, int num2) {
	if (num1 > num2) return true;
	else return false;
}
bool asc(int num1, int num2) {
	if (num1 < num2) return true;
	else return false;
}

int main() {
	int N, K;
	int tmpnum;
	cin >> N >> K;
	vector<int> Aarr;
	vector<int> Barr;
	for (int i = 0; i < N; i++) {
		cin >> tmpnum; Aarr.push_back(tmpnum);
	}
	for (int j = 0; j < N; j++) {
		cin >> tmpnum; Barr.push_back(tmpnum);
	}
	while (K--) {
		sort(Aarr.begin(), Aarr.end(), asc);
		sort(Barr.begin(), Barr.end(), desc);
		if (Aarr[0] < Barr[0]) { //swap
			tmpnum = Aarr[0];
			Aarr[0] = Barr[0];
			Barr[0] = tmpnum;
		}
		else break;
	}
	long long resultsum = 0;
	for (int i = 0; i < N; i++) {
		resultsum += Aarr[i];
	}
	cout << resultsum << "\n";

	return 0;
}