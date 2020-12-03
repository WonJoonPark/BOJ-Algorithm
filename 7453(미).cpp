#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXIMUM = 4000;

int N;
int inputarr[4][MAXIMUM];
vector<int> sumarr;
int resultcount;

void inputs() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inputarr[0][i] >> inputarr[1][i] >> inputarr[2][i] >> inputarr[3][i];
	}
}
void fisesum() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = inputarr[0][i] + inputarr[1][j];
			sumarr.push_back(tmp); //1,2 ��° �迭�� ���� �����س���
		}
	}
	sort(sumarr.begin(), sumarr.end());
}
void getcount() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmpsum = inputarr[2][i] + inputarr[3][j];
			int lo = lower_bound(sumarr.begin(), sumarr.end(), -tmpsum)-sumarr.begin();// ���۵Ǵ� index (������)
			int hi = upper_bound(sumarr.begin(), sumarr.end(), -tmpsum)-sumarr.begin(); // �� index
			if (-tmpsum==sumarr[lo]) {
				resultcount += (hi - lo);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	inputs();
	fisesum();
	getcount();
	cout << resultcount << "\n";
	return 0;
}