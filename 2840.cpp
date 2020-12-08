#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, K;
void setpan(vector<char> &pan) {
	for (int i = 0; i < N; i++) {
		pan[i] = '?';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	vector<char> pan(N);
	setpan(pan);
	int index;
	for (int i = 0; i < K; i++) {
		int count; char tmpc;
		cin >> count >> tmpc;
		if (i == 0) { pan[0] = tmpc; index = 0; continue; }
		index = (count + index) % N;
		//������ �� ��������(���� �ڸ�)�� ���� �� �ִ�. �װ͸��� �ƴϸ� Ʋ�� ����
		if (pan[index] != '?'&& pan[index] != tmpc) { cout << "!"; return 0; }
		else {
			pan[index] = tmpc;
		}
	}
	//�ߺ�üũ
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if(pan[i]!='?' &&pan[i]==pan[j]) { cout << "!"; return 0; }
		}
	}
	for (int i = 0; i < N; i++) {
		cout << pan[index];
		index--;
		if (index == -1) index = N - 1;
	}
	return 0;
}