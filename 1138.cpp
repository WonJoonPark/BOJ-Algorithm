#include <iostream>
using namespace std;

const int max_size = 11;
int people[max_size];
int N;
int tallernum;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tallernum;
		for (int j = 1; j <= N; j++) {
			if (tallernum == 0 && people[j] == 0) { //������ Űū����� �� ����
				people[j] = i;                      // ������ �� ������� ������ Ű��ū ����� �̹Ƿ�
				break;                              // ���� ���� �ȴ�.
			}
			else if (people[j] == 0) { //���ڸ� ---�� ������ Űū����� �� �ڸ�
				tallernum--;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << people[i] << ' ';
	}
	cout << '\n';
	return 0;
}