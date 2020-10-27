#include<iostream>
using namespace std;

int min(int a, int b) {
	if (a > b) { return b; }
	else return a;
}
int main() {
	int ts; //�׽�Ʈ���̽�
	cin >> ts;
	while (ts--) {
		int usingprice[4]; // 1�ϱ�,1������,3������,12������
		int usingdays[13]; // ����ϼ�(�Է�)
		int minmonthprice[13]; // �ΰ� �Ѵ��� �̿��ϴ� ���
		int resultprice[13]; // ��ȭ���� ���ϸ鼭 ������ ��� ����
		for (int i = 0; i < 13; i++) {
			minmonthprice[i] = 0;
			resultprice[i] = 0;
		}
		for (int i = 0; i < 4; i++) {
			cin >> usingprice[i];
		}
		for (int i = 1; i <= 12; i++) {
				cin >> usingdays[i];
		}
		for (int i = 1; i <= 12; i++) {
			minmonthprice[i] = min(usingdays[i] * usingprice[0], usingprice[1]);
		}
		for (int i = 1; i <= 12; i++) {
			resultprice[i] = resultprice[i - 1] + minmonthprice[i];
			if (i >= 3) {
				if (resultprice[i - 3] + usingprice[2] < resultprice[i])
					resultprice[i] = resultprice[i - 3] + usingprice[2];
			}
		}
		if (resultprice[12] > usingprice[3]) {
			resultprice[12] = usingprice[3];
		}
		cout << resultprice[12] << '\n';
	}
	return 0;
}