#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int L;
	cin >> L;
	string s;
	cin >> s;
	long long  mul = 1;
	long long result = 0;
	for (int i = 0; i < L; i++) {
		result =(result+((s[i]-'a'+1)*mul))%1234567891;
		mul = (mul * 31) % 1234567891;
	}
	cout << result<< "\n";
	return 0;
}