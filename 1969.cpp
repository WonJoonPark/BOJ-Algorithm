#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string DNAarr[1001];
vector<char> hamDNA;
int hmdistancesum;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> DNAarr[i];
	}

	for (int i = 0; i < M; i++) {
		int tmpACGT[4] = { 0,0,0,0 };
		for (int j = 0; j < N; j++) {
			if (DNAarr[j][i] == 'A') { tmpACGT[0]++; }
			else if (DNAarr[j][i] == 'C') { tmpACGT[1]++; }
			else if (DNAarr[j][i] == 'G') { tmpACGT[2]++; }
			else if (DNAarr[j][i] == 'T') { tmpACGT[3]++; }
		}
		int MAX_DNA = 0;
		for (int k = 1; k < 4; k++) { //ACGT�� �� �ڸ� ���ڿ� � ���ڰ� ���帹�� �ߺ��Ǿ�����
			if (tmpACGT[MAX_DNA] < tmpACGT[k]) {
				MAX_DNA = k;
			}
		}
		hmdistancesum += N - tmpACGT[MAX_DNA];
		//���� �ߺ��� ���ڸ� �־��ش�(�عֵ��Ͻ��� �ּҰ� �ǵ��� �ϱ� ����)
		if (MAX_DNA == 0) {
			hamDNA.push_back('A');
		}
		else if (MAX_DNA == 1) {
			hamDNA.push_back('C');
		}
		else if (MAX_DNA == 2) {
			hamDNA.push_back('G');
		}
		else if (MAX_DNA == 3) {
			hamDNA.push_back('T');
		}
	}
	for (int i = 0; i < M; i++) { // ���� �������� DNA�� ã�����Ƿ� ���
		cout << hamDNA[i];
	}
	cout << '\n';
	cout << hmdistancesum << '\n';
	return 0;
}
