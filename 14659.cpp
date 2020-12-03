#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int N;
int mountain[30001];
int killcount[30001];
bool live[30001];

bool compare(int a, int b) {
	if (a > b) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> mountain[i];
		for (int j = 0; j < i;j++) {
			if (live[j] == false) {
				if (mountain[j] > mountain[i]) {
					killcount[j]++;
				}
				else { live[j] = true; }
			}
		}
	}
	sort(killcount, killcount + N,compare);
	cout << killcount[0] << "\n";
	return 0;
}