#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n;

int main() {
	cin >> n;
	int count = 0; //3���� (0~59 ��)
	for (int i = 0; i < 60; i++) {
		if (i / 10 == 3) { count++; continue; }
		if (i % 10 == 3) { count++; continue; }
	}
	int sum = 0;
	if (n >= 3) {
		sum += 60 * 60; //�ð� 3 �� ���
		sum += n * ((2 * count * 60) - (count*count)); //�� or ��
	}
	else {
		sum += (n + 1)*((2 * count * 60) - (count*count));
	}
	cout << sum << endl;
	return 0;
}