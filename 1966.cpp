#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int ts;
struct queuedata {
	int importance;
	int document;
};
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int dnum;
	int wantresult;
	int count;
	int tmpimportance;
	cin >> ts;
	while (ts--) {
		queue<queuedata> dataarr;
		vector<int> imparr;
		queuedata tmpd;
		count = 1;
		cin >> dnum >> wantresult;
		for (int i = 1; i <= dnum; i++) {
			tmpd.document = i;
			cin >> tmpd.importance;
			imparr.push_back(tmpd.importance); // �߿䵵 ��������
			dataarr.push(tmpd);
		}
		sort(imparr.begin(), imparr.end(),greater<int>() ); //�߿䵵�� ������������ ���� �Ǿ� �ִ� ����
		int n = 0;
		while (1) {
			tmpd = dataarr.front();
			if (tmpd.importance == imparr[n]) { // ���õǾ����Ƿ� �� �߿䵵�� �ڿ� �ڽź��� �� ���� ������ ���� ���
				dataarr.pop();
				n++;
				if (tmpd.document == wantresult+1) {
					cout << count << '\n';
					break ;
				}
				count++; //���°�� ��µǴ����� �˾ƾ� �ϹǷ�
			}
			else {//�ڿ� �� ���� ������ ������� �ǵڷ� ����.
				dataarr.pop();
				dataarr.push(tmpd);
			}
		}
	}
	return 0;
}