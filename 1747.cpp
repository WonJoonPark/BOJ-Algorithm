#include<bits/stdc++.h>
using namespace std;

bool notpri[1003002]; //�鸸�� �����鼭 �Ҽ��̸鼭 �縰���
string inputs;

bool pelin(string s) {
	int slen = s.length();
	for (int i = 0; i < slen / 2; i++) {
		if (s[i] != s[slen - 1 - i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> inputs;
	for (int i = 2; i <= 1003001; i++) { //���� ���� ����
		if (notpri[i] == true) continue; //�̹� �Ҽ� �ƴ�
		int t = 2;
		while (t * i <= 1003001) {
			notpri[t * i] = true;
			t++;
		}
		if (stoi(inputs) <= i) { //�Ҽ� �̸鼭 inputs ���� ũ�ų� ����
			if (pelin(to_string(i))) {
				cout << i; return 0;
			}
		}
	}
}
