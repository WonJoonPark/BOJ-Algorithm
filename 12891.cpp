#include<bits/stdc++.h>
using namespace std;

int slen, plen;
string inputs;
int sindex, eindex;
int ACGTcount[26]; //A~Z
int ac, cc, gc, tc;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> slen >> plen;
	cin >> inputs;
	cin >> ac >> cc >> gc >> tc;
	sindex = 0; eindex = plen - 1;
	for (int i = sindex; i <= eindex; i++) { //ù ���ڿ� �ʱ�ȭ
		ACGTcount[inputs[i] - 'A']++;
	}
	int resultcount = 0;
	while (eindex<=slen-1) {
		bool suc = false;
		if (ACGTcount['A' - 'A'] >= ac && ACGTcount['C' - 'A'] >= cc && ACGTcount['G' - 'A'] >= gc && ACGTcount['T' - 'A'] >= tc) resultcount++;
		ACGTcount[inputs[sindex] - 'A']--; // ���� �ϳ� ��
		sindex++;
		eindex++;
		ACGTcount[inputs[eindex] - 'A']++; // ���ڿ� �ϳ� ���� (��ĭ�̵�)
	}
	cout << resultcount;
	return 0;
}