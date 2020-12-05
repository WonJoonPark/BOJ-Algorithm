#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int T;
int n;
vector<int> numarr;
vector<int> narr;
long long resultsum;

int gcd(int n1,int n2) {
	if (n1%n2 == 0) return n2;
	return gcd(n2, n1%n2);
}
void setcase(int index) {
	if (narr.size() == 2) {
		resultsum += gcd(narr[0], narr[1]); return; }
	for (int i = index; i < n; i++) {
		narr.push_back(numarr[i]);
		setcase(i+1);
		narr.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tmp;
	cin >> T;
	while (T--) {
		narr.clear();
		numarr.clear(); resultsum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp; numarr.push_back(tmp);
		}
		setcase(0);
		cout << resultsum << "\n";
	}
	return 0;
}