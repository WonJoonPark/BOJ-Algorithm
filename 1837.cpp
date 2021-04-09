#include<bits/stdc++.h>
using namespace std;
const int maxk= 1e6+1;

bool isitprime[maxk]; //false 이면 소수
string ps;
int k;
int resulti = 0;

void makeprimeset() { //소수 판별
	isitprime[0] = true; isitprime[1] = true;
	for (int i = 2; i <= k; i++) {
		if (isitprime[i] == false) { //소수이면
			int index = i;
			int tmp = 2;
			while (index * tmp <= k) { //배수는 모두 소수가 아님
				isitprime[index * tmp] = true;
				tmp++;
			}
		}
	}
}
bool bigintdivide(int p) {
	int tmpsum = 0;
	for (int i = 0; i < ps.length(); i++) {
		tmpsum = (tmpsum * 10 + (ps[i] - '0'))%p; //앞자리수 부터
	}
	if (tmpsum == 0) return true;
	else return false;
}

bool isunderk() {
	for (int i = 2; i <k; i++) {
		if (isitprime[i] == false) {
			if (bigintdivide(i)) {
				resulti = i; return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> ps >> k;

	makeprimeset(); //에라토스테네스의 채
	if (isunderk()) cout << "GOOD" << "\n";
	else cout << "BAD" << " " << resulti << "\n";


	return 0;
} 