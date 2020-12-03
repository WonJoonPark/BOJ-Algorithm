#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

double R;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R;
	cout << fixed;
	double pi =atan(1)*4;
	cout.precision(6);
	cout << (powl(R,2) * pi)<<"\n";
	cout << (powl(R,2) * 2) << "\n";

	return 0;
}