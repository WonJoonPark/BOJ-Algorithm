#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct person {
	int weight;//������
	int height;//Ű
	int inputnum;// ���� ���� ����
	int resultcount;// ��� ���
};

bool cmp1(person a, person b) {
	if (a.weight > b.weight) {return true; }
	else if (a.weight == b.weight) {
		if (a.height < b.height) {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}
bool cmp2(person a, person b) {
	if (a.inputnum > b.inputnum) { return false; }
	else { return true; }
}

int n; //�����
vector<person> parr;
int countnum = 1;
int samejumpcount = 0; //���� ����� ������ �Ǹ� �׸�ŭ ���� �ٱ�����

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	person tmpperson;
	for (int i = 1; i <= n; i++) {
		cin >> tmpperson.weight >> tmpperson.height;
		tmpperson.inputnum = i;
		parr.push_back(tmpperson);
	}
	sort(parr.begin(), parr.end(), cmp1);
	parr[0].resultcount = countnum;
	for (int i = 1; i < parr.size(); i++) {
		if (parr[i].height <= parr[i-1].height&&parr[i].weight<parr[i-1].weight) {
			countnum++;
			parr[i].resultcount = countnum+samejumpcount;
			samejumpcount = 0; //�ʱ�ȭ
		}
		else if (parr[i].weight == parr[i - 1].weight) {
			parr[i].resultcount = countnum;
			samejumpcount++;
		}
		else { parr[i].resultcount = countnum;
		samejumpcount++;
		}
}
	sort(parr.begin(), parr.end(), cmp2);
	for (int i = 0; i < parr.size(); i++) {
		cout << parr[i].resultcount << " ";
	}
	cout << '\n';
	return 0;
}