#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int dduk[1000001];
int M;
vector<int> resultarr;

long long getlength(int H) {
	long long result = 0;
	for (int i = 0; i < N; i++) {
		if (dduk[i] - H > 0) { result += dduk[i] - H; }
	}
	return result;
}
int main() {
	cin >> N >> M;
	int maxdduk = 0;
	for (int i = 0; i < N; i++) {
		cin >> dduk[i];
		if (dduk[i] > maxdduk) { maxdduk = dduk[i]; }
	}
	int left = 0;
	int right = maxdduk;

	long long tmpresult;
	int mid = (left + right) / 2;;
	while (1) {
		tmpresult = getlength(mid);
		if (tmpresult >= M) {
			resultarr.push_back(mid);
			left = mid+1;
		}
		else {
			right = mid-1;
		}
		mid = (left + right) / 2;
		if (left>=right) break;
	}
	sort(resultarr.begin(), resultarr.end());
	cout << resultarr[resultarr.size() - 1]<<endl;

	return 0;
}