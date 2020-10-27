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
			if (tallernum == 0 && people[j] == 0) { //나보다 키큰사람은 다 섰고
				people[j] = i;                      // 앞으로 올 사람들은 나보다 키가큰 사람들 이므로
				break;                              // 내가 서면 된다.
			}
			else if (people[j] == 0) { //빈자리 ---즉 나보다 키큰사람이 설 자리
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