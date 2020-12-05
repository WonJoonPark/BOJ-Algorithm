#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> N;
		if (N == 0) break;
		vector<bool> numarr(N + 1);
		vector<int> prime;
		numarr[0] = false; numarr[1] = false;
		for (int i = 2; i < N + 1; i++) {
			numarr[i] = true;
		}
		for (int i = 2; i*i <=N; i++) { //소수구하기
			if (numarr[i] == true) {
				for (int j = i*i; j < N; j+=i) {
					numarr[j] = false;
				}
			}
		}
		for (int i = 3; i <= N; i++) {
			if (numarr[i] == true) prime.push_back(i);
		}
		int resultnum[2];
		for (int i = 0; i <prime.size(); i++) {
			if (numarr[prime[i]] == true && numarr[N - prime[i]] == true) {
				resultnum[1] = N - prime[i]; resultnum[0] = prime[i]; break;
				}
		}
		cout << N << " = " << resultnum[0] << " + " << resultnum[1] << "\n";
	}
	return 0;
}