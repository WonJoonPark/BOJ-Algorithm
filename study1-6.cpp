#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, W, H;
int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> W >> H;
	int cross = W * W + H * H;
	for (int i = 0; i < N; i++) {
		cin >> ll;
		if (ll*ll<=cross) {
			cout << "DA" << "\n";
			continue;
		}
		cout << "NE" << "\n";
	}


	return 0;
}