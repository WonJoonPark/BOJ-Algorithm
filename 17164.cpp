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
		if (eindex == n) { //�ѹ� Ȯ���ϰ� �����Ұ�
			maxlength = max(maxlength, eindex - sindex);
			break;
		}
		if (inputs[eindex] == 'V') { //V�� ������ ���� 3����� ��� ������ų�� ����.
			maxlength = max(maxlength, eindex - sindex);
			sindex = eindex;
			eindex = sindex + 1;
			continue;
		}

		if (inputs[eindex] != inputs[eindex - 1]&&inputs[eindex-1]!='V') { //not ����
			eindex++;
		}
		else { // �Ƹ��ٿ� ������ �ƴ�
			maxlength = max(maxlength, eindex - sindex);
			sindex = eindex;
			eindex = sindex + 1;
		}
	}
	cout << maxlength;
	return 0;
}