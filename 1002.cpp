#include<iostream>
#include<vector>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int count=0;
		int x1, y1;
		int x2, y2;
		int r1, r2;
		int distance;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x2 > x1) { swap(x1, x2); }
		if (y2 > y1) { swap(y1, y2); }
		if (r2 > r1) { swap(r1, r2); }
		int squar = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		if (squar == (r1 + r2)*(r1 + r2)) {
			// �������� ������ ���(����)
			count = 1;
	}
		else if (squar < (r1 + r2)*(r1 + r2)&& squar > (r1 - r2)*(r1 - r2)) {
			//�������� ������ ���
			count = 2;
		}
		else if (squar > (r1 + r2)*(r1 + r2) && squar > (r1 - r2)*(r1 - r2)) {
			//�ȸ����� ���
			count = 0;
		}
		else if (squar == (r1 - r2)*(r1 - r2)) {
			//����
			if (r1 == r2) { //������ ��ġ�� ���
				count = -1; }
			else { count = 1; }
		}
		else if (squar < (r1 - r2)*(r1 - r2)) {
			count == 0;
		}
		cout << count << endl;
	}
	return 0;
}