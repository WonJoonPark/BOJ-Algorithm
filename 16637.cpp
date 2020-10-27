#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int N;
string inputs;
vector<long long> maxresult;
long long tmpnum;

long long cal(long long num1, long long num2, char c) {
	if (c == '+') { return num1 + num2; }
	else if (c == '-') { return num1 - num2; }
	else {
		return num1 * num2;
	}
}
void dfs(int index, long long nowvalue) {
	if (index >= N - 1) {
		maxresult.push_back(nowvalue);
		return;
	}
	tmpnum = cal(nowvalue, inputs[index + 2] - '0', inputs[index + 1]);
	dfs(index + 2, tmpnum);
	if (index + 4 <= N - 1) {
		long long first = cal(inputs[index + 2] - '0', inputs[index + 4] - '0', inputs[index + 3]);
		tmpnum = cal(nowvalue, first, inputs[index + 1]);
		dfs(index + 4, tmpnum);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> inputs;
	if (N == 1) { cout << inputs[0] - '0' << "\n"; return 0; }
	dfs(0, inputs[0] - '0');
	sort(maxresult.begin(), maxresult.end());
	cout << maxresult[maxresult.size() - 1] << "\n";
	return 0;
}