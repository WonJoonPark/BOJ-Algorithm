#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int T, M, N, x, y;

int GCD(int num1, int num2) { //최대 공약수
	if (num1%num2 == 0) return num2;
	return GCD(num2, num1%num2);
}
int LCM(int num1,int num2){ //최소 공배수
	return (num1*num2) / GCD(num1, num2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;
		int resultyear = x;
		bool check = false;
		while (1) {
			if (resultyear > LCM(M, N)) { break; }
			if (((resultyear-1)% N) +1 == y) { check = true; break; }
			resultyear += M;
		}
		if (check == true) { cout << resultyear << "\n"; }
		else { cout << -1 << "\n"; }
	}
	return 0;
}