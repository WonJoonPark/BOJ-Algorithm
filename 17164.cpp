#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string inputs;
	inputs.reserve(250001);
	cin >> n;
	cin >> inputs;
	int sindex = 0;
	int eindex = 0;
	int maxlength = 1;
	while (1) {
		if (eindex == sindex&&inputs[eindex]!='V') {
			eindex++;
		}
		if (eindex == sindex && inputs[eindex] == 'V') {
			eindex++; sindex++;
		}
		if (eindex == n) { //한번 확인하고 종료할것
			maxlength = max(maxlength, eindex - sindex);
			break;
		}
		if (inputs[eindex] == 'V') { //V가 나오는 순간 3사람을 모두 만족시킬순 없다.
			maxlength = max(maxlength, eindex - sindex);
			sindex = eindex;
			eindex = sindex + 1;
			continue;
		}

		if (inputs[eindex] != inputs[eindex - 1]&&inputs[eindex-1]!='V') { //not 색맹
			eindex++;
		}
		else { // 아름다운 보석이 아님
			maxlength = max(maxlength, eindex - sindex);
			sindex = eindex;
			eindex = sindex + 1;
		}
	}
	cout << maxlength;
	return 0;
}