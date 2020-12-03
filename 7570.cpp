#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N;
int numarr[1000001];
int maxlistcount;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp; 
		numarr[tmp] = numarr[tmp - 1] + 1;
		maxlistcount = max(maxlistcount, numarr[tmp]);
	}
	cout << N - maxlistcount << "\n";
	return 0;
}