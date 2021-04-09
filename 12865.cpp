#include<bits/stdc++.h>
using namespace std;

int N, K;// 물품의 수, 버틸수 있는 무게
pair<int, int> narr[101]; //무게,가치
int dpV[100001]; //버티는 무게당 최대가치

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> narr[i].first>>narr[i].second;
	}
	sort(narr+1, narr+(N+1));
	for (int i = 1; i <= N; i++) {

		//** 여기 중요 실수가능 반드시 뒤에서 부터 봐야됨
		for (int j = K; j >= narr[i].first; j--) { //넣을래 말래
				dpV[j] = max(dpV[j], dpV[j - narr[i].first] + narr[i].second);
		}
	}
	cout << dpV[K];

	return 0;
}