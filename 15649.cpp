#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> numarr;
int inputnums[8];

void getdata() {
	if (numarr.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << numarr[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N; i++) {
		bool check = false;
		for (int j = 0; j < numarr.size(); j++) {
			if (numarr[j] == inputnums[i]) { check = true; break; }
		}
		if (check == false) {
			numarr.push_back(inputnums[i]);
			getdata();
			numarr.pop_back();
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> inputnums[i];
	}
	sort(inputnums, inputnums + N);
	getdata();

	return 0;
}