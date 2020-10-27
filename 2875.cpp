#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	int team = 0;
	if (N > (2 * M)) {//여학생이 남는경우
		team = M;
		K = K - (N - 2 * M);
		if (K > 0) {
			if (K % 3 == 0) { team = team - (K / 3); }
			else {
				team = team - (K / 3 + 1);
			}
		}
	}
	else if (N == (2 * M)) { //비율이 딱 맞는 경우
		team = M;
		if (K > 0) {
			if (K % 3 == 0) { team = team - (K / 3); }
			else {
				team = team - (K / 3 + 1);
			}
		}
	}
	else { //남학생이 남는경우
		team = N / 2;
		K = K - (M - N / 2);
		if (K > 0) {
			if (K % 3 == 0) { team = team - (K / 3); }
			else {
				team = team - (K / 3 + 1);
			}
		}
	}
	cout << team << '\n';
	return 0;
}