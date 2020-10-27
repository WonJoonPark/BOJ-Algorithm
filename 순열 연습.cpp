#include<iostream>
#include<vector>
using namespace std;

//������ ��� ���� ������� (����) -- ���Ʈ����(��� ����� ��)
int N;
vector<int> cardnumarr;
int wholenum = 0;//��ü ��� ����� ���� ������ �� Ȯ���ϱ� ���ؼ�

void swap(int index1, int index2) { //��ġ �ٲپ� �ֱ�
	int tem = cardnumarr[index1];
	cardnumarr[index1] = cardnumarr[index2];
	cardnumarr[index2] = tem;
}

void brute(int sizenum) {
	if (sizenum == 1) { //��� �Լ� ��������
		for (int i = 0; i < N; i++) {
			cout << cardnumarr[i] << ' ';
		}
		wholenum++;
		cout << '\n';
	}
	for (int i = 0; i < sizenum; i++) {
		swap(i, sizenum-1); // sizenum ������ �Է¹��� ���ʹ� �ε����� (0~sizenum-1) �̹Ƿ�
		brute(sizenum - 1); // �ϳ��� ������ ���� ��ü���� �ϳ��� ��ŭ�� ���� �ϸ�ȴ�.
		swap(sizenum-1, i);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp; cardnumarr.push_back(tmp);
	}
	brute(N);
	cout << wholenum << '\n';
	return 0;
}