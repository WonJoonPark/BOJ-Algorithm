#include<bits/stdc++.h>
using namespace std;
const int maxk= 1e6+1;

bool isitprime[maxk]; //false �̸� �Ҽ�
string ps;
int k;
int resulti = 0;

void makeprimeset() { //�Ҽ� �Ǻ�
	isitprime[0] = true; isitprime[1] = true;
	for (int i = 2; i <= k; i++) {
		if (isitprime[i] == false) { //�Ҽ��̸�
			int index = i;
			int tmp = 2;
			while (index * tmp <= k) { //����� ��� �Ҽ��� �ƴ�
				isitprime[index * tmp] = true;
				tmp++;
			}
		}
	}
}
bool bigintdivide(int p) {
	int tmpsum = 0;
	for (int i = 0; i < ps.length(); i++) {
		tmpsum = (tmpsum * 10 + (ps[i] - '0'))%p; //���ڸ��� ����
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

	makeprimeset(); //�����佺�׳׽��� ä
	if (isunderk()) cout << "GOOD" << "\n";
	else cout << "BAD" << " " << resulti << "\n";


	return 0;
} 